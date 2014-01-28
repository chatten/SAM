/*******************************************************************************
*	uart.h     		                            						       *
*																			   *
*******************************************************************************/


#include "hardware.h"
#include "hardwareDef.h"


typedef struct {
	uint32_t baseAddr;
	uint32_t baudrate;
	uint8_t echo;
	uint8_t stopBits;
	uint8_t enable;
}uartConfig_t;



void hwUartConfig(uartConfig_t *uartConfig);

void hwUartPutChar(uint32_t baseAddr, uint8_t txData);
uint8_t hwUartGetChar(uint32_t baseAddr);

