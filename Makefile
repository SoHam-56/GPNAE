# Project Structure
PRJ_DIR = $(shell pwd)
SRC_DIR = $(PRJ_DIR)/src
TB_DIR = $(PRJ_DIR)/testbenches

VERILATOR = verilator
IVERILOG = iverilog
VCS = vcs
VVP = vvp
WAVE = gtkwave

DESIGN_FILES = \
	../ArithmeticLibrary/Common/src/sienna_fmt_pkg.sv \
	../ArithmeticLibrary/Common/src/credit_link_if.sv \
	../ArithmeticLibrary/Common/src/credit_counter.sv \
	../ArithmeticLibrary/Common/src/credit_link_checker.sv \
	lane_fifo.sv \
	lane_link.sv \
	TYTAN/Memory/CoeffROM.v \
	TYTAN/Memory/InputFIFO.v \
	TYTAN/Memory/PE5B.v \
	TYTAN/Memory/RAM.v \
	TYTAN/Memory/ROM.v \
	TYTAN/LZC.v \
	../ArithmeticLibrary/Adders/FP32/src/fp32Adder.sv \
	../ArithmeticLibrary/Adders/FP32/src/LZC.sv \
	../ArithmeticLibrary/Multipliers/Radix4Booth/src/R4Booth.sv \
	../ArithmeticLibrary/Multipliers/Karatsuba/src/karatsubaUnsigned.sv \
	../ArithmeticLibrary/Multipliers/FP32/src/fp32Multiplier.sv \
	../ArithmeticLibrary/Multipliers/FP/src/fpMultiplier.sv \
	../ArithmeticLibrary/Adders/FP/src/fpAdder.sv \
	../ArithmeticLibrary/Multipliers/Int/src/intMultiplier.sv \
	../ArithmeticLibrary/Multipliers/Fx/src/fxMac.sv \
	../ArithmeticLibrary/Requant/src/tfliteRequant.sv \
	../ArithmeticLibrary/Divider/FP32/src/fp32Divider.sv \
	../ArithmeticLibrary/Divider/FP32/src/divu.sv \
	fp32_down.sv \
	fp32_up_down.sv \
	SeLu.sv \
	sigtan.sv \
	TYTAN/barrel_mac.sv \
	gpnae.sv \
	gpnae_tail.sv \
	gpnae_poly_int8.sv \
	gpnae_poly.sv

# ccache 3.7 here served corrupted objects that segfaulted at start-up; USE_CCACHE=1 opts back in.
USE_CCACHE ?= 0
ifeq ($(USE_CCACHE),0)
export CCACHE_DISABLE := 1
endif

TESTBENCH = TB_gpnae.sv
TOP_MODULE = TB_gpnae

VERILATOR_DIR = $(PRJ_DIR)/Verilator
IVERILOG_DIR = $(PRJ_DIR)/Icarus
VCS_DIR = $(PRJ_DIR)/VCS

# Simulation threads; several simulations at once each need fewer (Verilator's threads spin, so oversubscribed runs crawl).
SIM_THREADS ?= $(shell nproc)

VERILATOR_FLAGS = \
	--binary \
	--trace \
	--timing \
	--assert \
	--top-module $(TOP_MODULE) \
	--threads $(SIM_THREADS) \
	--build-jobs $(shell nproc) \
	--sv \
	-I$(SRC_DIR) \
	-I$(TB_DIR) \
	--Mdir $(VERILATOR_DIR) \
	--Wno-WIDTHTRUNC \
	--Wno-WIDTHEXPAND \
	--Wno-CASEINCOMPLETE \
	--Wno-MODDUP \
	--Wno-UNOPTTHREADS

# Hooks as in SIENNA: one-off defines (EXTRA_FLAGS) and simulator arguments (SIM_ARGS).
VERILATOR_FLAGS += $(EXTRA_FLAGS)

IVERILOG_FLAGS = \
	-g2012 \
	-Wall \
	-Wno-timescale \
	-I$(SRC_DIR) \
	-I$(TB_DIR)

VCS_FLAGS = \
	-full64 \
	-sverilog \
	-debug_all \
	-timescale=1ns/1ps \
	-Mdir=$(VCS_DIR) \
	+v2k \
	+incdir+$(SRC_DIR) \
	+incdir+$(TB_DIR)

default: help

help:
	@echo "Simulation Targets:"
	@echo "  make verilator    - Simulate using Verilator"
	@echo "  make iverilog     - Simulate using Icarus Verilog"
	@echo "  make vcs          - Simulate using Synopsys VCS"
	@echo "  make clean        - Remove all simulation artifacts"
	@echo "  make regression   - The model checks, the lane in fp32, bf16, int8 (FMT=<f>: one), bit-exact and against the functions, then one table"
	@echo "  make regression/<point>, make regression-summary - one point (regression.py --action points), the table again"

verilator:
	@echo "-- Verilator simulation for GPNAE"
	@mkdir -p $(VERILATOR_DIR)
	$(VERILATOR) $(VERILATOR_FLAGS) \
		$(addprefix $(SRC_DIR)/,$(DESIGN_FILES)) \
		$(TB_DIR)/$(TESTBENCH) \
		-o $(TOP_MODULE)_sim
	@echo "-- Compiling Verilator simulation"
	make -C $(VERILATOR_DIR) -f V$(TOP_MODULE).mk
	@echo "-- Running Verilator simulation"
	$(VERILATOR_DIR)/./$(TOP_MODULE)_sim $(SIM_ARGS)

iverilog:
	@echo "-- Icarus Verilog simulation for GPNAE"
	@mkdir -p $(IVERILOG_DIR)
	$(IVERILOG) $(IVERILOG_FLAGS) \
		-o $(IVERILOG_DIR)/$(TOP_MODULE)_sim \
		$(addprefix $(SRC_DIR)/,$(DESIGN_FILES)) \
		$(TB_DIR)/$(TESTBENCH)
	@echo "-- Running Icarus Verilog simulation"
	cd $(IVERILOG_DIR) && $(VVP) ./$(TOP_MODULE)_sim -vcd=$(TOP_MODULE).vcd
	@echo "-- Waveform generated at $(IVERILOG_DIR)/$(TOP_MODULE).vcd"

vcs:
	@echo "-- VCS simulation for GPNAE"
	@mkdir -p $(VCS_DIR)
	$(VCS) $(VCS_FLAGS) \
		-o $(VCS_DIR)/$(TOP_MODULE)_sim \
		$(addprefix $(SRC_DIR)/,$(DESIGN_FILES)) \
		$(TB_DIR)/$(TESTBENCH)
	@echo "-- Running VCS simulation"
	cd $(VCS_DIR) && ./$(TOP_MODULE)_sim -visualize
	@echo "-- Simulation complete"

view:
	@echo "-- Opening waveform"
	$(WAVE) $(IVERILOG_DIR)/$(TOP_MODULE).vcd

clean:
	@echo "-- Cleaning simulation artifacts"
	-rm -rf $(VERILATOR_DIR) $(IVERILOG_DIR) $(VCS_DIR)
	-rm -f *.vpd *.vcd

# Elaboration of one block in one format, e.g. make lint_fmt TOP=barrel_mac FMT="-GEXP_W=8 -GMAN_W=7".
lint_fmt:
	$(VERILATOR) --lint-only -Wno-fatal -Werror-USERFATAL -DSYNTHESIS --top-module $(TOP) $(FMT) -I$(SRC_DIR) -I$(SRC_DIR)/TYTAN/Memory \
		$(addprefix $(SRC_DIR)/,$(DESIGN_FILES))

.PHONY: default help verilator iverilog vcs view clean lint_fmt regression regression-summary

# make regression: the model checks, gpnae_poly bit-exact in fp32, bf16, int8 and against the functions (fp32 gated, bf16 reported); one target per point, then one table.
PYTHON  ?= python3
FORMATS  = fp32 bf16 int8
# Only FMT= on make's command line narrows it, not an exported FMT.
REG_FMT  = $(if $(filter command line,$(origin FMT)),$(FMT))
ifneq ($(REG_FMT),)
ifneq ($(filter-out $(FORMATS),$(REG_FMT))$(words $(REG_FMT)),1)
$(error Invalid FMT=$(FMT): must be one of fp32, bf16, int8)
endif
endif
comma := ,
empty :=
space := $(empty) $(empty)
REG_SELECT  = --formats $(subst $(space),$(comma),$(strip $(or $(REG_FMT),$(FORMATS))))
REG_DIR    ?= $(TB_DIR)/results/regression
REG_SUMMARY = $(PYTHON) regression.py --action summary --results $(REG_DIR) $(REG_SELECT)
ifneq ($(filter regression,$(MAKECMDGOALS)),)
ifeq ($(origin REG_RUN),undefined)
REG_RUN := $(shell date +%Y%m%d-%H%M%S)-$(shell echo $$PPID)
endif
REG_POINTS := $(shell $(PYTHON) regression.py --action points $(REG_SELECT))
endif

# One point, e.g. make regression/bf16/lane: runs in a private copy of the tree, writes $(REG_DIR)/<point>.log and .json.
regression/%:
	@$(PYTHON) regression.py --action point --name $* --results $(REG_DIR)$(if $(REG_RUN), --run $(REG_RUN))$(if $(filter regression,$(MAKECMDGOALS)), --keep-going)

regression: $(addprefix regression/,$(REG_POINTS))
	@$(REG_SUMMARY) --run $(REG_RUN)

# The table of the results already in REG_DIR; fails on any FAIL or NOT RUN.
regression-summary:
	@$(REG_SUMMARY)$(if $(REG_RUN), --run $(REG_RUN))
