#include "bsp_clk.h"
#include "bsp_led.h"
#include "bsp_delay.h"


int main(void)
{
	clk_enable();
	led_init();

	while(1)
	{	
		led_switch(LED0,ON);
		delay(500);

		led_switch(LED0,OFF);
		delay(500);
	}
	return 0;
}
