#include "fsl_debug_console.h"
#include "fsl_flexcan.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"


#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "pin_mux.h"

#include "FlexCan_3.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define EXAMPLE_CAN CAN3

#define RX_MESSAGE_BUFFER_NUM (9)
#define TX_MESSAGE_BUFFER_NUM (8)
#define DLC                   (8)

/* Select OSC24Mhz as master flexcan clock source */
#define FLEXCAN_CLOCK_SOURCE_SELECT (1U)
/* Clock divider for master flexcan clock source */
#define FLEXCAN_CLOCK_SOURCE_DIVIDER (1U)
/* Get frequency of flexcan clock */
#define EXAMPLE_CAN_CLK_FREQ ((CLOCK_GetRootClockFreq(kCLOCK_Root_Can3) / 100000U) * 100000U)
/* Set USE_IMPROVED_TIMING_CONFIG macro to use api to calculates the improved CAN / CAN FD timing values. */
#define USE_IMPROVED_TIMING_CONFIG (1U)
/* Fix MISRA_C-2012 Rule 17.7. */
#define LOG_INFO (void)PRINTF
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
flexcan_handle_t flexcanHandle;
volatile bool txComplete = false;
volatile bool rxComplete = false;
volatile bool wakenUp    = false;
flexcan_mb_transfer_t txXfer, rxXfer;
#if (defined(USE_CANFD) && USE_CANFD)
flexcan_fd_frame_t frame;
#else
volatile flexcan_frame_t frame;
volatile flexcan_frame_t frame_RX;
//flexcan_frame_t frame;
//flexcan_frame_t frame_RX;

#endif
uint32_t txIdentifier;
uint32_t rxIdentifier;

status_t status_Can;

flexcan_config_t flexcanConfig;
flexcan_rx_mb_config_t mbConfig;
uint8_t node_type;

volatile uint32_t CAN_rx_Speed;

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief FlexCAN Call Back function
 */
//void(x)(CAN_Type * base, flexcan_handle_t * handle, status_t status, uint64_t result, void *userData)
static FLEXCAN_CALLBACK(flexcan_callback)
{
    switch (status)
    {
        case kStatus_FLEXCAN_RxIdle:
            if (RX_MESSAGE_BUFFER_NUM == result)
            {
    			FLexCAN_3_RX_Msg();
    			CAN_rx_Speed = frame_RX.dataByte0;
    			frame.dataByte0++;
    			if(frame.dataByte0== 250)
    			{
    				frame.dataByte0 = 0;
    			}
                rxComplete = true;
            }
            break;

        case kStatus_FLEXCAN_TxIdle:
            if (TX_MESSAGE_BUFFER_NUM == result)
            {
                txComplete = true;
            }
            break;

        case kStatus_FLEXCAN_WakeUp:
            wakenUp = true;
            break;

        default:
            break;
    }
}

void BOARD_InitPins_CAN(void)
{
	  IOMUXC_SetPinMux(
	      IOMUXC_GPIO_LPSR_00_FLEXCAN3_TX,        /* GPIO_LPSR_00 is configured as FLEXCAN3_TX */
	      1U);                                    /* Software Input On Field: Force input path of pad GPIO_LPSR_00 */
	  IOMUXC_SetPinMux(
	      IOMUXC_GPIO_LPSR_01_FLEXCAN3_RX,        /* GPIO_LPSR_01 is configured as FLEXCAN3_RX */
	      1U);                                    /* Software Input On Field: Force input path of pad GPIO_LPSR_01 */
	  IOMUXC_SetPinConfig(
	      IOMUXC_GPIO_LPSR_00_FLEXCAN3_TX,        /* GPIO_LPSR_00 PAD functional properties : */
	      0x02U);                                 /* Slew Rate Field: Slow Slew Rate
	                                                 Drive Strength Field: high driver
	                                                 Pull / Keep Select Field: Pull Disable
	                                                 Pull Up / Down Config. Field: Weak pull down
	                                                 Open Drain LPSR Field: Disabled
	                                                 Domain write protection: Both cores are allowed
	                                                 Domain write protection lock: Neither of DWP bits is locked */
	  IOMUXC_SetPinConfig(
	      IOMUXC_GPIO_LPSR_01_FLEXCAN3_RX,        /* GPIO_LPSR_01 PAD functional properties : */
	      0x02U);                                 /* Slew Rate Field: Slow Slew Rate
	                                                 Drive Strength Field: high driver
	                                                 Pull / Keep Select Field: Pull Disable
	                                                 Pull Up / Down Config. Field: Weak pull down
	                                                 Open Drain LPSR Field: Disabled
	                                                 Domain write protection: Both cores are allowed
	                                                 Domain write protection lock: Neither of DWP bits is locked */
}

void FLexCAN_3_Init(void)
{

    /*Clock setting for FLEXCAN*/
    clock_root_config_t rootCfg = {0};
    // kCLOCK_CAN3_ClockRoot_MuxOsc24MOut
    rootCfg.mux                 = FLEXCAN_CLOCK_SOURCE_SELECT;  // kCLOCK_CAN3_ClockRoot_MuxOsc24MOut
    rootCfg.div                 = FLEXCAN_CLOCK_SOURCE_DIVIDER;
    CLOCK_SetRootClock(kCLOCK_Root_Can3, &rootCfg);

    txIdentifier = 0x123;
    rxIdentifier = 0x321;
    /* Get FlexCAN module default Configuration. */
    /*
     * flexcanConfig.clkSrc                 = kFLEXCAN_ClkSrc0;
     * flexcanConfig.baudRate               = 1000000U;
     * flexcanConfig.baudRateFD             = 2000000U;
     * flexcanConfig.maxMbNum               = 16;
     * flexcanConfig.enableLoopBack         = false;
     * flexcanConfig.enableSelfWakeup       = false;
     * flexcanConfig.enableIndividMask      = false;
     * flexcanConfig.disableSelfReception   = false;
     * flexcanConfig.enableListenOnlyMode   = false;
     * flexcanConfig.enableDoze             = false;
     */
    FLEXCAN_GetDefaultConfig(&flexcanConfig);

#if defined(EXAMPLE_CAN_CLK_SOURCE)
    flexcanConfig.clkSrc = EXAMPLE_CAN_CLK_SOURCE;
#endif

/* If special quantum setting is needed, set the timing parameters. */
#if (defined(SET_CAN_QUANTUM) && SET_CAN_QUANTUM)
    flexcanConfig.timingConfig.phaseSeg1 = PSEG1;
    flexcanConfig.timingConfig.phaseSeg2 = PSEG2;
    flexcanConfig.timingConfig.propSeg   = PROPSEG;
#if (defined(FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE) && FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE)
    flexcanConfig.timingConfig.fphaseSeg1 = FPSEG1;
    flexcanConfig.timingConfig.fphaseSeg2 = FPSEG2;
    flexcanConfig.timingConfig.fpropSeg   = FPROPSEG;
#endif
#endif

#if (defined(USE_IMPROVED_TIMING_CONFIG) && USE_IMPROVED_TIMING_CONFIG)
    flexcan_timing_config_t timing_config;
    memset(&timing_config, 0, sizeof(flexcan_timing_config_t));
#if (defined(USE_CANFD) && USE_CANFD)
    if (FLEXCAN_FDCalculateImprovedTimingValues(EXAMPLE_CAN, flexcanConfig.baudRate, flexcanConfig.baudRateFD,
                                                EXAMPLE_CAN_CLK_FREQ, &timing_config))
    {
        /* Update the improved timing configuration*/
        memcpy(&(flexcanConfig.timingConfig), &timing_config, sizeof(flexcan_timing_config_t));
    }
    else
    {
        LOG_INFO("No found Improved Timing Configuration. Just used default configuration\r\n\r\n");
    }
#else
    if (FLEXCAN_CalculateImprovedTimingValues(EXAMPLE_CAN, flexcanConfig.baudRate, EXAMPLE_CAN_CLK_FREQ,
                                              &timing_config))
    {
        /* Update the improved timing configuration*/
        memcpy(&(flexcanConfig.timingConfig), &timing_config, sizeof(flexcan_timing_config_t));
    }
    else
    {
        LOG_INFO("No found Improved Timing Configuration. Just used default configuration\r\n\r\n");
    }
#endif
#endif

#if (defined(USE_CANFD) && USE_CANFD)
    FLEXCAN_FDInit(EXAMPLE_CAN, &flexcanConfig, EXAMPLE_CAN_CLK_FREQ, BYTES_IN_MB, true);
#else
    FLEXCAN_Init(EXAMPLE_CAN, &flexcanConfig, EXAMPLE_CAN_CLK_FREQ);
#endif

    /* Create FlexCAN handle structure and set call back function. */
    FLEXCAN_TransferCreateHandle(EXAMPLE_CAN, &flexcanHandle, flexcan_callback, NULL);

    /* Set Rx Masking mechanism. */
    FLEXCAN_SetRxMbGlobalMask(EXAMPLE_CAN, FLEXCAN_RX_MB_STD_MASK(rxIdentifier, 0, 0));

    /* Setup Rx Message Buffer. */
    mbConfig.format = kFLEXCAN_FrameFormatStandard;
    mbConfig.type   = kFLEXCAN_FrameTypeData;
    mbConfig.id     = FLEXCAN_ID_STD(rxIdentifier);
#if (defined(USE_CANFD) && USE_CANFD)
    FLEXCAN_SetFDRxMbConfig(EXAMPLE_CAN, RX_MESSAGE_BUFFER_NUM, &mbConfig, true);
#else
    FLEXCAN_SetRxMbConfig(EXAMPLE_CAN, RX_MESSAGE_BUFFER_NUM, &mbConfig, true);
#endif

/* Setup Tx Message Buffer. */
#if (defined(USE_CANFD) && USE_CANFD)
    FLEXCAN_SetFDTxMbConfig(EXAMPLE_CAN, TX_MESSAGE_BUFFER_NUM, true);
#else
    FLEXCAN_SetTxMbConfig(EXAMPLE_CAN, TX_MESSAGE_BUFFER_NUM, true);
#endif



}

void FLexCAN_3_TX_Msg(void)
{
    frame.id     = FLEXCAN_ID_STD(txIdentifier);
    frame.format = (uint8_t)kFLEXCAN_FrameFormatStandard;
    frame.type   = (uint8_t)kFLEXCAN_FrameTypeData;
    frame.length = (uint8_t)DLC;
#if (defined(USE_CANFD) && USE_CANFD)
    frame.brs = (uint8_t)1U;
#endif
    txXfer.mbIdx = (uint8_t)TX_MESSAGE_BUFFER_NUM;
#if (defined(USE_CANFD) && USE_CANFD)
    txXfer.framefd = &frame;
    (void)FLEXCAN_TransferFDSendNonBlocking(EXAMPLE_CAN, &flexcanHandle, &txXfer);
#else
    txXfer.frame = &frame;
    status_Can = FLEXCAN_TransferSendNonBlocking(EXAMPLE_CAN, &flexcanHandle, &txXfer);
#endif

//    while (!txComplete)
//    {
//    	__asm("nop");
//    };
//    txComplete = false;

}


void FLexCAN_3_RX_Msg(void)
{
	frame_RX.id     = FLEXCAN_ID_STD(txIdentifier);
	frame_RX.format = (uint8_t)kFLEXCAN_FrameFormatStandard;
	frame_RX.type   = (uint8_t)kFLEXCAN_FrameTypeData;
	frame_RX.length = (uint8_t)DLC;
#if (defined(USE_CANFD) && USE_CANFD)
	frame_RX.brs = (uint8_t)1U;
#endif
    /* Start receive data through Rx Message Buffer. */
    rxXfer.mbIdx = (uint8_t)RX_MESSAGE_BUFFER_NUM;
#if (defined(USE_CANFD) && USE_CANFD)
    rxXfer.framefd = &frame;
    (void)FLEXCAN_TransferFDReceiveNonBlocking(EXAMPLE_CAN, &flexcanHandle, &rxXfer);
#else
    rxXfer.frame = &frame_RX;
    (void)FLEXCAN_TransferReceiveNonBlocking(EXAMPLE_CAN, &flexcanHandle, &rxXfer);
#endif

//    /* Wait until Rx MB full. */
//    while (!rxComplete)
//    {
//    };
//    rxComplete = false;
}
