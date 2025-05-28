.global _start // Define entry point for the program. The program starts executing from this label.

/*
there are 5 steps to turn on the LED:
    1. enable clock for all peripherals
    2. set up GPIO1_IO03 as GPIO
    3. set up GPIO1_IO03 pad
    4. set GPIO1_IO03 as output
    5. turn on LED
*/
_start:
    // 1. clock enables
    // enable clock for all peripherals
    ldr r0, =0x020C4068 // register CCGR0
    ldr r1, =0xFFFFFFFF
    str r1, [r0]

    ldr r0, =0x020C406C // register CCGR1
    str r1, [r0]

    ldr r0, =0x020C4070 // register CCGR2
    str r1, [r0]

    ldr r0, =0x020C4074 // register CCGR3
    str r1, [r0]

    ldr r0, =0x020C4078 // register CCGR4
    str r1, [r0]

    ldr r0, =0x020C407C // register CCGR5
    str r1, [r0]

    ldr r0, =0x020C4080 // register CCGR6
    str r1, [r0]
    //-------------------------------------------------------------

    // 2. set up GPIO1_IO03 as GPIO
    ldr r0, =0x020E0068 // register IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03
    ldr r1, =0x5 // MUX mode ALT5
    str r1, [r0]
    //-------------------------------------------------------------

    // 3. set up GPIO1_IO03 pad

    /**bit 16:0 HYS disable
    *bit [15:14]: 00 pull down
    *bit [13]: 0 keeper disabled
    *bit [12]: 1 pull/keeper enables
    *bit [11]: 0 open drain disabled
    *bit [7:6]: 10 speed 100Mhz
    *bit [5:3]: 110 R0/6 driver strength
    *bit [0]: 0 low transition rate
    */
    ldr r0, =0x020E02F4 // register IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO03
    ldr r1, =0x10B0
    str r1, [r0]
    //-------------------------------------------------------------

    // 4. set GPIO1_IO03 as output
    ldr r0, =0X0209C004 // register GPIO1_GDIR
    ldr r1, =0x00000008 // set bit 3 to 1 as output
    str r1, [r0]
    //-------------------------------------------------------------

    // 5. turn on LED
    ldr r0, =0X0209C000 // register GPIO1_DR
    ldr r1, =0x00000000 // set bit 3 to 0 to turn on LED
    str r1, [r0]
    //-------------------------------------------------------------

// infinite loop to keep the program running
loop:
    b loop 