
/*******************************************************************************
*	uart_sam.c	     															*
*																				*
*			   		                 											*
*******************************************************************************/

#include "uart_sam.h"
#include "hardware.h"


/*******************************************************************************
*	hwUartConfig	     														*
*																				*
*										   		             					*
*******************************************************************************/

void hwUartConfig(uartConfig_t *uartConfig)
{
	
	Pmc *pmc = PMC;
	Uart *uart = uartConfig->port;
	
	//The UART pins are multiplexed with PIO lines. The programmer must first configure the corresponding PIO Controller to
	//enable I/O line operations of the UART.	
	

	/* Reset and disable receiver & transmitter */
							
	uart->UART_IDR |= 0x1FFF;					//disables uart interrupts
			
	uart->UART_CR |= (UART_CR_RSTRX | UART_CR_RSTTX);				//reset uart
	uart->UART_CR |= (UART_CR_TXDIS | UART_CR_RXDIS);

		//The UART clock is controllable through the Power Management Controller. In this case, the programmer must first
	//configure the PMC to enable the UART clock. Usually, the peripheral identifier used for this purpose is 1.
	//enable peripheral clock
	pmc->PMC_PCER0 |= (PMC_PCER0_PID7 | PMC_PCER0_PID10 | PMC_PCER0_PID11 | PMC_PCER0_PID12 | PMC_PCER0_PID13);

	/* Disable PDC channel (Peripheral DMA Controller Channels) */
	uart->UART_PTCR |= (UART_PTCR_TXTDIS | UART_PTCR_RXTDIS);

	
	//Baud Rate = MCK / (16 X CD)
	//*((uint32_t *)(uartConfig->baseAddr + UART_BRGR)) = (MCK/(16 * uartConfig->baudrate));
	//0x41 = 115200 & 1Mhz


	uint32_t cd = (MCK / uartConfig->baudrate) / 16;
	uart->UART_BRGR = cd;
	uart->UART_MR = 0x00000800;  //Set for no parity
	
	//The transmitter is enabled
	//by writing the control register UART_CR with the bit TXEN at 1.
	uart->UART_CR &= ~(UART_CR_TXDIS | UART_CR_RXDIS);	
	uart->UART_CR &= ~(UART_CR_RSTRX | UART_CR_RSTTX);

	uart->UART_CR |= (UART_CR_TXEN | UART_CR_RXEN);

	//the transmitter waits for a character
	//to be written in the Transmit Holding Register (UART_THR) before actually starting the transmission


}


/*******************************************************************************
*	hwUartPutChar																*
*																				*
*	Send 1 character over UART			   										*
*																				*
*	Returns Nothing																*
*******************************************************************************/

void hwUartPutChar(Uart * uart, uint8_t txData )
{
     	while((uart->UART_SR &  UART_SR_TXEMPTY) == 0)
		;												//UART_THR = 1 = TX READY		
		uart->UART_THR |= txData;	
}

/*******************************************************************************
*	hwUartGetChar																*
*																				*
*	Receives 1 character from UART												*
*																				*
*	returns 1 character															*
*******************************************************************************/
uint8_t hwUartGetChar(Uart *uart)
{
	while((uart->UART_SR &  UART_SR_RXRDY) == 0)    //wait for byte
	;

	return uart->UART_RHR;                        
}


