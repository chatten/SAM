/*******************************************************************************
*	Hardware.c	     				                                           *
*						                                                       *
*			   		                 	                                       *
*******************************************************************************/


#include "hardware.h"
#include "hardwareDef.h"

void setRegBit(uint32_t address, uint32_t mask)
{
	
	*((uint32_t *)(address)) |= (mask);
	
}

void clrRegBit(uint32_t address, uint32_t mask)
{
	
	*((uint32_t *)(address)) &= ~(mask);
	
}

void setReg(uint32_t address, uint32_t value)
{
	*((uint32_t *)(address)) = value;
	
}

uint32_t getReg(uint32_t address)
{
	return *((uint32_t *)(address));
	
}