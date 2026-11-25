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
# gcc 2.8.1 aligns jump tables to 8 (.align 3); the original's tables are
# only word-aligned, so cap rodata alignment at 4.
FIXALIGN   := sed 's/^\t\.align\t3$$/\t.align\t2/'

CPPFLAGS  := -undef -lang-c -nostdinc -Iinclude -Isrc -D_LANGUAGE_C -DUSE_INCLUDE_ASM
CFLAGS    := -quiet -O2 -G0 -mips1 -mcpu=3000 -mgas -msoft-float -fgnu-linker -funsigned-char

# Source files the original build compiled without optimisation
# (frame-pointer prologues, every variable kept on the stack).
O0_SRCS   := src/game/unk_80043F90.c
$(O0_SRCS:%.c=$(BUILD)/%.o): CFLAGS := -quiet -O0 -G0 -mips1 -mcpu=3000 -mgas -msoft-float -fgnu-linker -funsigned-char

# Most game-logic objects were assembled without divide-by-zero checks
# (no break 7 after div); unk_800191D4 and the sound objects have them.
NODIV_SRCS := src/game/main.c src/game/unk_8002B070.c \
              src/game/unk_8002FE30.c src/game/unk_8003CB78.c src/game/unk_8003DD74.c \
              src/game/unk_8003FD00.c
$(NODIV_SRCS:%.c=$(BUILD)/%.o): MASPSX := $(PYTHON) tools/maspsx/maspsx.py --aspsx-version=2.79
# The field overlay has no divide-by-zero checks either.
$(BUILD)/src/ov_%.o: MASPSX := $(PYTHON) tools/maspsx/maspsx.py --aspsx-version=2.79
# The PsyQ library objects in the main EXE were compiled with gcc 2.7.2
# (plain signed char) and assembled with ASPSX, whose delay-slot filling
# tools/aspsx_delay_slots.py reproduces.
$(BUILD)/src/lib/%.o: CC1 := tools/gcc-2.7.2-psx/cc1
# Objects built with the SN Systems cygnus-2.7.2-970404 cc1 instead
LIB_CDK := libc2/strcmp libc2/memmove
$(LIB_CDK:%=$(BUILD)/src/lib/%.o): CC1 := tools/gcc-2.7.2-cdk/cc1
$(BUILD)/src/lib/%.o: CFLAGS := -quiet -O2 -G0 -mips1 -mcpu=3000 -mgas -msoft-float -fgnu-linker -fsigned-char
$(BUILD)/src/lib/%.o: FIXALIGN := $(PYTHON) tools/aspsx_delay_slots.py
# ASPSX pads each object's sections to 16 bytes (the nops after the last
# function), so let GNU as pad these objects too.
$(BUILD)/src/lib/%.o: ASFLAGS := -EL -I. -Iinclude -march=r3000 -mtune=r3000 -O1 -G0
# ...except these, which end without padding (assembled separately:
# libsn and most of libgte are hand-written asm).
LIB_NOPAD := 2mbyte libgte/fog_02 libgte/msc00 libgte/smp_05 \
             libgte/smp_06 libetc/vmode unk_800285D8 unk_8004B230 libsn/lseek \
             libsn/fsinit libsn/snread libsn/snwrite libsn/_fixusdf
$(LIB_NOPAD:%=$(BUILD)/src/lib/%.o): ASFLAGS := -EL -I. -Iinclude -march=r3000 -mtune=r3000 -no-pad-sections -O1 -G0
# The PsyQ libpress object at the start of the field overlay was compiled
# with gcc 2.7.2 (unfilled jr delay slots), not the game's 2.8.1.
$(BUILD)/src/ov_field/libpress.o: CC1 := tools/gcc-2.7.2-psx/cc1
$(BUILD)/src/ov_field/libpress.o: FIXALIGN := $(PYTHON) tools/aspsx_delay_slots.py

ASFLAGS   := -EL -I. -Iinclude -march=r3000 -mtune=r3000 -no-pad-sections -O1 -G0
LDFLAGS   := -EL -nostdlib --no-check-sections -T undefined_funcs.txt -T linker_scripts/undefined_funcs_auto.txt \
             -T linker_scripts/undefined_syms_auto.txt -T $(LD_SCRIPT) -Map $(BUILD)/$(BASENAME).map

# Only the asm that the linker script actually uses (not asm/nonmatchings,
# which is pulled into C files through INCLUDE_ASM).
S_FILES   := $(shell find asm -name '*.s' -not -path 'asm/nonmatchings/*' -not -path 'asm/ov_*' 2>/dev/null)
C_FILES   := $(shell find src -name '*.c' -not -path 'src/ov_*' 2>/dev/null)
BIN_FILES := $(shell find assets -name '*.bin' 2>/dev/null)
O_FILES   := $(S_FILES:%.s=$(BUILD)/%.o) $(C_FILES:%.c=$(BUILD)/%.o) $(BIN_FILES:%.bin=$(BUILD)/%.o)

.DEFAULT_GOAL := all

# ---- Overlays (disc files loaded at runtime; see overlay_map.md) ----
# Each one is split from iso/files/NNNN.bin (tools/extract_files.py), linked on
# its own against the main EXE's symbols, and compared with the disc file.
OVERLAYS      := ov_field
ov_field_FILE := 0003

define OVERLAY_RULES
$(1)_S   := $$(shell find asm/$(1) -name '*.s' -not -path '*/nonmatchings/*' 2>/dev/null)
$(1)_C   := $$(shell find src/$(1) -name '*.c' 2>/dev/null)
$(1)_O   := $$($(1)_S:%.s=$(BUILD)/%.o) $$($(1)_C:%.c=$(BUILD)/%.o)
$(1)_LDFLAGS := -EL -nostdlib --no-check-sections -T undefined_funcs.txt \
                -T linker_scripts/$(1)_undefined_funcs_auto.txt \
                -T linker_scripts/$(1)_undefined_syms_auto.txt \
                -T linker_scripts/$(1).ld -Map $(BUILD)/$(1).map

$(BUILD)/$(1).elf: $$($(1)_O) linker_scripts/$(1).ld
	$$(LD) $$($(1)_LDFLAGS) -o $$@

$(BUILD)/files/$$($(1)_FILE).bin: $(BUILD)/$(1).elf
	@mkdir -p $$(dir $$@)
	$$(OBJCOPY) -O binary --gap-fill 0x00 $$< $$@

check-$(1): $(BUILD)/files/$$($(1)_FILE).bin
	@sha1sum $$< iso/files/$$($(1)_FILE).bin
	@cmp $$< iso/files/$$($(1)_FILE).bin && echo "OK: $$< matches" || (echo "MISMATCH: $(1)"; exit 1)

split-$(1):
	$$(PYTHON) -m splat split $(1).yaml
endef
$(foreach ov,$(OVERLAYS),$(eval $(call OVERLAY_RULES,$(ov))))

.PHONY: all split check clean progress $(OVERLAYS:%=check-%) $(OVERLAYS:%=split-%)
.DELETE_ON_ERROR:

# Overlays are checked too once they have been extracted into iso/files/.
all: check $(foreach ov,$(OVERLAYS),$(if $(wildcard iso/files/$($(ov)_FILE).bin),check-$(ov)))

split:
	$(PYTHON) -m splat split $(BASENAME).yaml

$(BUILD)/%.o: %.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

# C: preprocess -> PS1 gcc cc1 -> maspsx (ASPSX emulation) -> GNU as
$(BUILD)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) $< | $(CC1) $(CFLAGS) | $(FIXALIGN) | $(MASPSX) | $(AS) $(ASFLAGS) -o $@

# No per-file dependency tracking: rebuild every C object when a header changes
$(C_FILES:%.c=$(BUILD)/%.o): $(wildcard include/*.h)

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
