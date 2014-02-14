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
 
/* PIO Controller *************************************************************/
 


// Register Offsets
/*
#define PIO_PER     (uint32_t)0x00000000
#define PIO_PDR     (uint32_t)0x00000004
#define PIO_PSR     (uint32_t)0x00000008
#define PIO_OER     (uint32_t)0x00000010
#define PIO_ODR     (uint32_t)0x00000014
#define PIO_OSR     (uint32_t)0x00000018
#define PIO_IFER    (uint32_t)0x00000020
#define PIO_IFDR    (uint32_t)0x00000024
#define PIO_IFSR    (uint32_t)0x00000028
#define PIO_SODR    (uint32_t)0x00000030
#define PIO_CODR    (uint32_t)0x00000034
#define PIO_ODSR    (uint32_t)0x00000038
#define PIO_PDSR    (uint32_t)0x0000003C
#define PIO_IER     (uint32_t)0x00000040
#define PIO_IDR     (uint32_t)0x00000044
#define PIO_IMR     (uint32_t)0x00000048
#define PIO_ISR     (uint32_t)0x0000004C
#define PIO_MDER    (uint32_t)0x00000050
#define PIO_MDDR    (uint32_t)0x00000054
#define PIO_MDSR    (uint32_t)0x00000058
#define PIO_PUDR    (uint32_t)0x00000060
#define PIO_PUER    (uint32_t)0x00000064
#define PIO_PUSR    (uint32_t)0x00000068
#define PIO_ABCDSR1 (uint32_t)0x00000070
#define PIO_ABCDSR2 (uint32_t)0x00000074
#define PIO_IFSCDR  (uint32_t)0x00000080
#define PIO_IFSCER  (uint32_t)0x00000084
#define PIO_IFSCSR  (uint32_t)0x00000088
#define PIO_SCDR    (uint32_t)0x0000008C
#define PIO_PPDDR   (uint32_t)0x00000090
#define PIO_PPDER   (uint32_t)0x00000094
#define PIO_PPDSR   (uint32_t)0x00000098
#define PIO_OWER    (uint32_t)0x000000A0
#define PIO_OWDR    (uint32_t)0x000000A4
#define PIO_OWSR    (uint32_t)0x000000A8
#define PIO_AIMER   (uint32_t)0x000000B0
#define PIO_AIMDR   (uint32_t)0x000000B4
#define PIO_AIMMR   (uint32_t)0x000000B8
#define PIO_ESR     (uint32_t)0x000000C0
#define PIO_LSR     (uint32_t)0x000000C4
#define PIO_ELSR    (uint32_t)0x000000C8
#define PIO_FELLSR  (uint32_t)0x000000D0
#define PIO_REHLSR  (uint32_t)0x000000D4
#define PIO_FRLHSR  (uint32_t)0x000000D8
#define PIO_LOCKSR  (uint32_t)0x000000E0
#define PIO_WPMR    (uint32_t)0x000000E4
#define PIO_WPSR    (uint32_t)0x000000E8
#define PIO_SCHMITT (uint32_t)0x00000100
#define PIO_DELAYR  (uint32_t)0x00000110
#define PIO_PCMR    (uint32_t)0x00000150
#define PIO_PCIER   (uint32_t)0x00000154
#define PIO_PCIDR   (uint32_t)0x00000158
#define PIO_PCIMR   (uint32_t)0x0000015C
#define PIO_PCISR   (uint32_t)0x00000160
#define PIO_PCRHR   (uint32_t)0x00000164
*/

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

/*
 * Sets a PIO register given a bank, an offset and a new value
 */
#define pio_set_register(bank, offset, value) {(*(uint32_t *)(bank + offset)) = value;}
 
/*
 * Gets a PIO register given a bank and an offset
 */
#define pio_get_register(bank, offset) {return *((uint32_t *)(bank + offset));}
 
// Watchdog Defines
#define WDT_MR *((uint32_t *)0x400E1854)
 
 
#endif