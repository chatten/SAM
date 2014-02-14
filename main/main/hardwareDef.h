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

 
// Watchdog Defines
#define WDT_MR *((uint32_t *)0x400E1854)
 
 
#endif