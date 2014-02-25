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


void delay();


int main(void) {
	/* Disable the watchdog */
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	uint32_t ret = 0;
	
	// Configure the PIO lines
	pinPioConfig_t blueLED;
	blueLED.port = PIOA;
	blueLED.portPin = BLUE_LED_PIN;
	blueLED.dir = OUTPUT;
	blueLED.type = PIO;
	hwPinPioConfig(&blueLED);
	


	
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
		
		
	//set up timer 
	Tc *tc = TC0;
	Pmc *pmc = PMC;
	pmc->PMC_PCER0 |= PMC_PCER0_PID21;	//Enable TC0 Peripheral Clock
	//tc->
	
	
	//=================================================================================
	//PWM TEST FOR AMBER LED -SIGNAL ATTACHED TO PWMH0
	
	Pio *pio = PIOD;
	pio->PIO_PDR |= (1 << AMBER_LED_PIN);
	
	
	//Set to peripheral A 
	pio->PIO_ABCDSR[0] &= ~(1 << AMBER_LED_PIN);
	pio->PIO_ABCDSR[1] &= ~(1 << AMBER_LED_PIN);
	
	//Enable Output
	pio->PIO_OER |= (1 << AMBER_LED_PIN);
	
	
	
	//set up PWM
	pmc->PMC_PCER1 |= PMC_PCER1_PID36;  //Enable PWM Peripheral Clock
	Pwm *pwm = PWM;
	//1. Select the manual write of duty-cycle values and the manual update by setting the UPDM field to 0 in the
	//PWM_SCM register
	pwm->PWM_SCM  &=  ~PWM_SCM_UPDM_MODE0;
	
	//TODO  -Decifer correct value for CLK
	pwm->PWM_CLK =0x0101;
	
	//2. Define the synchronous channels by the SYNCx bits in the PWM_SCM register.
	pwm->PWM_SCM &= ~PWM_SCM_SYNC0;  //Channel 0 is not a synchronous channel.
	pwm->PWM_SCM &= ~PWM_SCM_SYNC1;  //Channel 1 is not a synchronous channel.
	pwm->PWM_SCM &= ~PWM_SCM_SYNC2;  //Channel 2 is not a synchronous channel.
	pwm->PWM_SCM &= ~PWM_SCM_SYNC3;  //Channel 3 is not a synchronous channel.
	
	//3. Enable the synchronous channels by writing CHID0 in the PWM_ENA register.
	pwm->PWM_ENA |= PWM_ENA_CHID0;		//1 = Enable PWM output for channel x.
	pwm->PWM_ENA &= ~PWM_ENA_CHID1;
	pwm->PWM_ENA &= ~PWM_ENA_CHID2;
	pwm->PWM_ENA &= ~PWM_ENA_CHID3;
	
	//4. If an update of the period value and/or the duty-cycle values and/or the dead-time values is required, write registers
	//		that need to be updated (PWM_CPRDUPDx, PWM_CDTYUPDx and PWM_DTUPDx).
	
	REG_PWM_CPRDUPD0 = 100;		//period
	REG_PWM_CDTYUPD0 = 0x0000;	//duty Cycle
	
	//5. Set UPDULOCK to 1 in PWM_SCUC.
	pwm->PWM_SCUC |= PWM_SCUC_UPDULOCK;
	int dutyCycle = 0;
	
	//==================================================================================
	
	
	// Blink the green LED
	while(1) {
		
		hwPinPioWrite(PIOD,GREEN_LED_PIN,LOW);
		ret = hwPinPioRead(PIOA, BP4_PIN);
		hwPinPioWrite(PIOA,BLUE_LED_PIN, (ret));
		delay();
		dutyCycle += 10;
		REG_PWM_CDTYUPD0 = dutyCycle;
		
		ret = hwPinPioRead(PIOA, BP4_PIN);
		hwPinPioWrite(PIOA,BLUE_LED_PIN, (ret));
		hwPinPioWrite(PIOD,GREEN_LED_PIN,HIGH);

		delay();
		if (dutyCycle > 0x64)
		{
			dutyCycle = 0;	
		}else 
		{
			dutyCycle += 10;
		}
		
		
		REG_PWM_CDTYUPD0 = dutyCycle;		

	}
	
	
	return 0;
}


void delay()
{
	volatile uint32_t cnt = 1;
	while(cnt++ < 100000);
	;
}
