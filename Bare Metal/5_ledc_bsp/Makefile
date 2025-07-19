CROSS_COMPILER = arm-none-eabi-
TARGET = bsp

CC := $(CROSS_COMPILER)gcc
LD := $(CROSS_COMPILER)ld
OBJCOPY := $(CROSS_COMPILER)objcopy
OBJDUMP := $(CROSS_COMPILER)objdump

INCDIRS := imx6ul \
        bsp/clk \
        bsp/led \
        bsp/delay

SRCDIRS := project \
        bsp/clk \
        bsp/led \
        bsp/delay

INCLUDE = $(patsubst %, -I %, $(INCDIRS))
SFILES = $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.S))
CFILES = $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))
SFILENDIR = $(notdir $(SFILES))
CFILENDIR = $(notdir $(CFILES))

SOBJS = $(patsubst %, obj/%, $(SFILENDIR:.S=.o))
COBJS = $(patsubst %, obj/%, $(CFILENDIR:.c=.o))
OBJS = $(SOBJS) $(COBJS)

VPATH = $(SRCDIRS)


.PHONY: clean
$(TARGET).bin : $(OBJS)
	$(LD) -T imx6ul.lds -o $(TARGET).elf $^
	$(OBJCOPY) -O binary -S $(TARGET).elf $@
	$(OBJDUMP) -D -m arm $(TARGET).elf > $(TARGET).dis

$(SOBJS): obj/%.o : %.S
	$(CC) -Wall -nostdlib -c -O2 $(INCLUDE) -o $@ $<

$(COBJS): obj/%.o : %.c
	$(CC) -Wall -nostdlib -c -O2 $(INCLUDE) -o $@ $<
clean:
	rm -rf $(TARGET).elf $(TARGET).dis $(TARGET).bin $(COBJS) $(SOBJS)
