# GPNAE

**A hardware activation engine for neural networks: SELU, sigmoid, tanh, ReLU and linear, in fp32, bf16 and int8.**

Neural-network accelerators are good at multiply-accumulate and slow at non-linear functions. GPNAE evaluates activation functions on the same kind of multiply-accumulate hardware, using short polynomials. It began as TYTAN, published at VDAT 2025, and is now the activation stage of the [SIENNA](https://github.com/SoHam-56/SIENNA) accelerator.

| | |
|---|---|
| **58x fewer cycles** per activation | than the published design: 747 -> 12.8 cycles for tanh (fp32) |
| **13.5 ns** per tanh in fp32 | 8.6 ns in bf16, 11.3 ns in int8, on one lane at 950 MHz |
| **within 1%** of the exact functions | in every format, on every input checked (fp32 within 0.50%) |
| **no lookup tables** | each function is a few polynomial pieces whose coefficients are data the host can rewrite |
| **35.8x smaller, 1.77x lower power** | than NVDLA's activation processor in the same 45 nm process (published TYTAN core) |

---

## The published design: TYTAN

> S. Pramanik, V. William, A. Raha, D. Das, A. Mukherjee and J. L. Paluh, "TYTAN: Taylor-series based Non-Linear Activation Engine for Deep Learning Accelerators," VDAT 2025, Springer. [Book](https://link.springer.com/book/9783032263049) · [arXiv:2512.23062](https://arxiv.org/abs/2512.23062)

**Code as published:** tag [`tytan_vdat2025`](https://github.com/SoHam-56/GPNAE/tree/tytan_vdat2025).

TYTAN computes e^x as a Taylor series on a modified multiply-accumulate unit (Horner's rule), then reshapes it:
- **SELU:** λα(e^x − 1);
- **sigmoid:** e^x / (e^x + 1);
- **tanh:** (e^2x − 1) / (e^2x + 1).

A software search picks how many Taylor terms each activation layer needs to stay within an accuracy budget, so accuracy and cost trade off per layer. The paper maps Swish, GELU and Softplus onto the same engine. The published RTL implements SELU, sigmoid and tanh in fp32.

Synthesized with Synopsys Design Compiler in FreePDK45, as published:

| Design | Process | Area (mm²) | Power (mW) | Max clock (MHz) |
|---|---|---|---|---|
| **TYTAN** | FreePDK45 | 0.028 (core), 0.037 (with SELU, sigmoid, tanh) | 19.86 (core), 24.37 (with them) | **950** |
| NVIDIA NVDLA | FreePDK45 | 1.002 | 35.165 | 450 |
| NN-LUT | 7 nm | 0.001 | 0.059 | not reported |
| UNO | TSMC 45 nm | 0.283 (kernel) | 66.5 (64 PEs) | 400 |
| ViTALiTy | 28 nm CMOS | 5.22 | 1 460 | 500 |

Source: Table 3 of the paper. Against NVDLA's single-data-point processor in the same process, the TYTAN core is 35.8× smaller, uses 1.77× less power and runs at 2.11× the clock (27.1× smaller and 1.44× less power with the SELU, sigmoid and tanh add-ons). The paper measured 747 cycles per tanh output with 30 Taylor terms.

---

## What changed since

The published engine computed one input at a time. Today's lane is built for throughput:

![GPNAE lane](docs/gpnae_lane.svg)

1. **A short polynomial per function, and a constant past it.** The published design built every function from e^x, which needed up to 30 series terms and, for sigmoid and tanh, a division. Today each function has its own short polynomial, fitted to that function alone, so only multiplies and adds are left. Past the point where the true value is within the tolerance of its limit (tanh at 3, SELU and sigmoid at 6 in fp32), the lane outputs the limit itself, so the far inputs cost no polynomial at all.
2. **Many inputs share one multiply-add unit.** A polynomial is evaluated as a chain (Horner's rule) in which each step waits for the previous one, so the published design kept its multiplier busy only about 6% of the time. The new unit works on 16 inputs in turn, like a barrel processor, so it starts a new step every cycle. Each input brings its own coefficient set and degree, so inputs in different pieces of a function share the unit at full rate.
3. **Coefficients are data, in three accuracy tiers.** The coefficients, the piece boundaries and each set's degree live in a 128-word memory the host can rewrite; its reset contents are the fitted sets. A write lands only while the lane holds no element (idle_o); one sent while it works is refused, so a running group never reads a half-written set. Each function has three sets: within 1%, 5% and 10% of the exact value. A layer that tolerates 10% picks tier 2 and runs fewer multiply-add rounds.
4. **Three number formats from one source.** One define picks fp32, bf16 or int8, and the same lane elaborates only that format's arithmetic. bf16 fits several low-degree pieces per function, because one polynomial in 8 significant bits cannot reach 1%; for sigmoid below -1.5 it computes e^-|x| as 2^-n P(f) in fp32 on a small side unit. fp32 does the same range reduction on the main multiply-add unit. int8 takes quantized inputs, rescales and centres them on the polynomial's range, and returns quantized outputs.
5. **Verification against the true function.** Every output the RTL produces in the regression is compared with numpy float64: within the tier's tolerance or one output step. A bit-exact Python model of the hardware is the diagnostic, and planted faults show that every new check can fail.

---

## Performance

> Measured in cycle-accurate Verilator simulation. Times assume a **950 MHz** clock, the frequency the published design reached. Synthesis of today's lane is planned.

**Cycles per input on one lane** at the 1% tier, streamed (6400 inputs, the lane never idle), from `make regression`'s cycles points; the far column is x = -100 (tanh 50), the published design's slowest inputs:

| Format | SELU | sigmoid | tanh |
|---|---|---|---|
| fp32 | 12.8 cycles · 13.5 ns | 13.8 (normal inputs) to 15.1 (uniform on [-8, 8]) · 14.5 to 15.9 ns; far 12.5 | 12.8 · 13.5 ns |
| bf16 | 8.2 · 8.6 ns | 11.8 to 14.6 · 12.5 to 15.3 ns; far 26.6 · 28 ns (the fp32 side unit) | 8.2 · 8.6 ns |
| int8 | 9.8 · 10.3 ns | 10.8 · 11.3 ns | 10.8 · 11.3 ns |

The 5% and 10% tiers take 7 to 10.5 cycles per input in every format (bf16 sigmoid's far inputs 14 to 19, on the side unit). ReLU and linear bypass the polynomial.

**Accuracy against the exact functions**, worst relative error over every input the regression gives each lane, at each tier:

| Format | Inputs per function | Tier | SELU | sigmoid | tanh |
|---|---|---|---|---|---|
| fp32 | 1 311 424 (a grid over [-16, 16], random bit patterns, random reals up to ±110, every power of two, each piece boundary's neighbours) | 1% | 0.25% | 0.25% | 0.50% |
| | | 5% | 3.2% | 3.0% | 3.5% |
| | | 10% | 5.2% | 5.6% | 8.1% |
| bf16 | every finite input (65 280) | 1% | 0.94% | 0.77% | 0.96% |
| | | 5% | 4.5% | 3.0% | 4.7% |
| | | 10% | 8.8% | 9.2% | 7.9% |
| int8 | every input code of 355 quantization parameter sets (90 880) | 1% | 0.69% | within one output step | within one output step |
| | | 5% | 4.1% | within one output step | 3.7% |
| | | 10% | 7.7% | within one output step | 4.9% |

An int8 output passes when it is within max(tolerance x |t|, one output step) of t, the exact value clamped to the output range; the int8 figures are the worst among outputs more than one step from t. int8 sigmoid needs its full degree at every tier, because its output step (1/256) is finer than 5%.

Inputs the fit never saw give the same picture: fp32 on 1.3 M fresh random words is within 0.25%, 0.25% and 0.50%, and int8 on 256 held-out parameter sets (every zero point, scales from 2^-20 to 15.99) within 0.68% for SELU and one output step for sigmoid and tanh (make regression's held-out points).

### Compared with other activation hardware

| Design | Method | Precision | Cycles per output |
|---|---|---|---|
| **GPNAE today** | fitted polynomial pieces on a barrel multiply-accumulate unit | fp32 · bf16 · int8 | 12.5 to 15.1 · 8.2 to 26.6 · 9.8 to 10.8 (one lane, 1% tier) |
| **TYTAN, as published** | Taylor series of e^x, then reshaped | fp32 | 747 (tanh, 30 terms) |
| NN-LUT [1] | 16-entry lookup table, piecewise linear | INT32, FP16, FP32 | 2 |
| UNO [2] | degree 2 to 4 Taylor series on existing MAC units | 8-bit fixed point | 3 to 5 per primitive (exp, log, divide) |
| CORDIC-based [3] | CORDIC rotations and division | 8-bit | 9 |

Lookup tables and short series take fewer cycles at reduced precision or with fewer segments. GPNAE keeps every format within 1% of the exact functions without a table.

[1] NN-LUT, DAC 2022, [arXiv:2112.02191](https://arxiv.org/abs/2112.02191) · [2] UNO, ISLPED 2021, [paper](https://jsm.ece.wisc.edu/docs/wu-islped2021.pdf) · [3] Kokane et al., "CORDIC Is All You Need", 2025, [arXiv:2503.11685](https://arxiv.org/abs/2503.11685)

---

## Getting started

You need Verilator 5 with a C++20 compiler (its `--timing` mode needs coroutines), and Python 3.10 or later with NumPy.

```bash
git clone --recursive https://github.com/SoHam-56/GPNAE.git
cd GPNAE

make regression                                     # every format: lint, the lane at each tier, protocol, load path, cycles, faults
make regression FMT=bf16                            # one format
python3 regression.py --format bf16 --run gate --tier 0   # one lane gate: every bf16 input against the true function
make fit                                            # refit every tier; writes gpnae_coef_default.json and gpnae_coef_mem.sv's reset contents
```

`regression.py` writes the stimulus, builds the testbench and judges every output against the true function. `gpnae_model.py` is the bit-exact model of the hardware, and `fit_poly_coeffs.py` fits the coefficient sets of every tier. `make regression` runs each point in a private copy of the tree and passes only on each point's own verdict; the table is `testbenches/results/regression/regression.log`.

The published Taylor lane was removed from this tree; the last commit that builds it carries the tag `gpnae_taylor_final`.

## Standalone machine

Everything here runs on any Linux machine; nothing depends on the authors' servers.

**You need:** GNU make, git, a C++ compiler with C++20 coroutines (g++ 10 or later), Verilator built with that compiler (tested: 5.035 for every regression, and the released 5.052), and Python 3 with the packages in `requirements.txt` (tested with Python 3.11).

```bash
git clone --recursive https://github.com/SoHam-56/GPNAE.git && cd GPNAE
python3 -m venv .venv && .venv/bin/pip install -r requirements.txt
make -j8 regression PYTHON=$PWD/.venv/bin/python
```

**Choosing N in `make -jN`:** the largest process of the whole regression peaked at 2.1 GB (measured: `make -j8` on an 8-core, 64 GB machine, 3 minutes 26 seconds; the fp32 gates' Python check is the largest), so `-j8` needs about 8 GB plus room for the builds. Nothing is skipped.

---

## Running with VCS

`make regression` runs on Verilator by default. `SIM=vcs` runs the same points, through the same gates, on Synopsys VCS, a 4-state simulator: it also models unknown (X) and floating (Z) bit values, which Verilator, a 2-state simulator, turns into 0 or 1.

**The authors have not run the VCS path yet** (no VCS license where it was written). The commands, gates and parsers are in place and were checked without VCS; your run is the first real one.

**You need:** `vcs` on your `PATH` with a working license, the C++ compiler VCS uses, GNU make, and Python 3 with `pip install -r requirements.txt`.

**Run it:**

```bash
make -j8 regression SIM=vcs
```

**Read the table** (also written to `testbenches/results/regression/regression.log`). Each row is one check: its name, its verdict, its time and its log. The last line is the overall verdict, for example `GPNAE REGRESSION PASS: 36 of 36 gated points passed; 3 reported, not gated; 1 not applicable to vcs`.

| Verdict | Meaning |
|---|---|
| `PASS` | the check met the same gate as on Verilator: every output against its reference and the true function |
| `FAIL (...)` | it did not; the bracket says why, the log (path on the row) says where |
| `N/A (...)` | `check-hier`, which reads Verilator's own elaborated hierarchy: listed, never run |
| `..., reported, not gated` | a VCS lint (`+lint=all`): counted, not failing, until its warning baseline is recorded |

**If a row fails,** send back `testbenches/results/regression/regression.log` and the log of each failing row. A line such as `FAIL: X in output word 37 of test <name>` means the design produced an unknown value where a number was expected: a real finding for the authors, not a set-up problem. A license or compile failure shows as `FAIL (exit N)` with VCS's message in the log.

**Recording the lint baseline** (once, on the first clean run): `make lint SIM=vcs RECORD=1 FMT=<f>` for fp32, bf16 and int8 writes `vcs_lint_baseline.txt`; commit it, and from then on a new VCS lint warning fails its row.

**Options:** `TRACE=1` waveforms, `XPROP=1` X-propagation, `RANDINIT=1 SEED=<n>` random register power-up instead of X. Without them a VCS build is plain: no debug access and no waveform.

What maps to what:

| Verilator | VCS | Note |
|---|---|---|
| `--binary --timing --assert` | `vcs -full64 -sverilog -timescale=1ns/1ps` | VCS runs delays and assertions natively |
| `--top-module X` | `-top X` |  |
| `-I<dir>`, `+define+X`, `-DX` (also in `EXTRA_FLAGS`) | `+incdir+<dir>`, `+define+X` |  |
| `-G<name>=<value>` (sizes, `EXTRA_FLAGS`) | `-pvalue+<top>.<name>=<value>` | top-level parameters, as with `-G` |
| `--trace` (`TRACE=1`) | `-debug_access+all +define+ENABLE_TRACE` (`TRACE=1`) | without it, `+vcs+dumpvarsoff`: no waveform |
| `--x-initial unique`, `+verilator+rand+reset+2` | `+vcs+initreg+random` (compile), `+vcs+initreg+<SEED>` (run): `RANDINIT=1 SEED=<n>` | VCS's default is X power-up, stricter than Verilator's zeros |
| (none) | `-xprop=tmerge`: `XPROP=1` | X-propagation through `if` and `case` |
| `+verilator+error+limit+N` | nothing | VCS carries on after `$error` by default |
| `-j`, `--build-jobs`, `--threads`, `SIM_THREADS` | `-j<cores>` (compile) | VCS simulates on one thread |
| `OPT_FAST=-O0`, `LARGE_CODE=1`, `USE_CCACHE` | not applicable | Verilator build workarounds |
| `/* verilator lint_off ... */`, `lint_waivers.vlt` | ignored | comments to VCS; the waiver file is Verilator's |
| `--lint-only -Wall` (the lint points) | `+lint=all` (ArithmeticLibrary's Common/vcs_lint.py) | reported, not gated, until `vcs_lint_baseline.txt` is recorded |
| `check-hier` (Verilator's `--xml-only` hierarchy) | not applicable | listed as N/A |

---

## Author

Soham Pramanik · [LinkedIn](https://www.linkedin.com/in/soham-pramanik-224004271/)
