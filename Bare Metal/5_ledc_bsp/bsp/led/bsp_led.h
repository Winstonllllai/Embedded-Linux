#ifndef __BSP_LED_H__
#define __BSP_LED_H__

#include "imx6ul.h"
#define LED0 0

void led_init(void);
void led_switch(int led, int status);

#endif