#ifndef __MAIN_H__
#define __MAIN_H__

// Define the clock control module register address
// There's no need to define each register individually as a struct is used
// Define the base address
// You can use the following structure to access the registers
#define CCM_BASE					(0X020C4000)
#define CCM_ANALOG_BASE				(0X020C8000)
#define IOMUX_SW_MUX_BASE			(0X020E0014)
#define IOMUX_SW_PAD_BASE			(0X020E0204)
#define GPIO1_BASE                  (0x0209C000)
#define GPIO2_BASE                  (0x020A0000)
#define GPIO3_BASE                  (0x020A4000)
#define GPIO4_BASE                  (0x020A8000)
#define GPIO5_BASE                  (0x020AC000)

typedef struct 
{
	volatile unsigned int CCR;
	volatile unsigned int CCDR;
	volatile unsigned int CSR;
	volatile unsigned int CCSR;
	volatile unsigned int CACRR;
	volatile unsigned int CBCDR;
	volatile unsigned int CBCMR;
	volatile unsigned int CSCMR1;
	volatile unsigned int CSCMR2;
	volatile unsigned int CSCDR1;
	volatile unsigned int CS1CDR;
	volatile unsigned int CS2CDR;
	volatile unsigned int CDCDR;
	volatile unsigned int CHSCCDR;
	volatile unsigned int CSCDR2;
	volatile unsigned int CSCDR3;	
	volatile unsigned int RESERVED_1[2];
	volatile unsigned int CDHIPR;  
	volatile unsigned int RESERVED_2[2];
	volatile unsigned int CLPCR;
	volatile unsigned int CISR;
	volatile unsigned int CIMR;
	volatile unsigned int CCOSR;
	volatile unsigned int CGPR;
	volatile unsigned int CCGR0;
	volatile unsigned int CCGR1;
	volatile unsigned int CCGR2;
	volatile unsigned int CCGR3;
	volatile unsigned int CCGR4;
	volatile unsigned int CCGR5;
	volatile unsigned int CCGR6;
	volatile unsigned int RESERVED_3[1];
	volatile unsigned int CMEOR;	
} CCM_Type; 
// CCM is a pointer to the CCM_Type structure
// This allows you to access the registers using the CCM pointer
// For example, to access the CCR register, you can use CCM->CCR
#define CCM ((CCM_Type *) CCM_BASE)

//Original code
// #define CCM_CCGR0 *((volatile unsigned int *)0x020C4068)
// #define CCM_CCGR1 *((volatile unsigned int *)0x020C406C)
// #define CCM_CCGR2 *((volatile unsigned int *)0x020C4070)
// #define CCM_CCGR3 *((volatile unsigned int *)0x020C4074)
// #define CCM_CCGR4 *((volatile unsigned int *)0x020C4078)
// #define CCM_CCGR5 *((volatile unsigned int *)0x020C407C)
// #define CCM_CCGR6 *((volatile unsigned int *)0x020C4080)
typedef struct 
{
	volatile unsigned int PLL_ARM;
	volatile unsigned int PLL_ARM_SET;
	volatile unsigned int PLL_ARM_CLR;
	volatile unsigned int PLL_ARM_TOG;
	volatile unsigned int PLL_USB1;
	volatile unsigned int PLL_USB1_SET;
	volatile unsigned int PLL_USB1_CLR;
	volatile unsigned int PLL_USB1_TOG;
	volatile unsigned int PLL_USB2;
	volatile unsigned int PLL_USB2_SET;
	volatile unsigned int PLL_USB2_CLR;
	volatile unsigned int PLL_USB2_TOG;
	volatile unsigned int PLL_SYS;
	volatile unsigned int PLL_SYS_SET;
	volatile unsigned int PLL_SYS_CLR;
	volatile unsigned int PLL_SYS_TOG;
	volatile unsigned int PLL_SYS_SS;
	volatile unsigned int RESERVED_1[3];
	volatile unsigned int PLL_SYS_NUM;
	volatile unsigned int RESERVED_2[3];
	volatile unsigned int PLL_SYS_DENOM; 
	volatile unsigned int RESERVED_3[3];
	volatile unsigned int PLL_AUDIO;
	volatile unsigned int PLL_AUDIO_SET;
	volatile unsigned int PLL_AUDIO_CLR;
	volatile unsigned int PLL_AUDIO_TOG;
	volatile unsigned int PLL_AUDIO_DENOM;
	volatile unsigned int RESERVED_4[3];
	volatile unsigned int PLL_VIDEO;
	volatile unsigned int PLL_VIDEO_SET;
	volatile unsigned int PLL_VIDEO_CLR;
	volatile unsigned int PLL_VIDEO_TOG;
	volatile unsigned int PLL_VIDEO_NUM;
	volatile unsigned int RESERVED_5[3];
	volatile unsigned int PLL_VIDEO_DENOM;
	volatile unsigned int RESERVED_6[7];
	volatile unsigned int PLL_ENET;
	volatile unsigned int PLL_ENET_SET;
	volatile unsigned int PLL_ENET_CLR;
	volatile unsigned int PLL_ENET_TOG;
	volatile unsigned int PFD_480;
	volatile unsigned int PFD_480_SET;
	volatile unsigned int PFD_480_CLR;
	volatile unsigned int PFD_480_TOG;
	volatile unsigned int PFD_528;
	volatile unsigned int PFD_528_SET;
	volatile unsigned int PFD_528_CLR;
	volatile unsigned int PFD_528_TOG;
	volatile unsigned int RESERVED_7[16];
	volatile unsigned int MISC0;
	volatile unsigned int MISC0_SET;
	volatile unsigned int MISC0_CLR;
	volatile unsigned int MISC0_TOG;
	volatile unsigned int MISC1;
	volatile unsigned int MISC1_SET;
	volatile unsigned int MISC1_CLR;
	volatile unsigned int MISC1_TOG;
	volatile unsigned int MISC2;
	volatile unsigned int MISC2_SET;
	volatile unsigned int MISC2_CLR;
	volatile unsigned int MISC2_TOG;
} CCM_ANALOG_Type; 
// Define IOMUX register address

typedef struct 
{
	volatile unsigned int BOOT_MODE0;
	volatile unsigned int BOOT_MODE1;
	volatile unsigned int SNVS_TAMPER0;
	volatile unsigned int SNVS_TAMPER1;
	volatile unsigned int SNVS_TAMPER2;
	volatile unsigned int SNVS_TAMPER3;
	volatile unsigned int SNVS_TAMPER4;
	volatile unsigned int SNVS_TAMPER5;
	volatile unsigned int SNVS_TAMPER6;
	volatile unsigned int SNVS_TAMPER7;
	volatile unsigned int SNVS_TAMPER8;
	volatile unsigned int SNVS_TAMPER9;
	volatile unsigned int JTAG_MOD;
	volatile unsigned int JTAG_TMS;
	volatile unsigned int JTAG_TDO;
	volatile unsigned int JTAG_TDI;
	volatile unsigned int JTAG_TCK;
	volatile unsigned int JTAG_TRST_B;
	volatile unsigned int GPIO1_IO00;
	volatile unsigned int GPIO1_IO01;
	volatile unsigned int GPIO1_IO02;
	volatile unsigned int GPIO1_IO03;
	volatile unsigned int GPIO1_IO04;
	volatile unsigned int GPIO1_IO05;
	volatile unsigned int GPIO1_IO06;
	volatile unsigned int GPIO1_IO07;
	volatile unsigned int GPIO1_IO08;
	volatile unsigned int GPIO1_IO09;
	volatile unsigned int UART1_TX_DATA;
	volatile unsigned int UART1_RX_DATA;
	volatile unsigned int UART1_CTS_B;
	volatile unsigned int UART1_RTS_B;
	volatile unsigned int UART2_TX_DATA;
	volatile unsigned int UART2_RX_DATA;
	volatile unsigned int UART2_CTS_B;
	volatile unsigned int UART2_RTS_B;
	volatile unsigned int UART3_TX_DATA;
	volatile unsigned int UART3_RX_DATA;
	volatile unsigned int UART3_CTS_B;
	volatile unsigned int UART3_RTS_B;
	volatile unsigned int UART4_TX_DATA;
	volatile unsigned int UART4_RX_DATA;
	volatile unsigned int UART5_TX_DATA;
	volatile unsigned int UART5_RX_DATA;
	volatile unsigned int ENET1_RX_DATA0;
	volatile unsigned int ENET1_RX_DATA1;
	volatile unsigned int ENET1_RX_EN;
	volatile unsigned int ENET1_TX_DATA0;
	volatile unsigned int ENET1_TX_DATA1;
	volatile unsigned int ENET1_TX_EN;
	volatile unsigned int ENET1_TX_CLK;
	volatile unsigned int ENET1_RX_ER;
	volatile unsigned int ENET2_RX_DATA0;
	volatile unsigned int ENET2_RX_DATA1;
	volatile unsigned int ENET2_RX_EN;
	volatile unsigned int ENET2_TX_DATA0;
	volatile unsigned int ENET2_TX_DATA1;
	volatile unsigned int ENET2_TX_EN;
	volatile unsigned int ENET2_TX_CLK;
	volatile unsigned int ENET2_RX_ER;
	volatile unsigned int LCD_CLK;
	volatile unsigned int LCD_ENABLE;
	volatile unsigned int LCD_HSYNC;
	volatile unsigned int LCD_VSYNC;
	volatile unsigned int LCD_RESET;
	volatile unsigned int LCD_DATA00;
	volatile unsigned int LCD_DATA01;
	volatile unsigned int LCD_DATA02;
	volatile unsigned int LCD_DATA03;
	volatile unsigned int LCD_DATA04;
	volatile unsigned int LCD_DATA05;
	volatile unsigned int LCD_DATA06;
	volatile unsigned int LCD_DATA07;
	volatile unsigned int LCD_DATA08;
	volatile unsigned int LCD_DATA09;
	volatile unsigned int LCD_DATA10;
	volatile unsigned int LCD_DATA11;
	volatile unsigned int LCD_DATA12;
	volatile unsigned int LCD_DATA13;
	volatile unsigned int LCD_DATA14;
	volatile unsigned int LCD_DATA15;
	volatile unsigned int LCD_DATA16;
	volatile unsigned int LCD_DATA17;
	volatile unsigned int LCD_DATA18;
	volatile unsigned int LCD_DATA19;
	volatile unsigned int LCD_DATA20;
	volatile unsigned int LCD_DATA21;
	volatile unsigned int LCD_DATA22;
	volatile unsigned int LCD_DATA23;
	volatile unsigned int NAND_RE_B;
	volatile unsigned int NAND_WE_B;
	volatile unsigned int NAND_DATA00;
	volatile unsigned int NAND_DATA01;
	volatile unsigned int NAND_DATA02;
	volatile unsigned int NAND_DATA03;
	volatile unsigned int NAND_DATA04;
	volatile unsigned int NAND_DATA05;
	volatile unsigned int NAND_DATA06;
	volatile unsigned int NAND_DATA07;
	volatile unsigned int NAND_ALE;
	volatile unsigned int NAND_WP_B;
	volatile unsigned int NAND_READY_B;
	volatile unsigned int NAND_CE0_B;
	volatile unsigned int NAND_CE1_B;
	volatile unsigned int NAND_CLE;
	volatile unsigned int NAND_DQS;
	volatile unsigned int SD1_CMD;
	volatile unsigned int SD1_CLK;
	volatile unsigned int SD1_DATA0;
	volatile unsigned int SD1_DATA1;
	volatile unsigned int SD1_DATA2;
	volatile unsigned int SD1_DATA3;
	volatile unsigned int CSI_MCLK;
	volatile unsigned int CSI_PIXCLK;
	volatile unsigned int CSI_VSYNC;
	volatile unsigned int CSI_HSYNC;
	volatile unsigned int CSI_DATA00;
	volatile unsigned int CSI_DATA01;
	volatile unsigned int CSI_DATA02;
	volatile unsigned int CSI_DATA03;
	volatile unsigned int CSI_DATA04;
	volatile unsigned int CSI_DATA05;
	volatile unsigned int CSI_DATA06;
	volatile unsigned int CSI_DATA07;
}IOMUX_SW_MUX_Type;

typedef struct 
{
	volatile unsigned int DRAM_ADDR00;
	volatile unsigned int DRAM_ADDR01;
	volatile unsigned int DRAM_ADDR02;
	volatile unsigned int DRAM_ADDR03;
	volatile unsigned int DRAM_ADDR04;
	volatile unsigned int DRAM_ADDR05;
	volatile unsigned int DRAM_ADDR06;
	volatile unsigned int DRAM_ADDR07;
	volatile unsigned int DRAM_ADDR08;
	volatile unsigned int DRAM_ADDR09;
	volatile unsigned int DRAM_ADDR10;
	volatile unsigned int DRAM_ADDR11;
	volatile unsigned int DRAM_ADDR12;
	volatile unsigned int DRAM_ADDR13;
	volatile unsigned int DRAM_ADDR14;
	volatile unsigned int DRAM_ADDR15;
	volatile unsigned int DRAM_DQM0;
	volatile unsigned int DRAM_DQM1;
	volatile unsigned int DRAM_RAS_B;
	volatile unsigned int DRAM_CAS_B;
	volatile unsigned int DRAM_CS0_B;
	volatile unsigned int DRAM_CS1_B;
	volatile unsigned int DRAM_SDWE_B;
	volatile unsigned int DRAM_ODT0;
	volatile unsigned int DRAM_ODT1;
	volatile unsigned int DRAM_SDBA0;
	volatile unsigned int DRAM_SDBA1;
	volatile unsigned int DRAM_SDBA2;
	volatile unsigned int DRAM_SDCKE0;
	volatile unsigned int DRAM_SDCKE1;
	volatile unsigned int DRAM_SDCLK0_P;
	volatile unsigned int DRAM_SDQS0_P;
	volatile unsigned int DRAM_SDQS1_P;
	volatile unsigned int DRAM_RESET;
	volatile unsigned int TEST_MODE;
	volatile unsigned int POR_B;
	volatile unsigned int ONOFF;
	volatile unsigned int SNVS_PMIC_ON_REQ;
	volatile unsigned int CCM_PMIC_STBY_REQ;
	volatile unsigned int BOOT_MODE0;
	volatile unsigned int BOOT_MODE1;
	volatile unsigned int SNVS_TAMPER0;
	volatile unsigned int SNVS_TAMPER1;
	volatile unsigned int SNVS_TAMPER2;
	volatile unsigned int SNVS_TAMPER3;
	volatile unsigned int SNVS_TAMPER4;
	volatile unsigned int SNVS_TAMPER5;
	volatile unsigned int SNVS_TAMPER6;
	volatile unsigned int SNVS_TAMPER7;
	volatile unsigned int SNVS_TAMPER8;
	volatile unsigned int SNVS_TAMPER9;
	volatile unsigned int JTAG_MOD;
	volatile unsigned int JTAG_TMS;
	volatile unsigned int JTAG_TDO;
	volatile unsigned int JTAG_TDI;
	volatile unsigned int JTAG_TCK;
	volatile unsigned int JTAG_TRST_B;
	volatile unsigned int GPIO1_IO00;
	volatile unsigned int GPIO1_IO01;
	volatile unsigned int GPIO1_IO02;
	volatile unsigned int GPIO1_IO03;
	volatile unsigned int GPIO1_IO04;
	volatile unsigned int GPIO1_IO05;
	volatile unsigned int GPIO1_IO06;
	volatile unsigned int GPIO1_IO07;
	volatile unsigned int GPIO1_IO08;
	volatile unsigned int GPIO1_IO09;
	volatile unsigned int UART1_TX_DATA;
	volatile unsigned int UART1_RX_DATA;
	volatile unsigned int UART1_CTS_B;
	volatile unsigned int UART1_RTS_B;
	volatile unsigned int UART2_TX_DATA;
	volatile unsigned int UART2_RX_DATA;
	volatile unsigned int UART2_CTS_B;
	volatile unsigned int UART2_RTS_B;
	volatile unsigned int UART3_TX_DATA;
	volatile unsigned int UART3_RX_DATA;
	volatile unsigned int UART3_CTS_B;
	volatile unsigned int UART3_RTS_B;
	volatile unsigned int UART4_TX_DATA;
	volatile unsigned int UART4_RX_DATA;
	volatile unsigned int UART5_TX_DATA;
	volatile unsigned int UART5_RX_DATA;
	volatile unsigned int ENET1_RX_DATA0;
	volatile unsigned int ENET1_RX_DATA1;
	volatile unsigned int ENET1_RX_EN;
	volatile unsigned int ENET1_TX_DATA0;
	volatile unsigned int ENET1_TX_DATA1;
	volatile unsigned int ENET1_TX_EN;
	volatile unsigned int ENET1_TX_CLK;
	volatile unsigned int ENET1_RX_ER;
	volatile unsigned int ENET2_RX_DATA0;
	volatile unsigned int ENET2_RX_DATA1;
	volatile unsigned int ENET2_RX_EN;
	volatile unsigned int ENET2_TX_DATA0;
	volatile unsigned int ENET2_TX_DATA1;
	volatile unsigned int ENET2_TX_EN;
	volatile unsigned int ENET2_TX_CLK;
	volatile unsigned int ENET2_RX_ER;
	volatile unsigned int LCD_CLK;
	volatile unsigned int LCD_ENABLE;
	volatile unsigned int LCD_HSYNC;
	volatile unsigned int LCD_VSYNC;
	volatile unsigned int LCD_RESET;
	volatile unsigned int LCD_DATA00;
	volatile unsigned int LCD_DATA01;
	volatile unsigned int LCD_DATA02;
	volatile unsigned int LCD_DATA03;
	volatile unsigned int LCD_DATA04;
	volatile unsigned int LCD_DATA05;
	volatile unsigned int LCD_DATA06;
	volatile unsigned int LCD_DATA07;
	volatile unsigned int LCD_DATA08;
	volatile unsigned int LCD_DATA09;
	volatile unsigned int LCD_DATA10;
	volatile unsigned int LCD_DATA11;
	volatile unsigned int LCD_DATA12;
	volatile unsigned int LCD_DATA13;
	volatile unsigned int LCD_DATA14;
	volatile unsigned int LCD_DATA15;
	volatile unsigned int LCD_DATA16;
	volatile unsigned int LCD_DATA17;
	volatile unsigned int LCD_DATA18;
	volatile unsigned int LCD_DATA19;
	volatile unsigned int LCD_DATA20;
	volatile unsigned int LCD_DATA21;
	volatile unsigned int LCD_DATA22;
	volatile unsigned int LCD_DATA23;
	volatile unsigned int NAND_RE_B;
	volatile unsigned int NAND_WE_B;
	volatile unsigned int NAND_DATA00;
	volatile unsigned int NAND_DATA01;
	volatile unsigned int NAND_DATA02;
	volatile unsigned int NAND_DATA03;
	volatile unsigned int NAND_DATA04;
	volatile unsigned int NAND_DATA05;
	volatile unsigned int NAND_DATA06;
	volatile unsigned int NAND_DATA07;
	volatile unsigned int NAND_ALE;
	volatile unsigned int NAND_WP_B;
	volatile unsigned int NAND_READY_B;
	volatile unsigned int NAND_CE0_B;
	volatile unsigned int NAND_CE1_B;
	volatile unsigned int NAND_CLE;
	volatile unsigned int NAND_DQS;
	volatile unsigned int SD1_CMD;
	volatile unsigned int SD1_CLK;
	volatile unsigned int SD1_DATA0;
	volatile unsigned int SD1_DATA1;
	volatile unsigned int SD1_DATA2;
	volatile unsigned int SD1_DATA3;
	volatile unsigned int CSI_MCLK;
	volatile unsigned int CSI_PIXCLK;
	volatile unsigned int CSI_VSYNC;
	volatile unsigned int CSI_HSYNC;
	volatile unsigned int CSI_DATA00;
	volatile unsigned int CSI_DATA01;
	volatile unsigned int CSI_DATA02;
	volatile unsigned int CSI_DATA03;
	volatile unsigned int CSI_DATA04;
	volatile unsigned int CSI_DATA05;                 
	volatile unsigned int CSI_DATA06;
	volatile unsigned int CSI_DATA07;
	volatile unsigned int GRP_ADDDS;
	volatile unsigned int GRP_DDRMODE_CTL;
	volatile unsigned int GRP_B0DS;
	volatile unsigned int GRP_DDRPK;
	volatile unsigned int GRP_CTLDS;
	volatile unsigned int GRP_B1DS;
	volatile unsigned int GRP_DDRHYS;
	volatile unsigned int GRP_DDRPKE;
	volatile unsigned int GRP_DDRMODE;
	volatile unsigned int GRP_DDR_TYPE;
}IOMUX_SW_PAD_Type;
// Original code
// #define SW_MUX_GPIO1_IO03 *((volatile unsigned int *)0x020E0068)
// #define SW_PAD_GPIO1_IO03 *((volatile unsigned int *)0x020E02F4)

// Define GPIO registers addresses
// #define GPIO1_DR *((volatile unsigned int *)0x0209C000)
// #define GPIO1_GDIR *((volatile unsigned int *)0x0209C004)
// #define GPIO1_PSR *((volatile unsigned int *)0x0209C008)
// #define GPIO1_ICR1 *((volatile unsigned int *)0x0209C00C)
// #define GPIO1_ICR2 *((volatile unsigned int *)0x0209C010)
// #define GPIO1_IMR *((volatile unsigned int *)0x0209C014)
// #define GPIO1_ISR *((volatile unsigned int *)0x0209C018)
// #define GPIO1_EDGE_SEL *((volatile unsigned int *)0x0209C01C)
typedef struct 
{
	volatile unsigned int DR;							
	volatile unsigned int GDIR; 							
	volatile unsigned int PSR;								
	volatile unsigned int ICR1; 							
	volatile unsigned int ICR2; 							 
	volatile unsigned int IMR;								 
	volatile unsigned int ISR;			
	volatile unsigned int EDGE_SEL;  
}GPIO_Type;

#define CCM_ANALOG			((CCM_ANALOG_Type *)CCM_ANALOG_BASE)
#define IOMUX_SW_MUX		((IOMUX_SW_MUX_Type *)IOMUX_SW_MUX_BASE)
#define IOMUX_SW_PAD		((IOMUX_SW_PAD_Type *)IOMUX_SW_PAD_BASE)
#define GPIO1				((GPIO_Type *)GPIO1_BASE)
#define GPIO2				((GPIO_Type *)GPIO2_BASE)
#define GPIO3				((GPIO_Type *)GPIO3_BASE)
#define GPIO4				((GPIO_Type *)GPIO4_BASE)
#define GPIO5				((GPIO_Type *)GPIO5_BASE)

#endif