/*******************************************************************************
*	pio.c					                                                   *
*                                                                              *
*												                               *
*												                               *
*																               *
*******************************************************************************/


#include "pio_sam.h"
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
	Pmc *pmc = PMC;

	//TODO:	Add support for other ports 
	pmc->PMC_PCER0 |= PMC_PCER0_PID9;		//PIOA


	Pio *pio = pinPioConfig->port;
	
	if (pinPioConfig->dir == OUTPUT)
	{		
		// PIO Output Enable Register
		pio->PIO_OER |= (1 << pinPioConfig->portPin);				
						
		// PIO Clear Output Data Register	PIO_CODR
		pio->PIO_CODR |= (1 << pinPioConfig->portPin);
	}else
	{
		//disables interrupt
		pio->PIO_IDR |= (1 << pinPioConfig->portPin);
		//PIO Pull Up Enable Register
		pio->PIO_PUER |= (1 << pinPioConfig->portPin);
		//PIO Output Disable Register
		pio->PIO_ODR |= (1 << pinPioConfig->portPin);		
	}

	if (pinPioConfig->type == PIO)  //enable PIO or PERPHERIAL
	{
		pio->PIO_PER |= (1 << pinPioConfig->portPin);
	}else
	{
		pio->PIO_PDR |= (1 << pinPioConfig->portPin);
	}
}


void hwPinPioWrite(Pio * port, uint32_t portPin, uint8_t state)
{		
	if (state == HIGH)
	{	
		port->PIO_SODR |= (1 << portPin);
	}else
	{
		port->PIO_CODR |= (1 << portPin);
	}



}


uint32_t hwPinPioRead(Pio * port, uint32_t portPin)
{
	return (((port->PIO_PDSR) & (1 << portPin)) >> portPin) ;
}




