# Fail a recipe if any command in a pipeline fails (cc1 errors must not be
# hidden by the assembler at the end of the C pipeline).
SHELL       := /bin/bash
.SHELLFLAGS := -eo pipefail -c

BASENAME  := slus_010.41
TARGET    := iso/SLUS_010.41
BUILD     := build
ELF       := $(BUILD)/$(BASENAME).elf
EXE       := $(BUILD)/SLUS_010.41
LD_SCRIPT := linker_scripts/$(BASENAME).ld

CROSS     := mips-linux-gnu-
AS        := $(CROSS)as
LD        := $(CROSS)ld
OBJCOPY   := $(CROSS)objcopy
PYTHON    := .venv/bin/python3

# ---- C toolchain (run `bash tools/setup_tools.sh` once to download) ----
CC_VERSION ?= 2.8.1
CC_DIR     := tools/gcc-$(CC_VERSION)-psx
CPP        := $(CC_DIR)/cpp
CC1        := $(CC_DIR)/cc1
MASPSX     := $(PYTHON) tools/maspsx/maspsx.py --aspsx-version=2.79 --expand-div

CPPFLAGS  := -undef -lang-c -nostdinc -Iinclude -Isrc -D_LANGUAGE_C -DUSE_INCLUDE_ASM
CFLAGS    := -quiet -O2 -G0 -mips1 -mcpu=3000 -mgas -msoft-float -fgnu-linker -funsigned-char

# Source files the original build compiled without optimisation
# (frame-pointer prologues, every variable kept on the stack).
O0_SRCS   := src/game/unk_80043F90.c
$(O0_SRCS:%.c=$(BUILD)/%.o): CFLAGS := -quiet -O0 -G0 -mips1 -mcpu=3000 -mgas -msoft-float -fgnu-linker -funsigned-char

ASFLAGS   := -EL -I. -Iinclude -march=r3000 -mtune=r3000 -no-pad-sections -O1 -G0
LDFLAGS   := -EL -nostdlib --no-check-sections -T undefined_funcs.txt -T linker_scripts/undefined_funcs_auto.txt \
             -T linker_scripts/undefined_syms_auto.txt -T $(LD_SCRIPT) -Map $(BUILD)/$(BASENAME).map

# Only the asm that the linker script actually uses (not asm/nonmatchings,
# which is pulled into C files through INCLUDE_ASM).
S_FILES   := $(shell find asm -name '*.s' -not -path 'asm/nonmatchings/*' 2>/dev/null)
C_FILES   := $(shell find src -name '*.c' 2>/dev/null)
BIN_FILES := $(shell find assets -name '*.bin' 2>/dev/null)
O_FILES   := $(S_FILES:%.s=$(BUILD)/%.o) $(C_FILES:%.c=$(BUILD)/%.o) $(BIN_FILES:%.bin=$(BUILD)/%.o)

.PHONY: all split check clean progress
.DELETE_ON_ERROR:

all: check

split:
	$(PYTHON) -m splat split $(BASENAME).yaml

$(BUILD)/%.o: %.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

# C: preprocess -> PS1 gcc cc1 -> maspsx (ASPSX emulation) -> GNU as
$(BUILD)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) $< | $(CC1) $(CFLAGS) | $(MASPSX) | $(AS) $(ASFLAGS) -o $@

$(BUILD)/%.o: %.bin
	@mkdir -p $(dir $@)
	$(LD) -EL -r -b binary -o $@ $<

$(ELF): $(O_FILES) $(LD_SCRIPT)
	$(LD) $(LDFLAGS) -o $@

$(EXE): $(ELF)
	$(OBJCOPY) -O binary --gap-fill 0x00 $< $@

check: $(EXE)
	@sha1sum $(EXE) $(TARGET)
	@cmp $(EXE) $(TARGET) && echo "OK: $(EXE) matches" || (echo "MISMATCH"; exit 1)

clean:
	rm -rf $(BUILD)

# Refresh progress/files.csv and add this commit to progress/history.csv
progress: check
	$(PYTHON) tools/progress.py --files-csv progress/files.csv --history progress/history.csv
