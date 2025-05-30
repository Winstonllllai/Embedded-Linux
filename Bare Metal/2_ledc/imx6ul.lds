SECTIONS
{
    # The starting address of the Section
    # . is the current location counter

    . = 0X87800000;
    .text : {
        start.o
        main.o
        *(.text)
    }   # The .text section
    .rodata ALIGN(4) : { *(.rodata*) }  # read-only data section
    .data ALIGN(4) : { *(.data) }  # initialized data section


    # We need to record the start and end of the .bss section so as to initialize it to zero

    __bss_start = .;
    .bss ALIGN(4) : { *(.bss) *(COMMON) } # uninitialized data section
    __bss_end = .;
}
