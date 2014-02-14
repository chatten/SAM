/*******************************************************************************
*	uart.h     		                            						       *
*																			   *
*******************************************************************************/


#include "hardware.h"
#include "hardwareDef.h"


typedef struct {
	Uart * port;
	uint32_t baudrate;
	uint8_t echo;
	uint8_t stopBits;
	uint8_t enable;
}uartConfig_t;



void hwUartConfig(uartConfig_t *uartConfig);

void hwUartPutChar(Uart * uart, uint8_t txData);
uint8_t hwUartGetChar(Uart * uart);

