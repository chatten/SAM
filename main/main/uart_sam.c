
/*******************************************************************************
*	Uart.c	     																*
*																				*
*			   		                 											*
*******************************************************************************/

#include "uart_sam.h"
#include "hardware.h"





/*******************************************************************************
*	hwUartConfig	     														*
*																				*
*			   		                 											*
*******************************************************************************/

void hwUartConfig(uartConfig_t *uartConfig)
{
	
	Pmc *pmc = PMC;
	
	//The UART pins are multiplexed with PIO lines. The programmer must first configure the corresponding PIO Controller to
	//enable I/O line operations of the UART.	
	

	/* Reset and disable receiver & transmitter */
			
	setReg(uartConfig->baseAddr +UART_IDR, 0x1FFF);					//disables uart interrupts

	setRegBit(uartConfig->baseAddr + UART_CR, RSTRX | RSTTX );		//reset uart
	setRegBit(uartConfig->baseAddr + UART_CR, TXDIS | RXDIS);		//disable uart

		//The UART clock is controllable through the Power Management Controller. In this case, the programmer must first
	//configure the PMC to enable the UART clock. Usually, the peripheral identifier used for this purpose is 1.
	//enable peripheral clock
	
	
	//TODO  FIX THIS
	setRegBit(pmc->PMC_PCER0, PID7 | PID10 | PID11 | PID12 | PID13);

	/* Disable PDC channel (Peripheral DMA Controller Channels) */
	setRegBit(uartConfig->baseAddr + UART_PTCR, TXTDIS | RXTDIS );
	

	
	//Baud Rate = MCK / (16 X CD)
	//*((uint32_t *)(uartConfig->baseAddr + UART_BRGR)) = (MCK/(16 * uartConfig->baudrate));
	//0x41 = 115200 & 1Mhz


	uint32_t cd = (MCK / uartConfig->baudrate) / 16;
	setReg(uartConfig->baseAddr + UART_BRGR, cd);
	setReg(uartConfig->baseAddr + UART_MR, 0x00000800 ); //Set for no parity

	
	//The transmitter is enabled
	//by writing the control register UART_CR with the bit TXEN at 1.
	clrRegBit(uartConfig->baseAddr + UART_CR, TXDIS | RXDIS);	
	clrRegBit(uartConfig->baseAddr + UART_CR, RSTRX | RSTTX);	

	setRegBit(uartConfig->baseAddr + UART_CR, TXEN | RXEN );

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

void hwUartPutChar(uint32_t baseAddr, uint8_t txData )
{
     	while((getReg(baseAddr  + UART_SR) &  TXEMPTY) == 0)
		;												//UART_THR = 1 = TX READY
		
			
    	setReg(baseAddr + UART_THR, txData);
}

/*******************************************************************************
*	hwUartGetChar																*
*																				*
*	Receives 1 character from UART												*
*																				*
*	returns 1 character															*
*******************************************************************************/
uint8_t hwUartGetChar(uint32_t baseAddr)
{
	while((getReg(baseAddr  + UART_SR) &  RXRDY) == 0)    //wait for byte
	;

	return getReg(baseAddr  + UART_RHR);                        
}


