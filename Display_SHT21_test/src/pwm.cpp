#include <sblib/core.h>

#include "pwm.h"

void init_pwm(void) {
	pinMode(PIO3_2, OUTPUT_MATCH);  // configure digital pin PIO2_6 to match MAT1 of timer32 #0

	// Begin using the timer.
	timer16_0.begin();

	timer16_0.prescaler((SystemCoreClock / 10000) - 1); // let the timer count milliseconds
	timer16_0.matchMode(MAT2, SET);  // set the output of PIO2_6 to 1 when the timer matches MAT1
	timer16_0.match(MAT2, 8);      // match MAT1 when the timer reaches this value
	timer16_0.pwmEnable(MAT2);       // enable PWM for match channel MAT1

	// Reset the timer when the timer matches MAT3 and generate an interrupt.
	timer16_0.matchMode(MAT3, RESET | INTERRUPT);
	timer16_0.match(MAT3, 10);     // match MAT3 after 1000 milliseconds

	timer16_0.start();
}
