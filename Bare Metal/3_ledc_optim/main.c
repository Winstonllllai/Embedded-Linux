#include "main.h"
/*
there are 5 steps to turn on the LED:
    1. enable clock for all peripherals
    2. set up GPIO1_IO03 as GPIO
    3. set up GPIO1_IO03 pad
    4. set GPIO1_IO03 as output
    5. turn on LED
*/
// Enable clock for all peripherals
void enable_peripherals_clock(void) {
    CCM_CCGR0 = 0xFFFFFFFF;
    CCM_CCGR1 = 0xFFFFFFFF;
    CCM_CCGR2 = 0xFFFFFFFF;
    CCM_CCGR3 = 0xFFFFFFFF;
    CCM_CCGR4 = 0xFFFFFFFF;
    CCM_CCGR5 = 0xFFFFFFFF;
    CCM_CCGR6 = 0xFFFFFFFF;
}

// Initialize led GPIO pin
void led_init(void) {
    SW_MUX_GPIO1_IO03 = 0x5;
    SW_PAD_GPIO1_IO03 = 0x10B0;
    GPIO1_GDIR = 0x00000008; // Set GPIO1_IO03 as output
    GPIO1_DR = 0X0; // Initialize GPIO1 data to 0
}

void led_on(void) {
    GPIO1_DR &= ~(1 << 3); // Turn on LED by clearing the bit for GPIO1_IO03
}

void led_off(void) {
    GPIO1_DR |= (1 << 3); // Turn off LED by setting the bit for GPIO1_IO03
}

void delay_short(volatile unsigned int n) {
    while(n--){}
}

void delay(volatile unsigned int n) {
    while(n--){
        // main frequency is 396MHz
        delay_short(0x7ff); //about 1ms delay
    }
}

int main(void) {
    enable_peripherals_clock();
    led_init();
    while(1) {
        led_on();
        delay(500);
        led_off();
        delay(500);
    }
    return 0;
}
