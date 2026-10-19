# GPNAE

**A hardware activation engine for neural networks: SELU, sigmoid, tanh, ReLU and linear, in fp32, bf16 and int8.**

Neural-network accelerators are good at multiply-accumulate and slow at non-linear functions. GPNAE evaluates activation functions on the same kind of multiply-accumulate hardware, using polynomials. It began as TYTAN, published at VDAT 2025, and is now the activation stage of the [SIENNA](https://github.com/SoHam-56/SIENNA) accelerator.

| | |
|---|---|
| **39× fewer cycles** per activation | than the published design: 747 → 17–19 cycles for tanh (fp32) |
| **18–20 ns** per tanh in fp32 | 12 ns in int8, on one lane at 950 MHz |
| **within 0.39%** of the exact functions | in fp32, over 1 182 960 checked inputs |
| **bit-exact** | fp32, bf16 and int8 lanes match a Python model of the hardware on every output |
| **35.8× smaller, 1.77× lower power** | than NVDLA's activation processor in the same 45 nm process (published TYTAN core) |

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

1. **A short polynomial per function.** The published design built every function from e^x, which needed up to 30 series terms and, for sigmoid and tanh, a division. Today each function has its own short polynomial, fitted to that function alone, so only multiplies and adds are left. Inputs too large for the fit go to a small side unit that handles the flat tails of the curve.
2. **Many inputs share one multiply-add unit.** A polynomial is evaluated as a chain in which each step waits for the previous one, so the published design kept its multiplier busy only about 6% of the time. The new unit works on many inputs in turn, like a barrel processor, so it starts a new operation every cycle.
3. **Three number formats.** A build parameter switches the lane's arithmetic between fp32 and bf16. A separate fixed-point int8 lane takes quantized inputs and returns quantized outputs, as integer-quantized models expect.
4. **Verification.** Bit-exact Python models of every lane, a regression with ten stimulus patterns per activation (eleven on the polynomial lane), and correctness fixes in the control logic. The published Taylor lane is still in the repository (`src/gpnae.sv`) and is checked by the same regression.

---

## Performance

> Measured in cycle-accurate Verilator simulation of the fitted-polynomial lane. Times assume a **950 MHz** clock, the frequency the published design reached. Synthesis of today's lane is planned.

Every number in this section comes from one `make regression` run on 2026-10-12 (GPNAE e82024f).

**Cycles per input on one lane,** as the testbench reports them; fp32 and bf16 over the eleven stimulus patterns, int8 over every input of its 252 parameter sets:

| Format | SELU | sigmoid | tanh | ReLU, linear |
|---|---|---|---|---|
| fp32 | 15–17 cycles · 16–18 ns | 13–36 cycles · 14–38 ns | 17–19 cycles · 18–20 ns | 3 cycles · 3 ns |
| bf16 | 15–17 cycles · 16–18 ns | 13–76 cycles · 14–80 ns | 16–19 cycles · 17–20 ns | 3 cycles · 3 ns |
| int8 | 10 cycles · 11 ns | 11 cycles · 12 ns | 11 cycles · 12 ns | 3 cycles · 3 ns |

The upper end of each range comes from inputs at the edges of the fitted range, which take the tail unit. In bf16 every negative sigmoid input takes it too (below), so all-negative inputs cost about 6x the positive ones (76 against 13 cycles).

**Accuracy against the exact functions:** the worst relative error of the RTL's words against numpy float64 (`truth.py`, the regression's gate), over every input each lane point runs:

| Format | Inputs | SELU | sigmoid | tanh |
|---|---|---|---|---|
| fp32 | 1 182 960 (a grid over [-16, 16], 2^20 random, the range edges) | 0.006% | 0.073% | 0.39% |
| bf16 | every finite input, and the eleven patterns (67 920) | 2.5% | 0.77% | 8.5% |
| int8 | every input of 252 parameter sets (about 65 000) | 7.8% (10 steps) | 6.0% (2 steps) | 7.3% (3 steps) |

The gate's bound is 10% (a waiver; 1% is the target): no output in any format exceeds it. In int8 an output passes when it is within max(10% |t|, one output step) of t, the exact value clamped to the output range (the decimal rule), so the int8 figures are the worst among outputs more than one step from t, with the worst distance in steps (measured: rs2_g6bf_i1_gpreg2).

- **fp32** is within 1% everywhere.
- **bf16** carries only 8 significant bits. Its sigmoid sends every x < 0 to the tail unit, which runs in fp32 with two Newton steps for 1/(1 + e^-|x|) and rounds the result to nearest bf16, because 1 - P in 8 bits cannot reach 1% there; over every finite bf16 input it is within 0.772% (at x = 0.0156). tanh's worst, 8.5%, is at |x| = 3.84, just below the tail's start at 4.
- **tanh at tiny |x|** returns x wherever tanh(x) rounds to x in the format (|x| below 3.5211e-4 in fp32, 0.0903 in bf16), so small inputs no longer read about 7% low in bf16 or flush to zero just above 2^-126.
- **SELU, the basis of its figures.** SELU's error is measured against λx for x ≥ 0 and λα(e^x - 1) below. In bf16, λ is stored as 0x3F87 (1.0547, rounded up), because the multiplier truncates: every x ≥ 0 is then within 0.38%. Where λx lies above the format's maximum the gate accepts the maximum or +Inf; at 0x7F73, whose λx rounds to the finite maximum, the lane now gives +Inf (0x7F7E, below the maximum, before). In int8 the lane multiplies the exact rescale product (q - z_in) · mx, a block-floating x, by λ or by the fitted P(x) ≈ SELU(x)/x, so any input scale works and λx is exact past 512. Its SELU figure covers input scales from 1e-7 to 15.99, calibrated and uncalibrated output scales, and output scales far below the input's. P is fitted for relative error (worst 4.16%), so int8 SELU does not reach the 1% target; that would need a third degree, one more multiply-add round.
- **int8 sigmoid past |x| = 2.5** is exact: there the curve is so flat that each output code covers a wide band of inputs, so instead of the polynomial the lane counts how many of 19 fixed thresholds |x| has passed and that count gives the output code. The thresholds come from sigmoid itself, the comparison costs no cycle, and all 65 536 possible lane inputs (16-bit fixed point) are within GPNAE's int8 tolerance, max(6.25% |t|, one step) (3 370 were outside before, from the polynomial's saturation below x = -3.5).
- The fp32, bf16 and int8 lanes match their bit-exact models on every output.

### Compared with other activation hardware

| Design | Method | Precision | Cycles per output |
|---|---|---|---|
| **GPNAE today** | fitted polynomial on a barrel multiply-accumulate unit | fp32 · bf16 · int8 | 13–36 · 13–76 · 10–11 (one lane) |
| **TYTAN, as published** | Taylor series of e^x, then reshaped | fp32 | 747 (tanh, 30 terms) |
| NN-LUT [1] | 16-entry lookup table, piecewise linear | INT32, FP16, FP32 | 2 |
| UNO [2] | degree 2–4 Taylor series on existing MAC units | 8-bit fixed point | 3–5 per primitive (exp, log, divide) |
| CORDIC-based [3] | CORDIC rotations and division | 8-bit | 9 |

Lookup tables and short series take fewer cycles at reduced precision or with fewer segments. GPNAE keeps fp32 results within 0.39% of the exact functions, and it also has bf16 and int8 versions.

[1] NN-LUT, DAC 2022, [arXiv:2112.02191](https://arxiv.org/abs/2112.02191) · [2] UNO, ISLPED 2021, [paper](https://jsm.ece.wisc.edu/docs/wu-islped2021.pdf) · [3] Kokane et al., "CORDIC Is All You Need", 2025, [arXiv:2503.11685](https://arxiv.org/abs/2503.11685)

---

## Getting started

You need Verilator 5 with a C++20 compiler (its `--timing` mode needs coroutines), and Python ≥ 3.10 with NumPy.

```bash
git clone --recursive https://github.com/SoHam-56/GPNAE.git
cd GPNAE

make regression                                          # today's lane in fp32, bf16 and int8, then one table (FMT=bf16: one format)
python3 regression.py                                    # the published Taylor lane, fp32
python3 regression.py --lane poly --format bf16          # today's lane, against the exact functions
python3 regression.py --lane poly --format bf16 --model hw   # bit for bit against the hardware model (fp32 too)
python3 regression.py --lane poly --format int8          # the int8 lane
```

`regression.py` generates the stimulus, builds the testbench and checks every output. `gpnae_model.py` is the bit-exact model of the hardware, and `fit_poly_coeffs.py` fits the coefficient tables. Results go to `testbenches/results/`.

`make regression` runs the model checks (`check_gpnae_model_fp32.py`, `check_gpnae_model_bf16.py`, `check_gpnae_model_int8.py`), the published Taylor lane in fp32 (`fp32/taylor`: `python3 regression.py` as it is) and each format's lane as points of their own (`make regression/bf16/lane`; `make -j4` runs four at once), each in a private copy of the tree, and passes only on each point's own verdict.

- **The gate is the true function.** Every lane point judges the RTL's own words (`+dump_got`) against numpy float64 through ArithmeticLibrary's `truth.py`: relative error at most 10% (a waiver; 1% is the target, and every run prints the count over 1%), or output and true value both at most 2^-126 in bf16 and fp32, or within 1 output LSB in int8. A miss prints `ACCURACY: FAIL` and fails the point.
- **Coverage.** `bf16/lane` runs every finite bf16 input through all five activations (pattern `bf16_all`); `fp32/lane` runs a grid over [-16, 16], 2^20 random inputs and the range edges (`fp32_dense`); `int8/lane` runs every input of every parameter set.
- **Diagnostics.** The check against the hardware model bit for bit, and the testbench's tolerance against the exact functions (the same 10%), still fail their point but are not the accuracy verdict. `bf16/lane` keeps the 1% sigmoid gate.
- **Every point passes** in every format (2026-10-12).

The table is `testbenches/results/regression/regression.log`; `make regression-summary` prints it again.

---

## Author

Soham Pramanik · [LinkedIn](https://www.linkedin.com/in/soham-pramanik-224004271/)
