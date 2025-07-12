#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"


void clk_enable(void)
{
	CCM->CCGR0 = 0XFFFFFFFF;
	CCM->CCGR1 = 0XFFFFFFFF;

	CCM->CCGR2 = 0XFFFFFFFF;
	CCM->CCGR3 = 0XFFFFFFFF;
	CCM->CCGR4 = 0XFFFFFFFF;
	CCM->CCGR5 = 0XFFFFFFFF;
	CCM->CCGR6 = 0XFFFFFFFF;

}

void led_init(void)
{	// SW_MUX_GPIO1_IO03 = 0x5;
    // SW_PAD_GPIO1_IO03 = 0x10B0;
	IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03,0);
	IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03,0X10B0);

	GPIO1->GDIR |= (1 << 3);	

	GPIO1->DR &= ~(1 << 3);			
}

void led_on(void)
{
	GPIO1->DR &= ~(1<<3); 
}

void led_off(void)
{
	GPIO1->DR |= (1<<3); 
}

void delay_short(volatile unsigned int n)
{
	while(n--){}
}

void delay(volatile unsigned int n)
{
	while(n--)
	{
		delay_short(0x7ff);
	}
}

int main(void)
{
	clk_enable();
	led_init();

	while(1)
	{	
		led_off();
		delay(500);

		led_on();
		delay(500);
	}

	return 0;
}
