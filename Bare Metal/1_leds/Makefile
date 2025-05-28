led.bin:led.s

	arm-none-eabi-gcc -g -c led.s -o led.o
	arm-none-eabi-ld -Ttext 0X87800000 led.o -o led.elf
	arm-none-eabi-objcopy -O binary -S -g led.elf led.bin
	arm-none-eabi-objdump -D led.elf > led.dis

clean:
