/*
Programmer: Jacob Dunn
Date: 24Feb2023
Class: ECE4721 Winter
Title: Speaker Output
*/

#include <MKL25Z4.h>


void Init_Speaker( void );
void Beep( void );
void Delay( volatile unsigned int time_del);


#define SPKR_SHIFT (0)
#define MASK(x) (1UL << (x))


int main (void) {
	Beep();
}


void Beep( void ) {
	Init_Speaker();
	while(1){
		PTC->PTOR = MASK(SPKR_SHIFT);
		Delay(20000); //Determines frequency of output pitch
	}
}

void Init_Speaker( void ) {
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK; //enable clock on port C
	PORTC->PCR[SPKR_SHIFT] |= PORT_PCR_MUX(1); //set GPIO
	PTC->PDDR |= MASK(SPKR_SHIFT); //set I/O to output
	PTC->PDOR |= MASK(SPKR_SHIFT); //initialize to 1
}

void Delay( volatile unsigned int time_del) {
	while(time_del--) { }
}
