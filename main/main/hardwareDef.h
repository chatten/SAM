/*
 * hardwareDef.h
 *
 * Created: 2013-10-01 8:59:51 PM
 *  Author: Derek
 */ 

/*
 * Header file for the SAM4E Processor
 *
 * Defines registers and macros for use of the SAM4E processor.
 */
#include <stdint.h>
#include <sam4e16e.h>
 
#ifndef SAM4E_H
#define SAM4E_H
 
#define MCK			4000000 
 



#ifdef SAM4E_EK
#define GREEN_LED_PIN	21
#define BLUE_LED_PIN	00
#define AMBER_LED_PIN	20 
#define BP4_PIN			01
#endif

/* UART Controller *************************************************************/

// Register Offsets

#define UART_CR		(uint32_t)0x00000000
#define UART_MR		(uint32_t)0x00000004
#define UART_IER	(uint32_t)0x00000008
#define UART_IDR	(uint32_t)0x0000000C
#define UART_IMR	(uint32_t)0x00000010
#define UART_SR		(uint32_t)0x00000014
#define UART_RHR	(uint32_t)0x00000018
#define UART_THR	(uint32_t)0x0000001C
#define UART_BRGR	(uint32_t)0x00000020
#define UART_PTCR	(uint32_t)0x00000120




//UART_CR
#define	RSTRX		(1 << 2)
#define RSTTX		(1 << 3)
#define RXEN		(1 << 4)
#define RXDIS		(1 << 5)
#define TXEN		(1 << 6)
#define TXDIS		(1 << 7)

//UART_PTCR
#define TXTDIS		(1 << 9)
#define RXTDIS		(1 << 1)

//UART_SR
#define RXRDY		(1 << 0)
#define TXRDY		(1 << 1)
#define TXEMPTY		(1 << 9)


#define PID7		(1 << 7)	//UART0

#define PID9		(1 << 9)	//PIOA
#define PID10		(1 << 10)   //PIOB
#define PID11		(1 << 11)   //PIOC
#define PID12		(1 << 12)	//PIOD
#define PID13		(1 << 13)	//PIOE


 
// Watchdog Defines
#define WDT_MR *((uint32_t *)0x400E1854)
 
 
#endif