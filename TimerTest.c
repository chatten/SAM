/*
 * TimerTest.c
 *
 * Created: 2013-11-05 8:49:56 PM
 *  Author: Derek
 */ 

#define SAM4E_EK


#include "hardwareDef.h"
#include "hardware.h"
#include "pio.h"
#include "uart.h"




int main(void) {
	// Disable the watchdog
	WDT_MR = 0;
	
	
	// Configure the PIO lines
	pinPioConfig_t blueLED;
	blueLED.portAddr = PIO_A;
	blueLED.portPin = BLUE_LED_PIN;
	blueLED.dir = OUTPUT;
	blueLED.type = PIO;
	hwPinPioConfig(&blueLED);
	
	pinPioConfig_t amberLED;
	amberLED.portAddr = PIO_D;
	amberLED.portPin = AMBER_LED_PIN;
	amberLED.dir = OUTPUT;
	amberLED.type = PIO;
	hwPinPioConfig(&amberLED);
	
	pinPioConfig_t greenLED;
	greenLED.portAddr = PIO_D;
	greenLED.portPin = GREEN_LED_PIN;
	greenLED.dir = OUTPUT;
	greenLED.type = PIO;
	hwPinPioConfig(&greenLED);
	
	pinPioConfig_t pushButton4;
	pushButton4.portAddr = BP4_PORT;
	pushButton4.portPin = BP4_PIN;
	pushButton4.dir = INPUT;
	pushButton4.type = PIO;
	hwPinPioConfig(&pushButton4);
	


	
	//configure UART1 PIO
	
	pinPioConfig_t uart0Tx;
	uart0Tx.portAddr = PIO_A;
	uart0Tx.portPin = 10;
	uart0Tx.dir = OUTPUT;
	uart0Tx.type = PER;
	hwPinPioConfig(&uart0Tx);
	
	pinPioConfig_t uart0Rx;
	uart0Rx.portAddr = PIO_A;
	uart0Rx.portPin = 9;
	uart0Rx.dir = INPUT;
	uart0Rx.type = PER;
	hwPinPioConfig(&uart0Rx);
	
	uartConfig_t uart0;
	uart0.baseAddr = UART0;
	uart0.baudrate =9600;
	hwUartConfig(&uart0);

	
	uint32_t ret = 0;
	
	
	// Blink the green LED
	while(1) {
		

		hwPinPioWrite(PIO_D,GREEN_LED_PIN,LOW);
		hwPinPioWrite(PIO_D,AMBER_LED_PIN,HIGH);
		ret = hwPinPioRead(BP4_PORT, BP4_PIN);
		delay();
		hwPinPioWrite(PIO_A,BLUE_LED_PIN, (ret));

		hwPinPioWrite(PIO_D,GREEN_LED_PIN,HIGH);
		hwPinPioWrite(PIO_D,AMBER_LED_PIN,LOW);
		delay();


		

	}
	
	
	return 0;
}


delay()
{
	volatile uint32_t cnt = 1;
	while(cnt++ < 100000);
	;
}
