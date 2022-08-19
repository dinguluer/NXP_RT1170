#ifndef FLEX_CAN_3_H_
#define FLEX_CAN_3_H_

void BOARD_InitPins_CAN(void);

void FLexCAN_3_Init(void);

void FLexCAN_3_TX_Msg(void);

void FLexCAN_3_RX_Msg(void);

extern uint32_t txIdentifier;
extern uint32_t rxIdentifier;

#endif /* FLEX_CAN_3_H_ */


