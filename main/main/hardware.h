/*******************************************************************************
*	hardware.h    		                          						       *
*																			   *
*******************************************************************************/


#include "hardwareDef.h"


#define FALSE	0
#define TRUE	1
#define INPUT	1
#define OUTPUT	0
#define HIGH 	1
#define LOW		0
#define PIO		0
#define PER		1


void setRegBit(uint32_t *address, uint32_t mask);
void clrRegBit(uint32_t address, uint32_t mask);
void setReg(uint32_t address, uint32_t value);
uint32_t getReg(uint32_t address);
