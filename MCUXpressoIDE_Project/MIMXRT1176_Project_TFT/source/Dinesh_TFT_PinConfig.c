#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "fsl_gpio.h"
#include "pin_mux.h"


/*
LCD_CLK   --> GPIO_DISP_B1_00
LCD_EN    --> GPIO_DISP_B1_01
LCD_HSYNC --> GPIO_DISP_B1_02
LCD_VSYNC --> GPIO_DISP_B1_03
LCD_B0    --> GPIO_DISP_B1_04
LCD_B1    --> GPIO_DISP_B1_05
LCD_B2    --> GPIO_DISP_B1_06
LCD_B3    --> GPIO_DISP_B1_07
LCD_B4    --> GPIO_DISP_B1_08
LCD_B5    --> GPIO_DISP_B1_09
LCD_B6    --> GPIO_DISP_B1_10
LCD_B7    --> GPIO_DISP_B1_11
LCD_G0    --> GPIO_DISP_B2_00
LCD_G1    --> GPIO_DISP_B2_01
LCD_G2    --> GPIO_DISP_B2_02
LCD_G3    --> GPIO_DISP_B2_03
LCD_G4    --> GPIO_DISP_B2_04
LCD_G5    --> GPIO_DISP_B2_05
LCD_G6    --> GPIO_DISP_B2_06
LCD_G7    --> GPIO_DISP_B2_07
LCD_R0    --> GPIO_DISP_B2_08
LCD_R1    --> GPIO_DISP_B2_09
LCD_R2    --> GPIO_DISP_B2_10
LCD_R3    --> GPIO_DISP_B2_11
LCD_R4    --> GPIO_DISP_B2_12
LCD_R5    --> GPIO_DISP_B2_13
LCD_R6    --> GPIO_DISP_B2_14
LCD_R7    --> GPIO_DISP_B2_15
 */
void BOARD_InitTFTPanelPins(void) {
	/*
	 IOMUXC_GPIO_AD_26_GPIO9_IO25 this means :---
	 Pad name is GPIO_AD_26 & Alternative function is GPIO9_IO25
	 GPIO9_IO25, means :--
	 Port Name GPIO9 and pin name is IO25
	*/

	//LCD_CLK   --> GPIO_DISP_B1_00
	IOMUXC_SetPinMux(
			IOMUXC_GPIO_DISP_B1_00_VIDEO_MUX_LCDIF_CLK,           /* Pad GPIO_DISP_B1_00 is configured as VIDEO_MUX_LCDIF_CLK */
			0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_CLK */

	//LCD_EN    --> GPIO_DISP_B1_01
	IOMUXC_SetPinMux(
			IOMUXC_GPIO_DISP_B1_01_VIDEO_MUX_LCDIF_ENABLE,           /* Pad GPIO_DISP_B1_01 is configured as VIDEO_MUX_LCDIF_ENABLE */
			0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_ENABLE */

	//LCD_HSYNC --> GPIO_DISP_B1_02
	IOMUXC_SetPinMux(
			IOMUXC_GPIO_DISP_B1_02_VIDEO_MUX_LCDIF_HSYNC,           /* Pad GPIO_DISP_B1_02 is configured as VIDEO_MUX_LCDIF_HSYNC */
			0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_HSYNC */

	//LCD_VSYNC --> GPIO_DISP_B1_03
	IOMUXC_SetPinMux(
			IOMUXC_GPIO_DISP_B1_03_VIDEO_MUX_LCDIF_VSYNC,           /* Pad GPIO_DISP_B1_03 is configured as VIDEO_MUX_LCDIF_VSYNC */
			0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_VSYNC */

	//LCD_B0    --> GPIO_DISP_B1_04
	IOMUXC_SetPinMux(
			IOMUXC_GPIO_DISP_B1_04_VIDEO_MUX_LCDIF_DATA00,           /* Pad GPIO_DISP_B1_04 is configured as VIDEO_MUX_LCDIF_DATA00 */
			0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA00 */

	//LCD_B1    --> GPIO_DISP_B1_05
	IOMUXC_SetPinMux(
			IOMUXC_GPIO_DISP_B1_05_VIDEO_MUX_LCDIF_DATA01,           /* Pad GPIO_DISP_B1_05 is configured as VIDEO_MUX_LCDIF_DATA01 */
			0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA01 */

	//LCD_B2    --> GPIO_DISP_B1_06
	IOMUXC_SetPinMux(
			IOMUXC_GPIO_DISP_B1_06_VIDEO_MUX_LCDIF_DATA02,           /* Pad GPIO_DISP_B1_06 is configured as VIDEO_MUX_LCDIF_DATA02 */
			0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA02 */

	//LCD_B3    --> GPIO_DISP_B1_07
	IOMUXC_SetPinMux(
			IOMUXC_GPIO_DISP_B1_07_VIDEO_MUX_LCDIF_DATA03,           /* Pad GPIO_DISP_B1_07 is configured as VIDEO_MUX_LCDIF_DATA03 */
			0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA03 */

	//LCD_B4    --> GPIO_DISP_B1_08
	IOMUXC_SetPinMux(
			IOMUXC_GPIO_DISP_B1_08_VIDEO_MUX_LCDIF_DATA04,           /* Pad GPIO_DISP_B1_08 is configured as VIDEO_MUX_LCDIF_DATA04 */
			0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA04 */

	//LCD_B5    --> GPIO_DISP_B1_09
	IOMUXC_SetPinMux(
			IOMUXC_GPIO_DISP_B1_09_VIDEO_MUX_LCDIF_DATA05,           /* Pad GPIO_DISP_B1_09 is configured as VIDEO_MUX_LCDIF_DATA05 */
			0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA05 */

	//LCD_B6    --> GPIO_DISP_B1_10
	IOMUXC_SetPinMux(
			IOMUXC_GPIO_DISP_B1_10_VIDEO_MUX_LCDIF_DATA06,           /* Pad GPIO_DISP_B1_10 is configured as VIDEO_MUX_LCDIF_DATA06 */
			0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA06 */

	//LCD_B7    --> GPIO_DISP_B1_11
	IOMUXC_SetPinMux(
			IOMUXC_GPIO_DISP_B1_11_VIDEO_MUX_LCDIF_DATA07,           /* Pad GPIO_DISP_B1_11 is configured as VIDEO_MUX_LCDIF_DATA07 */
			0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA07 */

	//LCD_G0    --> GPIO_DISP_B2_00
	IOMUXC_SetPinMux(
			IOMUXC_GPIO_DISP_B2_00_VIDEO_MUX_LCDIF_DATA08,           /* Pad GPIO_DISP_B2_00 is configured as VIDEO_MUX_LCDIF_DATA08 */
			0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA08 */

	//LCD_G1    --> GPIO_DISP_B2_01
	IOMUXC_SetPinMux(
			IOMUXC_GPIO_DISP_B2_01_VIDEO_MUX_LCDIF_DATA09,           /* Pad GPIO_DISP_B2_01 is configured as VIDEO_MUX_LCDIF_DATA09 */
			0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA09 */

	//LCD_G2    --> GPIO_DISP_B2_02
	IOMUXC_SetPinMux(
			IOMUXC_GPIO_DISP_B2_02_VIDEO_MUX_LCDIF_DATA10,           /* Pad GPIO_DISP_B2_02 is configured as VIDEO_MUX_LCDIF_DATA10 */
			0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA10 */

	//LCD_G3    --> GPIO_DISP_B2_03
	IOMUXC_SetPinMux(
			IOMUXC_GPIO_DISP_B2_03_VIDEO_MUX_LCDIF_DATA11,           /* Pad GPIO_DISP_B2_03 is configured as VIDEO_MUX_LCDIF_DATA11 */
			0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA11 */

	//LCD_G4    --> GPIO_DISP_B2_04
	IOMUXC_SetPinMux(
				IOMUXC_GPIO_DISP_B2_04_VIDEO_MUX_LCDIF_DATA12,           /* Pad GPIO_DISP_B2_04 is configured as VIDEO_MUX_LCDIF_DATA12 */
				0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA12 */

	//LCD_G5    --> GPIO_DISP_B2_05
	IOMUXC_SetPinMux(
				IOMUXC_GPIO_DISP_B2_05_VIDEO_MUX_LCDIF_DATA13,           /* Pad GPIO_DISP_B2_05 is configured as VIDEO_MUX_LCDIF_DATA13 */
				0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA13 */

	//LCD_G6    --> GPIO_DISP_B2_06
	IOMUXC_SetPinMux(
					IOMUXC_GPIO_DISP_B2_06_VIDEO_MUX_LCDIF_DATA14,           /* Pad GPIO_DISP_B2_06 is configured as VIDEO_MUX_LCDIF_DATA14 */
					0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA14 */

	//LCD_G7    --> GPIO_DISP_B2_07
	IOMUXC_SetPinMux(
					IOMUXC_GPIO_DISP_B2_07_VIDEO_MUX_LCDIF_DATA15,           /* Pad GPIO_DISP_B2_07 is configured as VIDEO_MUX_LCDIF_DATA15 */
					0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA15 */

	//LCD_R0    --> GPIO_DISP_B2_08
	IOMUXC_SetPinMux(
					IOMUXC_GPIO_DISP_B2_08_VIDEO_MUX_LCDIF_DATA16,           /* Pad GPIO_DISP_B2_08 is configured as VIDEO_MUX_LCDIF_DATA16 */
					0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA16 */

	// LCD_R1    --> GPIO_DISP_B2_09
	IOMUXC_SetPinMux(
					IOMUXC_GPIO_DISP_B2_09_VIDEO_MUX_LCDIF_DATA17,           /* Pad GPIO_DISP_B2_09 is configured as VIDEO_MUX_LCDIF_DATA17 */
					0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA17 */

	//LCD_R2    --> GPIO_DISP_B2_10
	IOMUXC_SetPinMux(
					IOMUXC_GPIO_DISP_B2_10_VIDEO_MUX_LCDIF_DATA18,           /* Pad GPIO_DISP_B2_10 is configured as VIDEO_MUX_LCDIF_DATA18 */
					0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA18 */

	//LCD_R3    --> GPIO_DISP_B2_11
	IOMUXC_SetPinMux(
					IOMUXC_GPIO_DISP_B2_11_VIDEO_MUX_LCDIF_DATA19,           /* Pad GPIO_DISP_B2_11 is configured as VIDEO_MUX_LCDIF_DATA19 */
					0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA19 */

	//LCD_R4    --> GPIO_DISP_B2_12
	IOMUXC_SetPinMux(
					IOMUXC_GPIO_DISP_B2_12_VIDEO_MUX_LCDIF_DATA20,           /* Pad GPIO_DISP_B2_12 is configured as VIDEO_MUX_LCDIF_DATA20 */
					0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA20 */

	//LCD_R5    --> GPIO_DISP_B2_13
	IOMUXC_SetPinMux(
					IOMUXC_GPIO_DISP_B2_13_VIDEO_MUX_LCDIF_DATA21,           /* Pad GPIO_DISP_B2_13 is configured as VIDEO_MUX_LCDIF_DATA21 */
					0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA21 */

	//LCD_R6    --> GPIO_DISP_B2_14
	IOMUXC_SetPinMux(
					IOMUXC_GPIO_DISP_B2_14_VIDEO_MUX_LCDIF_DATA22,           /* Pad GPIO_DISP_B2_14 is configured as VIDEO_MUX_LCDIF_DATA22 */
					0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA22 */

	//LCD_R7    --> GPIO_DISP_B2_15
	IOMUXC_SetPinMux(
					IOMUXC_GPIO_DISP_B2_15_VIDEO_MUX_LCDIF_DATA23,           /* Pad GPIO_DISP_B2_15 is configured as VIDEO_MUX_LCDIF_DATA23 */
					0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad VIDEO_MUX_LCDIF_DATA23 */
}

// Set : LCD_LR, LCD_UD, LCD_RESET, LCD_STDBY
void BOARD_InitTFTPanel_Support_Pins(void) {
	/*
	 IOMUXC_GPIO_AD_26_GPIO9_IO25 this means :---
	 Pad name is GPIO_AD_26 & Alternative function is GPIO9_IO25
	 GPIO9_IO25, means :--
	 Port Name GPIO9 and pin name is IO25
	*/

	// LCD_LR  --> GPIO_EMC_B2_19     // ------->  When L/R=’1’, set left to right scan direction.
	IOMUXC_SetPinMux(
			IOMUXC_GPIO_EMC_B2_19_GPIO8_IO29,           /* PAD GPIO_EMC_B2_19 is configured as GPIO8_IO29 */
			0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad GPIO8_IO29 */
	//sets the --> SW_PAD_CTL_PAD_TEST_MODE_DIG SW PAD Control Register
	IOMUXC_SetPinConfig(
			IOMUXC_GPIO_EMC_B2_19_GPIO8_IO29,           /* PAD GPIO8_IO29 PAD functional properties : */
			0x00U);                                 /* Slew Rate Field: Slow Slew Rate
		                                                 Drive Strength Field: normal drive strength
		                                                 Pull / Keep Select Field: Pull Disable, Highz
		                                                 Pull Up / Down Config. Field: Weak pull down
		                                                 Open Drain Field: Disabled
		                                                 Domain write protection: Both cores are allowed
		                                                 Domain write protection lock: Neither of DWP bits is locked */
    gpio_pin_config_t pinConfig_LCD_LR = {kGPIO_DigitalOutput, 0, kGPIO_NoIntmode};
	GPIO_PinInit(GPIO8, 29, &pinConfig_LCD_LR);
	// set pin high
	GPIO_PinWrite(GPIO8, 29, 0x01U);



	// LCD_UD  --> GPIO_EMC_B2_20     // ------->  When U/D=’0’, set top to bottom scan direction
	IOMUXC_SetPinMux(
			IOMUXC_GPIO_EMC_B2_20_GPIO8_IO30,           /* GPIO_EMC_B2_20 is configured as GPIO8_IO30 */
			0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad GPIO8_IO30 */
	//sets the --> SW_PAD_CTL_PAD_TEST_MODE_DIG SW PAD Control Register
	IOMUXC_SetPinConfig(
			IOMUXC_GPIO_EMC_B2_20_GPIO8_IO30,           /* GPIO8_IO30 PAD functional properties : */
			0x00U);                                 /* Slew Rate Field: Slow Slew Rate
				                                                 Drive Strength Field: normal drive strength
				                                                 Pull / Keep Select Field: Pull Disable, Highz
				                                                 Pull Up / Down Config. Field: Weak pull down
				                                                 Open Drain Field: Disabled
				                                                 Domain write protection: Both cores are allowed
				                                                 Domain write protection lock: Neither of DWP bits is locked */
    gpio_pin_config_t pinConfig_LCD_UD = {kGPIO_DigitalOutput, 0, kGPIO_NoIntmode};
	GPIO_PinInit(GPIO8, 30, &pinConfig_LCD_UD);
	// set pin LOW
	GPIO_PinWrite(GPIO8, 30, 0x00U);



	// LCD_RESET --> GPIO_AD_17       // ------->  H : normal operation   ,  L : reset state
	IOMUXC_SetPinMux(
			IOMUXC_GPIO_AD_17_GPIO9_IO16,           /* GPIO_AD_17 is configured as GPIO9_IO16 */
			0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad GPIO9_IO16 */
	//sets the --> SW_PAD_CTL_PAD_TEST_MODE_DIG SW PAD Control Register
	IOMUXC_SetPinConfig(
			IOMUXC_GPIO_AD_17_GPIO9_IO16,           /* GPIO9_IO16 PAD functional properties : */
			0x00U);                                 /* Slew Rate Field: Slow Slew Rate
				                                                 Drive Strength Field: normal drive strength
				                                                 Pull / Keep Select Field: Pull Disable, Highz
				                                                 Pull Up / Down Config. Field: Weak pull down
				                                                 Open Drain Field: Disabled
				                                                 Domain write protection: Both cores are allowed
				                                                 Domain write protection lock: Neither of DWP bits is locked */
    gpio_pin_config_t pinConfig_LCD_RESET = {kGPIO_DigitalOutput, 0, kGPIO_NoIntmode};
	GPIO_PinInit(GPIO9, 16, &pinConfig_LCD_RESET);
	// set pin high
	GPIO_PinWrite(GPIO9, 16, 0x01U);



	// LCD_STDBY --> GPIO_AD_19       // ------->  H : normal operation   ,  L : TCON, SD, power circuit and temp sensor will turn off
	IOMUXC_SetPinMux(
			IOMUXC_GPIO_AD_19_GPIO9_IO18,           /* GPIO_AD_19 is configured as GPIO9_IO18 */
			0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad GPIO9_IO18 */
	//sets the --> SW_PAD_CTL_PAD_TEST_MODE_DIG SW PAD Control Register
	IOMUXC_SetPinConfig(
			IOMUXC_GPIO_AD_19_GPIO9_IO18,           /* GPIO_AD_19 PAD functional properties : */
			0x00U);                                 /* Slew Rate Field: Slow Slew Rate
				                                                 Drive Strength Field: normal drive strength
				                                                 Pull / Keep Select Field: Pull Disable, Highz
				                                                 Pull Up / Down Config. Field: Weak pull down
				                                                 Open Drain Field: Disabled
				                                                 Domain write protection: Both cores are allowed
				                                                 Domain write protection lock: Neither of DWP bits is locked */
    gpio_pin_config_t pinConfig_LCD_STDBY = {kGPIO_DigitalOutput, 0, kGPIO_NoIntmode};
	GPIO_PinInit(GPIO9, 18, &pinConfig_LCD_STDBY);
	// set pin high
	GPIO_PinWrite(GPIO9, 18, 0x01U);

		  /*
		  LCD_LR  --> GPIO_EMC_B2_19     // ------->  When L/R=’1’, set left to right scan direction.
		  LCD_UD  --> GPIO_EMC_B2_20     // ------->  When U/D=’0’, set top to bottom scan direction
		  LCD_RESET --> GPIO_AD_17       // ------->  H : normal operation   ,  L : reset state
		  LCD_STDBY --> GPIO_AD_19       // ------->  H : normal operation   ,  L : TCON, SD, power circuit and temp sensor will turn off
		   */


		  // ----> COntrolled directly by ---> eLCDIF
		  // LCD_EN --> GPIO_DISP_B1_01     // ------->  pin-16 of TFT  :          DE : Data enable signal (DE) for DE mode or latch signal (LD) for source driver mode
}


///////////////////// Dinesh ///////////////////////
void DEMO_InitLcdBackLight(void)
{
//    const gpio_pin_config_t config = {
//        kGPIO_DigitalOutput,
//        1,
//        kGPIO_NoIntmode,
//    };
//
//    /* Backlight. */
//    GPIO_PinInit(LCD_BL_GPIO, LCD_BL_GPIO_PIN, &config);


// --------------------- Back light --------------------/
	/*
	 IOMUXC_GPIO_AD_26_GPIO9_IO25 this means :---
	 Pad name is GPIO_AD_26 & Alternative function is GPIO9_IO25
	 GPIO9_IO25, means :--
	 Port Name GPIO9 and pin name is IO25
	*/

	/* GPIO_AD_26 is configured as GPIO9_IO25*/
	  IOMUXC_SetPinMux(
			  IOMUXC_GPIO_AD_26_GPIO9_IO25,           /* GPIO_AD_26 is configured as GPIO9_IO25 */
	      0U);                                    /* Software Input On Field: 0b0..Input Path is determined by functionality of pad GPIO_AD_26 */
	  //sets the --> SW_PAD_CTL_PAD_TEST_MODE_DIG SW PAD Control Register
	  IOMUXC_SetPinConfig(
			  IOMUXC_GPIO_AD_26_GPIO9_IO25,           /* GPIO_AD_26 PAD functional properties : */
	      0x00U);                                 /* Slew Rate Field: Slow Slew Rate
	                                                 Drive Strength Field: normal drive strength
	                                                 Pull / Keep Select Field: Pull Disable, Highz
	                                                 Pull Up / Down Config. Field: Weak pull down
	                                                 Open Drain Field: Disabled
	                                                 Domain write protection: Both cores are allowed
	                                                 Domain write protection lock: Neither of DWP bits is locked */
      gpio_pin_config_t pinConfig = {kGPIO_DigitalOutput, 0, kGPIO_NoIntmode};
	  GPIO_PinInit(GPIO9, 25, &pinConfig);
	  // set pin high
	  GPIO_PinWrite(GPIO9, 25, 0x01U);

	  /*
	  LCD_LR  --> GPIO_EMC_B2_19     // ------->  When L/R=’1’, set left to right scan direction.
	  LCD_UD  --> GPIO_EMC_B2_20     // ------->  When U/D=’0’, set top to bottom scan direction
	  LCD_RESET --> GPIO_AD_17       // ------->  H : normal operation   ,  L : reset state
	  LCD_STDBY --> GPIO_AD_19       // ------->  H : normal operation   ,  L : TCON, SD, power circuit and temp sensor will turn off
	   */


	  // ----> COntrolled directly by ---> eLCDIF
	  // LCD_EN --> GPIO_DISP_B1_01     // ------->  pin-16 of TFT  :          DE : Data enable signal (DE) for DE mode or latch signal (LD) for source driver mode

}

//============================= Dinesh ==================

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
