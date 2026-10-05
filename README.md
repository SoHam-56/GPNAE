# GPNAE

A neural-network activation engine in SystemVerilog: SELU, sigmoid, tanh, ReLU and linear, in fp32, bf16 or int8. GPNAE provides the activation lanes of [SIENNA](https://github.com/SoHam-56/SIENNA), and it builds and verifies on its own.

**Dependencies:** Verilator 5 · a C++20 compiler (`--timing` needs coroutines) · Python ≥ 3.10 · NumPy

---

## Architecture

GPNAE has two lanes. They share the barrel MAC and differ in what they evaluate.

### `gpnae`: the Taylor lane (TYTAN)

`src/gpnae.sv` computes e^x with a Maclaurin series on the TYTAN MAC, using Horner's rule over 1/k! from `taylor_coeffs.mem`. It then reshapes the result into the activation:
- **SELU** (`src/SeLu.sv`): λx for x > 0 and λα(e^x − 1) below, through `fp32_down`.
- **sigmoid and tanh** (`src/sigtan.sv`): e^x / (1 + e^x) and (e^2x − 1) / (e^2x + 1), through an adder and a divider.

`terms_i` sets the series degree, trading accuracy against cycles. The lane takes a 2-bit control word: `01` SELU, `10` sigmoid, `11` tanh.

### `gpnae_poly`: the fitted-polynomial lane

`src/gpnae_poly.sv` evaluates each activation as a polynomial in x directly, so there is no exponential, no divider and no per-function reshaping. Only the coefficient table differs per activation:
- **SELU:** the negative branch is fitted, and x > 0 is λx.
- **sigmoid:** fitted on |x|; negative inputs are 1 − P(|x|).
- **tanh:** fitted as tanh(√u)/√u in u = x², with the sign restored.

`fit_poly_coeffs.py` fits the tables (Chebyshev) per format and measures them as the hardware evaluates them.

Inputs past the fitted range (SELU below −4, sigmoid |x| > 3.5, tanh |x| > 4) go to `src/gpnae_tail.sv`. It computes e^a for a ≤ 0 without cancellation: halve to |z| ≤ 1, take a Taylor series of e^z − 1, then double back. From that it forms λα(e^x − 1), E(1 − E(1 − E)) with E = e^−|x|, and 1 − 2E(1 − E(1 − E)) with E = e^−2|x|. Several tail elements run at once, each with its own registers, sharing one multiplier and one adder.

The lane takes a 3-bit control word: `001` SELU, `010` sigmoid, `011` tanh, `100` ReLU, `101` linear. ReLU and linear bypass the polynomial and are exact.

### `gpnae_poly_int8`: the int8 lane

`src/gpnae_poly_int8.sv` runs the same polynomial forms in fixed point (Q4.11) on integer products:
- **In:** int8 codes are rescaled from the producer's zero point and scale: (q − z_in) · mx, rounded, shifted and saturated to Q4.11.
- **Out:** results are requantized to int8 with a multiplier, shift and output zero point, as TFLite does.

This lane has no tail unit.

### Barrel MAC

The format's multiplier and adder accept a new operation every cycle. Horner's rule, however, carries a multiply-then-add dependency within an element: 13 cycles in fp32 and 8 in bf16. Elements are independent, so `src/TYTAN/barrel_mac.sv` interleaves K of them round-robin through one datapath, in lockstep on the term index, the way a barrel processor fills its pipeline. This keeps the multiplier busy where a single element would leave it mostly idle.

### Number formats

`EXP_W` and `MAN_W` set the floating-point format of a build (fp32: 8 / 23, bf16: 8 / 7); the int8 lane is its own module. `number_formats.py` also models fp16, tf32, fp24 and fp64 for accuracy sweeps, and `number_formats.py --rtl` lists what retargeting the RTL to another format involves.

`gpnae_model.py` is a bit-exact model of `gpnae_poly`, `gpnae_tail` and `gpnae_poly_int8`, operation for operation in the lane's format. It is built on [ArithmeticLibrary](https://github.com/SoHam-56/ArithmeticLibrary)'s `fpu.py` and `ipu.py`.

---

## Performance and accuracy

All figures come from Verilator simulation of the `gpnae_poly` lane, the one SIENNA uses (seed 1).

### Floating point (10 stimulus patterns × 3 activations × 240 inputs = 7 200 element checks per run)

The patterns include sweeps, random, normal, log-uniform, negative-only, positive-only, near-zero, edge, threshold and adversarial mixes.

| Format | Activation | Cycles per input | Worst relative error vs the exact function | Mean relative error | Bound | Bit-exact vs `gpnae_model` |
|---|---|---|---|---|---|---|
| fp32 | SELU    | 18 – 20 | 0.0056% | ≤ 0.0006% | 1% | |
| fp32 | sigmoid | 16 – 39 | 0.0613% | ≤ 0.0344% | 1% | |
| fp32 | tanh    | 20 – 22 | 0.3878% | ≤ 0.2558% | 1% | |
| bf16 | SELU    | 18      | 2.82%   | ≤ 1.28%   | 6.25% | 2 400 / 2 400 |
| bf16 | sigmoid | 16 – 28 | 7.22%   | ≤ 1.20%   | 6.25% | 2 400 / 2 400 |
| bf16 | tanh    | 19      | 8.59%   | ≤ 7.17%   | 6.25% | 2 400 / 2 400 |

The bound is the regression's relative tolerance, which scales with the format's precision. It is applied together with an absolute bound of 1e−6 (`numpy.isclose` semantics).

- **fp32:** every pattern passes.
- **bf16:** every output equals `gpnae_model` bit for bit (`--model hw`). Against the exact functions, SELU is within 6.25% everywhere, but sigmoid and tanh are not. Their worst cases come from the fit at bf16's 8 significand bits: sigmoid's 1 − P near x = −3.5, and the power-basis Horner evaluation for tanh.
- **Cycles per input:** the higher counts are on the threshold pattern, whose inputs sit at the fitted ranges' edges and reach the tail unit.

### int8 (every int8 input at each of 5 quantization cases, plus 32 random and 64 positive-SELU parameter sets × 256 inputs, plus a 2 098-element protocol stream)

| Activation | Cycles per input | Bit-exact vs `gpnae_model` | Worst error vs the exact function |
|---|---|---|---|
| SELU    | 13 | 25 856 / 25 856 | 9 LSB |
| sigmoid | 14 | 25 856 / 25 856 | 7 LSB |
| tanh    | 14 | 25 856 / 25 856 | 3 LSB |
| ReLU    | 6  | 25 856 / 25 856 | exact |
| linear  | 6  | 25 856 / 25 856 | exact |

The protocol stream checks group boundaries and capture timing. It ran 11 segments and 161 groups with no reset between groups: 2 098 of 2 098 outputs exact, none missing or extra. Accuracy is reported against a bound of 6.25% relative or 1 LSB absolute:
- SELU and tanh are within it on every gated output.
- sigmoid is outside it on 34 of its gated outputs (worst 7 LSB).

---

## Simulation

`regression.py` writes `testbenches/gpnae_test_config.svh` and the stimulus for the chosen format, then builds and runs the testbench with Verilator.

```bash
python3 regression.py                                    # gpnae (Taylor) lane, fp32, every pattern
python3 regression.py --lane poly --format bf16          # the fitted lane in bf16, against the exact functions
python3 regression.py --lane poly --format bf16 --model hw   # bit for bit against gpnae_model
python3 regression.py --lane poly --format int8          # the int8 lane: bit-exact, then accuracy
python3 regression.py --test act_threshold               # one stimulus pattern
./run_regression.sh --lane poly                          # the same, with the Verilator / gcc toolchain set up first
```

| Option | Meaning |
|---|---|
| `--lane gpnae\|poly` | which lane (default `gpnae`, the Taylor lane) |
| `--format` | fp32, bf16, int8 (the floating-point formats of `number_formats.py` are accepted for sweeps) |
| `--model exact\|series\|hw` | reference: the exact functions; the finite series the Taylor lane evaluates; or `gpnae_model` bit for bit (`poly` lane) |
| `--batches`, `--per-batch` | volume per activation (default 8 × 30) |
| `--rel-tol`, `--abs-tol` | override the bounds |
| `--seed` | stimulus seed |

Results go to `testbenches/results/`: one log per pattern and a summary report. Other tools:
- `python3 gpnae_tests.py --accuracy` shows the input range each term count holds for a format.
- `make lint_fmt TOP=<module> FMT="-GEXP_W=8 -GMAN_W=7"` elaborates one block in one format.
- `make verilator`, `make iverilog` and `make vcs` run the configured testbench directly.
