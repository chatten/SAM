/*
 * TimerTest.c
 *
 * Created: 2013-11-05 8:49:56 PM
 *  Author: Derek
 */ 

#define SAM4E_EK


#include "hardwareDef.h"
#include "hardware.h"
#include "pio_sam.h"
#include "uart_sam.h"




int main(void) {
	// Disable the watchdog
	WDT_MR = 0;
	
	
	// Configure the PIO lines
	pinPioConfig_t blueLED;
	blueLED.port = PIOA;
	blueLED.portPin = BLUE_LED_PIN;
	blueLED.dir = OUTPUT;
	blueLED.type = PIO;
	hwPinPioConfig(&blueLED);
	
	pinPioConfig_t amberLED;
	amberLED.port = PIOD;
	amberLED.portPin = AMBER_LED_PIN;
	amberLED.dir = OUTPUT;
	amberLED.type = PIO;
	hwPinPioConfig(&amberLED);
	
	pinPioConfig_t greenLED;
	greenLED.port = PIOD;
	greenLED.portPin = GREEN_LED_PIN;
	greenLED.dir = OUTPUT;
	greenLED.type = PIO;
	hwPinPioConfig(&greenLED);
	
	pinPioConfig_t pushButton4;
	pushButton4.port = PIOA;
	pushButton4.portPin = BP4_PIN;
	pushButton4.dir = INPUT;
	pushButton4.type = PIO;
	hwPinPioConfig(&pushButton4);
	




	
	
	// Blink the green LED
	while(1) {
		

		hwPinPioWrite(PIOD,GREEN_LED_PIN,LOW);
		hwPinPioWrite(PIOD,AMBER_LED_PIN,HIGH);
		//ret = hwPinPioRead(PIOA, BP4_PIN);
		delay();
		//hwPinPioWrite(PIOA,BLUE_LED_PIN, (ret));

		hwPinPioWrite(PIOD,GREEN_LED_PIN,HIGH);
		hwPinPioWrite(PIOD,AMBER_LED_PIN,LOW);
		delay();


		

	}
	
	
	return 0;
}


void delay()
{
	volatile uint32_t cnt = 1;
	while(cnt++ < 100000);
	;
}
