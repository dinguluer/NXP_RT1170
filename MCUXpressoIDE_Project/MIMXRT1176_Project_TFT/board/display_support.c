/*
 * Copyright 2019-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "display_support.h"
#include "fsl_gpio.h"
#include "pin_mux.h"
#include "board.h"
#include "fsl_debug_console.h"

#if (DEMO_DISPLAY_CONTROLLER == DEMO_DISPLAY_CONTROLLER_LCDIFV2)
#include "fsl_dc_fb_lcdifv2.h"
#else
#include "fsl_dc_fb_elcdif.h"
#endif

// Dinesh added
#include "lvgl_support.h"

//dinesh added
#include "Dinesh_TFT_PinConfig.h"
#include "display_support.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

//======================================= Dinesh =========================

/* Macros for panel. */
#define LCD_HSW 48
#define LCD_HFP 40
#define LCD_HBP 40
#define LCD_VSW 1
#define LCD_VFP 13
#define LCD_VBP 31
#define LCD_POL_FLAGS \
    (kELCDIF_DataEnableActiveHigh | kELCDIF_VsyncActiveLow | kELCDIF_HsyncActiveLow | kELCDIF_DriveDataOnRisingClkEdge)
#define LCD_LCDIF_DATA_BUS kELCDIF_DataBus24Bit

//======================================= Dinesh =========================

/*
 * DEMO_PANEL_TRUELY_800_480 panel
 */

#if (DEMO_PANEL_TRUELY_800_480 == DEMO_PANEL)

#define DEMO_HSW LCD_HSW
#define DEMO_HFP LCD_HFP
#define DEMO_HBP LCD_HBP
#define DEMO_VSW LCD_VSW
#define DEMO_VFP LCD_VFP
#define DEMO_VBP LCD_VBP

#endif

#if (DEMO_DISPLAY_CONTROLLER == DEMO_DISPLAY_CONTROLLER_LCDIFV2)

#define DEMO_LCDIF_POL_FLAGS                                                             \
    (kLCDIFV2_DataEnableActiveHigh | kLCDIFV2_VsyncActiveLow | kLCDIFV2_HsyncActiveLow | \
     kLCDIFV2_DriveDataOnFallingClkEdge)

#define DEMO_LCDIF LCDIFV2

#else

#define DEMO_LCDIF_POL_FLAGS \
    (kELCDIF_DataEnableActiveHigh | kELCDIF_VsyncActiveLow | kELCDIF_HsyncActiveLow | kELCDIF_DriveDataOnFallingClkEdge)

#define DEMO_LCDIF LCDIF

#endif


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

static void BOARD_InitLcdifClock(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/

static uint32_t TftDpiClkFreq_Hz;

#if (DEMO_DISPLAY_CONTROLLER == DEMO_DISPLAY_CONTROLLER_LCDIFV2)

static dc_fb_lcdifv2_handle_t s_dcFbLcdifv2Handle = {0};

static const dc_fb_lcdifv2_config_t s_dcFbLcdifv2Config = {
    .lcdifv2       = DEMO_LCDIF,
    .width         = DEMO_PANEL_WIDTH,
    .height        = DEMO_PANEL_HEIGHT,
    .hsw           = DEMO_HSW,
    .hfp           = DEMO_HFP,
    .hbp           = DEMO_HBP,
    .vsw           = DEMO_VSW,
    .vfp           = DEMO_VFP,
    .vbp           = DEMO_VBP,
    .polarityFlags = DEMO_LCDIF_POL_FLAGS,
    .lineOrder     = kLCDIFV2_LineOrderRGB,
/* CM4 is domain 1, CM7 is domain 0. */
#if (__CORTEX_M <= 4)
    .domain = 1,
#else
    .domain = 0,
#endif
};

const dc_fb_t g_dc = {
    .ops     = &g_dcFbOpsLcdifv2,
    .prvData = &s_dcFbLcdifv2Handle,
    .config  = &s_dcFbLcdifv2Config,
};

#else

dc_fb_elcdif_handle_t s_dcFbElcdifHandle = {0}; /* The handle must be initialized to 0. */

const dc_fb_elcdif_config_t s_dcFbElcdifConfig = {
    .elcdif        = DEMO_LCDIF,
    .width         = DEMO_PANEL_WIDTH,
    .height        = DEMO_PANEL_HEIGHT,
    .hsw           = DEMO_HSW,
    .hfp           = DEMO_HFP,
    .hbp           = DEMO_HBP,
    .vsw           = DEMO_VSW,
    .vfp           = DEMO_VFP,
    .vbp           = DEMO_VBP,
    .polarityFlags = DEMO_LCDIF_POL_FLAGS,
    .dataBus       = kELCDIF_DataBus24Bit,
};

const dc_fb_t g_dc = {
    .ops     = &g_dcFbOpsElcdif,
    .prvData = &s_dcFbElcdifHandle,
    .config  = &s_dcFbElcdifConfig,
};
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/
static void BOARD_InitLcdifClock(void)
{
    /*
     * The pixel clock is (height + VSW + VFP + VBP) * (width + HSW + HFP + HBP) * frame rate.
     *
     * For 60Hz frame rate, the RK055IQH091 pixel clock should be 36MHz.
     * the RK055AHD091 pixel clock should be 62MHz.
     * For 60Hz frame rate, the DEMO_PANEL_TRUELY_800_480 pixel clock should be 36MHz.
     * the RK055AHD091 pixel clock should be 62MHz.
     */
	// DEMO_PANEL_TRUELY_800_480
    const clock_root_config_t lcdifClockConfig = {
        .clockOff = false,
		.mux      = kCLOCK_LCDIF_ClockRoot_MuxVideoPllOut /*7*/, /*!< 984 MHZ. */
		.div = 33,
    };

    CLOCK_SetRootClock(kCLOCK_Root_Lcdif, &lcdifClockConfig);
   	TftDpiClkFreq_Hz = CLOCK_GetRootClockFreq(kCLOCK_Root_Lcdif);
}


#if (DEMO_DISPLAY_CONTROLLER == DEMO_DISPLAY_CONTROLLER_LCDIFV2)
void LCDIFv2_IRQHandler(void)
{
    DC_FB_LCDIFV2_IRQHandler(&g_dc);
}
#else
void eLCDIF_IRQHandler(void)
{
    DC_FB_ELCDIF_IRQHandler(&g_dc);
}
#endif

status_t BOARD_VerifyDisplayClockSource(void)
{
    status_t status;
    uint32_t srcClkFreq;

    /*
     * In this implementation, the SYSPLL2 (528M) clock is used as the source
     * of LCDIFV2 pixel clock and MIPI DSI ESC clock. The OSC24M clock is used
     * as the MIPI DSI DPHY PLL reference clock. This function checks the clock
     * source are valid. OSC24M is always valid, so only verify the SYSPLL2.
     */
    srcClkFreq = CLOCK_GetPllFreq(kCLOCK_PllSys2);
    if (528 != (srcClkFreq / 1000000))
    {
        status = kStatus_Fail;
    }
    else
    {
        status = kStatus_Success;
    }

    return status;
}

/* Configure the panel : pins. */
void BOARD_InitLcdPanel_tft(void)
{
	//    /* Backlight. */
	DEMO_InitLcdBackLight();
	// Set : LCD_LR, LCD_UD, LCD_RESET, LCD_STDBY
	BOARD_InitTFTPanel_Support_Pins();

}


status_t BOARD_InitDisplayInterface_TFT(void)
{
    CLOCK_EnableClock(kCLOCK_Video_Mux);

#if (DEMO_DISPLAY_CONTROLLER == DEMO_DISPLAY_CONTROLLER_LCDIFV2)
    /* LCDIF v2 output to RGB LCD. */
    VIDEO_MUX->VID_MUX_CTRL.SET = VIDEO_MUX_VID_MUX_CTRL_PARA_LCD_SEL_MASK;
#else
    /* ELCDIF output to RGB LCD. */
    VIDEO_MUX->VID_MUX_CTRL.CLR = VIDEO_MUX_VID_MUX_CTRL_PARA_LCD_SEL_MASK;
#endif

    /* Configure the panel : pins. */
    BOARD_InitLcdPanel_tft();

    return kStatus_Success;
}

status_t BOARD_PrepareDisplayController(void)
{
    status_t status;

    status = BOARD_VerifyDisplayClockSource();

    if (status != kStatus_Success)
    {
        PRINTF("Error: Invalid display clock source.\r\n");
        return status;
    }

    BOARD_InitLcdifClock();

    status = BOARD_InitDisplayInterface_TFT();

    if (kStatus_Success == status)
    {
#if (DEMO_DISPLAY_CONTROLLER == DEMO_DISPLAY_CONTROLLER_LCDIFV2)
        NVIC_ClearPendingIRQ(LCDIFv2_IRQn);
        NVIC_SetPriority(LCDIFv2_IRQn, 3);
        EnableIRQ(LCDIFv2_IRQn);
#else
        NVIC_ClearPendingIRQ(eLCDIF_IRQn);
        NVIC_SetPriority(eLCDIF_IRQn, 3);
        EnableIRQ(eLCDIF_IRQn);
#endif
    }

    return kStatus_Success;
}
