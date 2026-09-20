#!/usr/bin/env python3
"""Arbitrary binary floating-point formats, so stimulus, golden values and the coefficient ROM
can be generated for whatever format the RTL is built with. Run with --rtl for the retargeting map,
--check for a self-test against struct. Encode/decode is round-to-nearest-even unless told otherwise.
"""

import argparse
import math
import struct


class FloatFormat:
    """A binary floating-point format: 1 sign bit, E exponent bits, M mantissa bits."""

    def __init__(self, name: str, exp_bits: int, man_bits: int, ftz: bool = True,
                 round_mode: str = "nearest"):
        self.name = name
        self.exp_bits = exp_bits
        self.man_bits = man_bits
        # "trunc" is round-toward-zero, what the GPNAE units do: fp32Adder keeps norm_man[25:3],
        # fp32Multiplier keeps raw_product[46:24]. Model the datapath with it or the reference is 1 ULP off.
        self.round_mode = round_mode
        self.width = 1 + exp_bits + man_bits
        self.bias = (1 << (exp_bits - 1)) - 1
        self.exp_all_ones = (1 << exp_bits) - 1
        self.man_mask = (1 << man_bits) - 1
        # The GPNAE FP units flush subnormals; model that unless told otherwise.
        self.ftz = ftz

    # -- properties ---------------------------------------------------------

    @property
    def hex_digits(self) -> int:
        return (self.width + 3) // 4

    @property
    def eps(self) -> float:
        """Machine epsilon: the gap between 1.0 and the next representable value."""
        return 2.0 ** -self.man_bits

    @property
    def max_normal(self) -> float:
        return (2.0 - self.eps) * (2.0 ** (self.exp_all_ones - 1 - self.bias))

    @property
    def min_normal(self) -> float:
        return 2.0 ** (1 - self.bias)

    def __repr__(self) -> str:
        return (f"{self.name}(w={self.width}, e={self.exp_bits}, m={self.man_bits}, "
                f"eps={self.eps:.3g}, {self.round_mode})")

    # -- conversion ---------------------------------------------------------

    def _round(self, v: float) -> int:
        if self.round_mode == "trunc":
            return int(math.floor(v))          # magnitudes only; toward zero
        f = math.floor(v)
        r = v - f
        if r > 0.5:
            return int(f) + 1
        if r < 0.5:
            return int(f)
        return int(f) if int(f) % 2 == 0 else int(f) + 1

    def with_rounding(self, mode: str) -> "FloatFormat":
        """A copy of this format using a different rounding mode."""
        return FloatFormat(self.name, self.exp_bits, self.man_bits, self.ftz, mode)

    def encode(self, x) -> int:
        """Float -> integer bit pattern."""
        x = float(x)
        sign = 1 if math.copysign(1.0, x) < 0 else 0
        sbit = sign << (self.width - 1)

        if math.isnan(x):
            return sbit | (self.exp_all_ones << self.man_bits) | (1 << (self.man_bits - 1))
        x = abs(x)
        if math.isinf(x):
            return sbit | (self.exp_all_ones << self.man_bits)
        if x == 0.0:
            return sbit

        m, e = math.frexp(x)          # x = m * 2**e with 0.5 <= m < 1
        m *= 2.0
        e -= 1                        # now 1 <= m < 2
        biased = e + self.bias

        if biased >= self.exp_all_ones:                 # overflow -> infinity
            return sbit | (self.exp_all_ones << self.man_bits)

        if biased <= 0:                                  # subnormal range
            if self.ftz:
                return sbit
            scale = 2.0 ** (1 - self.bias - self.man_bits)
            q = self._round(x / scale)
            if q == 0:
                return sbit
            if q > self.man_mask:                        # rounded up into normals
                return sbit | (1 << self.man_bits)
            return sbit | q

        q = self._round((m - 1.0) * (1 << self.man_bits))
        if q > self.man_mask:                            # mantissa carried out
            q = 0
            biased += 1
            if biased >= self.exp_all_ones:
                return sbit | (self.exp_all_ones << self.man_bits)
        return sbit | (biased << self.man_bits) | q

    def decode(self, bits: int) -> float:
        """Integer bit pattern -> float."""
        bits &= (1 << self.width) - 1
        sign = (bits >> (self.width - 1)) & 1
        exp = (bits >> self.man_bits) & self.exp_all_ones
        man = bits & self.man_mask

        if exp == self.exp_all_ones:
            if man:
                return float("nan")
            return float("-inf") if sign else float("inf")
        if exp == 0:
            if self.ftz or man == 0:
                v = 0.0
            else:
                v = man * 2.0 ** (1 - self.bias - self.man_bits)
        else:
            v = (1.0 + man / (1 << self.man_bits)) * 2.0 ** (exp - self.bias)
        return -v if sign else v

    def quantize(self, x) -> float:
        """Round a value to the nearest representable one in this format."""
        return self.decode(self.encode(x))

    def to_hex(self, x) -> str:
        return format(self.encode(x), f"0{self.hex_digits}x")

    def from_hex(self, h: str) -> float:
        return self.decode(int(h, 16))


# --------------------------------------------------------------------------
# Catalogue
# --------------------------------------------------------------------------
FORMATS = {
    "fp32": FloatFormat("fp32", exp_bits=8, man_bits=23),   # IEEE binary32 — the current RTL
    "fp16": FloatFormat("fp16", exp_bits=5, man_bits=10),   # IEEE binary16
    "bf16": FloatFormat("bf16", exp_bits=8, man_bits=7),    # bfloat16
    "tf32": FloatFormat("tf32", exp_bits=8, man_bits=10),   # NVIDIA TensorFloat-32
    "fp24": FloatFormat("fp24", exp_bits=8, man_bits=15),   # a middle point, for sweeps
    "fp64": FloatFormat("fp64", exp_bits=11, man_bits=52),  # IEEE binary64
}


def get_format(name: str) -> FloatFormat:
    key = name.lower()
    if key not in FORMATS:
        raise ValueError(f"unknown format {name!r}; known: {sorted(FORMATS)}")
    return FORMATS[key]


def suggested_rel_tol(fmt: FloatFormat) -> float:
    """A tolerance that scales with the format's precision."""
    return max(0.01, 8.0 * fmt.eps)


# --------------------------------------------------------------------------
# What has to change in the RTL to retarget the block
# --------------------------------------------------------------------------

def rtl_dependencies() -> str:
    return """
GPNAE format-retargeting map (from reading the RTL)

  Already format-agnostic -- carry DATA_WIDTH only, nothing to change:
    TYTAN/controller.sv        sequencing only
    TYTAN/mac.sv               wiring only
    TYTAN/Memory/ROM.v         coefficient storage
    TYTAN/Memory/RAM.v         FIFO backing store
    TYTAN/Memory/InputFIFO.v   status-bitmap FIFO
    TYTAN/Memory/PE5B.v        priority encoder

  Swap the arithmetic instance, nothing else:
    TYTAN/datapath.v           fp32Multiplier MUL, fp32Adder ADD
    SeLu.sv                    fp32_down, fp32Multiplier
    sigtan.sv                  fp32_up_down, fp32Divider

  Needs a per-format replacement module:
    fp32_down.sv               A - 1.0
    fp32_up_down.sv            A + 1.0 and A - 1.0 in parallel

  Needs parameterising, not replacing:
    gpnae.sv  LAMDA / LAMDA_ALPHA   SELU constants, format bit patterns
    gpnae.sv  tanh input doubler    hardcodes [30:23], 8'h00, 8'hFF, 8'd1;
                                    should use EXP_BITS / MAN_BITS
    gpnae.sv  current_is_positive   already generic, uses DATA_WIDTH

  Regenerate per format:
    TYTAN/Memory/taylor_coeffs.mem  1/k! coefficients, binary ($readmemb)

  The doubler is worth a note: it increments the exponent field rather than
  multiplying by two, which is exact and cheap but assumes the field position.
  Parameterising it is a two-line change once EXP_BITS/MAN_BITS exist.
"""


# --------------------------------------------------------------------------
# Self-test
# --------------------------------------------------------------------------

def self_check() -> bool:
    """Verify fp32/fp64 encode/decode against struct, and round-trips elsewhere."""
    okay = True
    f32 = FORMATS["fp32"]
    for v in (0.0, 1.0, -1.0, 0.5, 2.0, 3.14159, -2.718, 1e10, 1e-10, 1.0507009873554805):
        ref = struct.unpack(">I", struct.pack(">f", v))[0]
        got = f32.encode(v)
        if ref != got:
            print(f"  fp32 encode mismatch for {v}: struct={ref:08x} ours={got:08x}")
            okay = False
        back = f32.decode(got)
        ref_back = struct.unpack(">f", struct.pack(">I", ref))[0]
        if abs(back - ref_back) > 0:
            print(f"  fp32 decode mismatch for {v}")
            okay = False

    f64 = FORMATS["fp64"]
    for v in (1.0, -0.1, 1234.5678):
        if f64.quantize(v) != v:
            print(f"  fp64 round-trip lost {v}")
            okay = False

    for name, fmt in FORMATS.items():
        for v in (1.0, -1.0, 0.5, 100.0, -0.001):
            q = fmt.quantize(v)
            if v != 0 and abs(q - v) / abs(v) > fmt.eps:
                print(f"  {name}: quantize({v}) = {q}, error exceeds eps")
                okay = False
        if fmt.quantize(0.0) != 0.0:
            print(f"  {name}: zero did not round-trip")
            okay = False
    return okay


def main() -> None:
    p = argparse.ArgumentParser(description="Number formats for GPNAE testing")
    p.add_argument("--list", action="store_true")
    p.add_argument("--check", action="store_true")
    p.add_argument("--rtl", action="store_true", help="show the retargeting map")
    a = p.parse_args()

    if a.rtl:
        print(rtl_dependencies())
        return
    if a.check:
        print("\n  Self-test:", "PASS" if self_check() else "FAIL", "\n")
        return

    print(f"\n  {'format':<8} {'width':>6} {'exp':>5} {'man':>5} {'eps':>12} "
          f"{'max normal':>14} {'suggested tol':>14}")
    print("  " + "-" * 72)
    for name, f in FORMATS.items():
        print(f"  {name:<8} {f.width:>6} {f.exp_bits:>5} {f.man_bits:>5} "
              f"{f.eps:>12.3e} {f.max_normal:>14.4e} {suggested_rel_tol(f)*100:>13.2f}%")
    print()


if __name__ == "__main__":
    main()
