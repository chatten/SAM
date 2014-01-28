/*******************************************************************************
*	pio.h     		                            						       *
*																			   *
*******************************************************************************/


#include "hardware.h"
#include "hardwareDef.h"

typedef struct {
	uint32_t portAddr;
	uint32_t portPin;
	uint8_t dir;
	uint8_t type;	//PIO or PER(PERIPHERIAL)
} pinPioConfig_t;

extern void hwPinPioConfig(pinPioConfig_t *pinPioConfig);

void hwPinPioWrite(uint32_t portAddr, uint32_t portPin, uint8_t state);
uint32_t hwPinPioRead(uint32_t portAddr, uint32_t portPin);


typedef struct {
	volatile uint16_t *portAddr;
	uint16_t dir;
	uint8_t state;
	uint8_t openDrain;
} portPioConfig_t;

extern void hwPortPioConfig(portPioConfig_t *portPioConfig);