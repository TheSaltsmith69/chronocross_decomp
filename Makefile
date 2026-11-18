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

ASFLAGS   := -EL -Iinclude -march=r3000 -mtune=r3000 -no-pad-sections -O1 -G0
LDFLAGS   := -EL -nostdlib --no-check-sections -T undefined_funcs.txt -T linker_scripts/undefined_funcs_auto.txt \
             -T linker_scripts/undefined_syms_auto.txt -T $(LD_SCRIPT) -Map $(BUILD)/$(BASENAME).map

S_FILES   := $(shell find asm -name '*.s' 2>/dev/null)
BIN_FILES := $(shell find assets -name '*.bin' 2>/dev/null)
O_FILES   := $(S_FILES:%.s=$(BUILD)/%.o) $(BIN_FILES:%.bin=$(BUILD)/%.o)

.PHONY: all split check clean

all: check

split:
	$(PYTHON) -m splat split $(BASENAME).yaml

$(BUILD)/%.o: %.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

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
