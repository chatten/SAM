/*******************************************************************************
*	pio.h     		                            						       *
*																			   *
*******************************************************************************/


#include "hardware.h"
#include "hardwareDef.h"

typedef struct {
	Pio * port;
	uint32_t portPin;
	uint8_t dir;
	uint8_t type;	//PIO or PER(PERIPHERIAL)
} pinPioConfig_t;

extern void hwPinPioConfig(pinPioConfig_t *pinPioConfig);

void hwPinPioWrite(Pio * port, uint32_t portPin, uint8_t state);
uint32_t hwPinPioRead(Pio * port, uint32_t portPin);


typedef struct {
	Pio * port;
	uint16_t dir;
	uint8_t state;
	uint8_t openDrain;
} portPioConfig_t;

extern void hwPortPioConfig(portPioConfig_t *portPioConfig);