# Project Structure
PRJ_DIR = $(shell pwd)
SRC_DIR = $(PRJ_DIR)/src
TB_DIR = $(PRJ_DIR)/testbenches
ARIL = $(PRJ_DIR)/ArithmeticLibrary

# The build's precision: FMT=fp32 (default), bf16 or int8; FMT_DEF is the define sienna_fmt_pkg reads (ArithmeticLibrary's fmt.mk).
include $(ARIL)/Common/fmt.mk
# The simulator: SIM ?= verilator, or vcs (ArithmeticLibrary's sim.mk: plain VCS builds, TRACE=1, XPROP=1, RANDINIT=1); make vcs runs TB_gpnae on VCS.
VCS_LINT_BASELINE = $(PRJ_DIR)/vcs_lint_baseline.txt
include $(ARIL)/Common/sim.mk

VERILATOR = verilator

# The lane: the format package, the credit interface, the units every format's math modules may pick, then gpnae's own files.
DESIGN_FILES = \
	$(ARIL)/Common/src/sienna_fmt_pkg.sv \
	$(ARIL)/Common/src/credit_link_if.sv \
	$(ARIL)/Common/src/credit_counter.sv \
	$(ARIL)/Common/src/credit_link_checker.sv \
	$(ARIL)/Fmt/src/fmt_mul.sv \
	$(ARIL)/Fmt/src/fmt_add.sv \
	$(ARIL)/Multipliers/Radix4Booth/src/R4Booth.sv \
	$(ARIL)/Multipliers/Karatsuba/src/karatsubaUnsigned.sv \
	$(ARIL)/Multipliers/FP32/src/fp32Multiplier.sv \
	$(ARIL)/Adders/FP32/src/LZC.sv \
	$(ARIL)/Adders/FP32/src/fp32Adder.sv \
	$(ARIL)/Multipliers/BF16/src/bf16Multiplier.sv \
	$(ARIL)/Multipliers/BF16Wide/src/bf16WideMultiplier.sv \
	$(ARIL)/Adders/BF16/src/bf16Adder.sv \
	$(ARIL)/Converters/FP32ToBF16/src/fp32ToBf16.sv \
	$(ARIL)/Multipliers/Int8/src/int8Multiplier.sv \
	$(ARIL)/Adders/Int32/src/int32Adder.sv \
	$(ARIL)/Multipliers/Int16/src/int16Multiplier.sv \
	$(ARIL)/Multipliers/Int24/src/int24Multiplier.sv \
	$(ARIL)/Requantizer/src/int8Requantizer.sv \
	$(SRC_DIR)/lane/gpnae_pkg.sv \
	$(SRC_DIR)/link/lane_fifo.sv \
	$(SRC_DIR)/link/lane_link.sv \
	$(SRC_DIR)/mac/fixedPointMultiplyAdd.sv \
	$(SRC_DIR)/lane/gpnae_horner.sv \
	$(SRC_DIR)/mac/barrel_mac.sv \
	$(SRC_DIR)/lane/gpnae_exp_split.sv \
	$(SRC_DIR)/memory/gpnae_coef_mem.sv \
	$(SRC_DIR)/lane/gpnae_act_in.sv \
	$(SRC_DIR)/lane/gpnae_post.sv \
	$(SRC_DIR)/lane/gpnae_tail.sv \
	$(SRC_DIR)/lane/gpnae.sv

# ccache 3.7 here served corrupted objects that segfaulted at start-up; USE_CCACHE=1 opts back in.
USE_CCACHE ?= 0
ifeq ($(USE_CCACHE),0)
export CCACHE_DISABLE := 1
endif

TESTBENCH = TB_gpnae.sv
TOP_MODULE = TB_gpnae

VERILATOR_DIR = $(PRJ_DIR)/Verilator

# Waveforms as in SIENNA: TRACE=1 or vcd writes tb_gpnae.vcd, fst writes tb_gpnae.fst; the default 0 writes none.
TRACE ?= 0
ifeq ($(filter $(TRACE),0 1 vcd fst),)
$(error Invalid TRACE=$(TRACE): must be one of 0, 1, vcd, fst)
endif
TRACE_ON = $(filter $(TRACE),1 vcd fst)

# Simulation threads: one lane is too small to share, so 1 (a 2^16-input fp32 run: 35.5 s at 1 thread, 151 s at 8; rs1_tf_thr1/8).
SIM_THREADS ?= 1

VERILATOR_FLAGS = \
	--binary \
	--timing \
	--assert \
	--top-module $(TOP_MODULE) \
	--threads $(SIM_THREADS) \
	-j $(shell nproc) \
	--build-jobs $(shell nproc) \
	--sv \
	$(FMT_DEF) \
	-I$(SRC_DIR) \
	-I$(TB_DIR) \
	--Mdir $(VERILATOR_DIR) \
	--Wno-WIDTHTRUNC \
	--Wno-WIDTHEXPAND \
	--Wno-CASEINCOMPLETE \
	--Wno-UNOPTTHREADS

# Hooks as in SIENNA: one-off defines or -G overrides (EXTRA_FLAGS) and simulator arguments (SIM_ARGS).
VERILATOR_FLAGS += $(EXTRA_FLAGS)
ifeq ($(TRACE),fst)
VERILATOR_FLAGS += --trace-fst -DENABLE_TRACE -DTRACE_FST
else ifneq ($(TRACE_ON),)
VERILATOR_FLAGS += --trace -DENABLE_TRACE
endif

default: help

help:
	@echo "  make vcs [FMT=f]        - the same on Synopsys VCS (README: Running with VCS); SIM=vcs runs make regression on VCS"
	@echo "  make verilator [FMT=f]  - build and run TB_gpnae (regression.py writes its stimulus; the run size and tier are SIM_ARGS)"
	@echo "  make barrel-mac [FMT=f] - TB_barrel_mac on barrel_mac_vectors.py's groups, bit for bit"
	@echo "  make lint [FMT=f]       - verilator --lint-only -Wall of gpnae and each of its new modules, with and without SYNTHESIS (lint_waivers.vlt: the library's and B's lane_link's own)"
	@echo "  make check-fmt          - no RTL outside the allowlist names a precision (C4: a planted EXP_W must fail it)"
	@echo "  make check-hier         - at each define, the lane elaborates only that precision's units"
	@echo "  make fit                - fit_poly_coeffs.py: every tier, then the default JSON and gpnae_coef_mem.sv's tables"
	@echo "  make clean              - remove the simulation artifacts"
	@echo "  make regression [FMT=f] - every point (regression.py --action points), one table; make regression/<point>, make regression-summary"

verilator:
	@echo "-- Verilator simulation for GPNAE, $(FMT)"
	@mkdir -p $(VERILATOR_DIR)
	$(VERILATOR) $(VERILATOR_FLAGS) $(DESIGN_FILES) $(TB_DIR)/top/$(TESTBENCH) -o $(TOP_MODULE)_sim
	$(VERILATOR_DIR)/./$(TOP_MODULE)_sim $(SIM_ARGS)

# VCS: TB_gpnae with the same define, include paths and plusargs; EXTRA_FLAGS' -G overrides become -pvalue+, its -D defines +define+.
VCS_DIR  = $(PRJ_DIR)/VCS
VCS_XTRA = $(call vcs_g,$(TOP_MODULE),$(EXTRA_FLAGS)) $(patsubst -D%,+define+%,$(filter -D%,$(EXTRA_FLAGS))) $(filter +define+%,$(EXTRA_FLAGS))
vcs:
	@echo "-- VCS simulation for GPNAE, $(FMT)"
	$(call vcs_build,$(TOP_MODULE),$(VCS_DIR),$(DESIGN_FILES) $(TB_DIR)/top/$(TESTBENCH),$(FMT_DEF) +incdir+$(SRC_DIR) +incdir+$(TB_DIR) $(VCS_XTRA))
	$(VCS_DIR)/sim $(VCS_RUN) $(SIM_ARGS)

PYTHON ?= python3

barrel-mac:
	@mkdir -p $(VERILATOR_DIR)_bm
	$(PYTHON) scripts/barrel_mac_vectors.py $(FMT)
ifeq ($(SIM),vcs)
	$(call vcs_build,TB_barrel_mac,$(VCS_DIR)_bm,$(DESIGN_FILES) $(TB_DIR)/units/TB_barrel_mac.sv,$(FMT_DEF))
	$(VCS_DIR)_bm/sim $(VCS_RUN)
else
	$(VERILATOR) --binary --timing --assert -j $(shell nproc) --build-jobs $(shell nproc) -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND $(FMT_DEF) \
	  --top-module TB_barrel_mac --Mdir $(VERILATOR_DIR)_bm $(DESIGN_FILES) $(TB_DIR)/units/TB_barrel_mac.sv -o sim
	$(VERILATOR_DIR)_bm/sim
endif

LINT_TOPS = fixedPointMultiplyAdd gpnae_horner barrel_mac gpnae_exp_split gpnae_coef_mem gpnae_act_in gpnae_post gpnae
# make lint SIM=vcs: VCS's +lint=all of each top, with and without SYNTHESIS (Common/vcs_lint.py; reported until vcs_lint_baseline.txt holds it)
lint:
ifeq ($(SIM),vcs)
	@rc=0; for t in $(LINT_TOPS) $(if $(filter bf16,$(FMT)),gpnae_tail); do \
	  $(call vcs_lint,$$t $(FMT),$$t,$(DESIGN_FILES),+define+SYNTHESIS $(FMT_DEF)) || rc=1; \
	  $(call vcs_lint,$$t $(FMT) sim,$$t,$(DESIGN_FILES),$(FMT_DEF)) || rc=1; done; exit $$rc
else
	@for t in $(LINT_TOPS) $(if $(filter bf16,$(FMT)),gpnae_tail); do \
	  bash $(ARIL)/Common/lint.sh "lint $$t $(FMT)" -Wall -Wno-fatal -DSYNTHESIS $(FMT_DEF) --top-module $$t $(PRJ_DIR)/scripts/lint_waivers.vlt $(DESIGN_FILES) || exit 1; \
	  bash $(ARIL)/Common/lint.sh "lint $$t $(FMT) sim" -Wall -Wno-fatal $(FMT_DEF) --top-module $$t $(PRJ_DIR)/scripts/lint_waivers.vlt $(DESIGN_FILES) || exit 1; done
	@t=$$(mktemp -d); sed 's/^endmodule/  logic lint_planted;\nendmodule/' $(SRC_DIR)/lane/gpnae.sv > $$t/gpnae.sv; \
	if verilator --lint-only -Wall -Wno-fatal -DSYNTHESIS $(FMT_DEF) --top-module gpnae $(PRJ_DIR)/scripts/lint_waivers.vlt $(filter-out $(SRC_DIR)/lane/gpnae.sv,$(DESIGN_FILES)) \
	  $$t/gpnae.sv 2>&1 | command grep -q "UNUSEDSIGNAL.*lint_planted"; then echo "lint control OK: a warning planted in gpnae.sv shows through the waivers"; \
	else echo "lint control FAIL: a warning planted in gpnae.sv did not show"; rm -rf $$t; exit 1; fi; \
	if verilator --lint-only -Wall -Wno-fatal $(FMT_DEF) --top-module gpnae $(PRJ_DIR)/scripts/lint_waivers.vlt $(filter-out $(SRC_DIR)/lane/gpnae.sv,$(DESIGN_FILES)) \
	  $$t/gpnae.sv 2>&1 | command grep -q "UNUSEDSIGNAL.*lint_planted"; then echo "lint control OK (sim): a warning planted in gpnae.sv shows through the waivers without SYNTHESIS"; \
	else echo "lint control FAIL (sim): a warning planted in gpnae.sv did not show without SYNTHESIS"; rm -rf $$t; exit 1; fi; rm -rf $$t
endif

# check-fmt: the allowlist is the package and ArithmeticLibrary's units, and GPNAE's define-selected math modules.
FMT_ALLOW = ^(ArithmeticLibrary/.*|src/(lane/gpnae_act_in|lane/gpnae_post|memory/gpnae_coef_mem|lane/gpnae_horner)\.sv)$$
check-fmt:
	@bash $(ARIL)/Common/check_fmt.sh $(PRJ_DIR) '$(FMT_ALLOW)' && echo "check-fmt OK: the tree passes" || { echo "check-fmt FAIL: the tree"; exit 1; }
	@t=$$(mktemp -d); mkdir -p $$t/src/lane; cp $(SRC_DIR)/lane/gpnae.sv $$t/src/lane/; echo '// EXP_W' >> $$t/src/lane/gpnae.sv; \
	if bash $(ARIL)/Common/check_fmt.sh $$t '$(FMT_ALLOW)' > $$t/c4.log; then echo "check-fmt FAIL: C4 planted EXP_W passed"; exit 1; \
	elif ! /usr/bin/grep -q '^check-fmt: 1 RTL files outside the allowlist, 1 naming a precision$$' $$t/c4.log; then echo "check-fmt FAIL: C4 failed for another reason"; cat $$t/c4.log; exit 1; \
	else echo "check-fmt OK: C4 planted EXP_W in gpnae.sv fails"; fi; rm -rf $$t

check-hier:
	@$(PYTHON) $(PRJ_DIR)/scripts/check_hier.py --verilator $(VERILATOR) --out $(PRJ_DIR)/Verilator_hier --files $(DESIGN_FILES)

fit:
	$(PYTHON) scripts/fit_poly_coeffs.py

clean:
	-rm -rf $(VERILATOR_DIR) $(VERILATOR_DIR)_bm $(PRJ_DIR)/Verilator_hier $(PRJ_DIR)/VCS $(PRJ_DIR)/VCS_bm
	-rm -f *.vcd *.fst

.PHONY: default help verilator vcs barrel-mac lint check-fmt check-hier fit clean regression regression-summary

# make regression: selftest, check-model and per format the barrel MAC, each tier's gate, protocol, load, cycles and the two faults.
FORMATS  = fp32 bf16 int8
# Only FMT= on make's command line narrows it, not an exported FMT.
REG_FMT  = $(if $(filter command line,$(origin FMT)),$(FMT))
comma := ,
empty :=
space := $(empty) $(empty)
REG_SELECT  = --formats $(subst $(space),$(comma),$(strip $(or $(REG_FMT),$(FORMATS))))
REG_DIR    ?= $(TB_DIR)/results/regression
REG_SUMMARY = $(PYTHON) regression.py --action summary --results $(REG_DIR) $(REG_SELECT) --sim $(SIM)
ifneq ($(filter regression,$(MAKECMDGOALS)),)
ifeq ($(origin REG_RUN),undefined)
REG_RUN := $(shell date +%Y%m%d-%H%M%S)-$(shell echo $$PPID)
endif
REG_POINTS := $(shell $(PYTHON) regression.py --action points $(REG_SELECT))
endif

# One point, e.g. make regression/bf16/lane-t0: runs in a private copy of the tree, writes $(REG_DIR)/<point>.log and .json.
regression/%:
	@$(PYTHON) regression.py --action point --name $* --results $(REG_DIR) --sim $(SIM)$(if $(REG_RUN), --run $(REG_RUN))$(if $(filter regression,$(MAKECMDGOALS)), --keep-going)

regression: $(addprefix regression/,$(REG_POINTS))
	@$(REG_SUMMARY) --run $(REG_RUN)

# The table of the results already in REG_DIR; fails on any FAIL or NOT RUN.
regression-summary:
	@$(REG_SUMMARY)$(if $(REG_RUN), --run $(REG_RUN))
