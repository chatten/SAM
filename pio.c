/*******************************************************************************
*	pio.c					                                                   *
*                                                                              *
*												                               *
*												                               *
*																               *
*******************************************************************************/


#include "pio.h"
#include "hardwareDef.h"
#include "hardware.h"



/*******************************************************************************
*	hwPinPioConfig			                                                   *
*                                                                              *
*	initialize one pin  for PIO                                                *
*	                                                                           *
*	Returns Nothing					                                           *
*******************************************************************************/
 
void hwPinPioConfig(pinPioConfig_t *pinPioConfig)
{
	//enable peripheral clock
	setRegBit(PMC_PCER0, PID9);
				
	if (pinPioConfig->dir == OUTPUT)
	{		
		// PIO Output Enable Register	
		setRegBit(pinPioConfig->portAddr + PIO_OER, 1 << pinPioConfig->portPin);				
		// PIO Clear Output Data Register	PIO_CODR
		setRegBit(pinPioConfig->portAddr + PIO_CODR, 1 << pinPioConfig->portPin);
	}else
	{

		//disables interrupt
		setRegBit(pinPioConfig->portAddr + PIO_IDR, 1 << pinPioConfig->portPin);
		//PIO Pull Up Enable Register
		setRegBit(pinPioConfig->portAddr + PIO_PUER, 1 << pinPioConfig->portPin);
		//PIO Output Disable Register
		setRegBit(pinPioConfig->portAddr + PIO_ODR, 1 << pinPioConfig->portPin);
		
	}

	if (pinPioConfig->type == PIO)  //enable PIO or PERPHERIAL 
	{
		setRegBit(pinPioConfig->portAddr + PIO_PER, 1 << pinPioConfig->portPin);
	}else
	{
		setRegBit(pinPioConfig->portAddr + PIO_PDR, 1 << pinPioConfig->portPin);
	}

	


}


void hwPinPioWrite(uint32_t portAddr, uint32_t portPin, uint8_t state)
{
	if (state == HIGH)
	{
		setRegBit(portAddr + PIO_SODR, 1 << portPin);
	}else
	{
		setRegBit(portAddr + PIO_CODR,1 << portPin);
	}



}


uint32_t hwPinPioRead(uint32_t portAddr, uint32_t portPin)
{
    return (*((uint32_t *)(portAddr + PIO_PDSR)) & (1 << portPin)) >> portPin ;
}

	
	
	
