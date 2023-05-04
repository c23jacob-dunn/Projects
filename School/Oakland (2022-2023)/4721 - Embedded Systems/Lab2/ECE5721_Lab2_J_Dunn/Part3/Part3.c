/*
Programmer: Jacob Dunn
Date: 24Feb2023
Class: ECE4721 Winter
Title: FSM for Water Tank System
*/

#include "MKL25Z4.h"


void Init( void );
void Read_Button_State( void );
void FSM ( void );
void LED ( void );
void Delay( volatile unsigned int time_del);


#define R_LED (2)
#define G_LED (3)
#define B_LED (4)
#define Y_LED (5)
#define BUTTON (8)
#define MASK(x) (1UL << (x))

int ETS=0, FLS=1, OFS=1;

static enum Status { START, 
										 TANK_EMPTY, 
										 WATER_IN_TANK, 
										 TANK_FULL,
										 TANK_OVERFLOW
} next_state = START;


int main ( void ) {
	
	Init();
	
	while(1){
		Read_Button_State();
		FSM();
		LED();
		Delay(20000);
	}
}


void Init( void ) {	
	
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK | SIM_SCGC5_PORTB_MASK; //enable clock on port E&B
	
	PORTE->PCR[R_LED] &= ~PORT_PCR_MUX_MASK; //clear GPIO
	PORTE->PCR[R_LED] |= PORT_PCR_MUX(1); //set GPIO
	PORTE->PCR[G_LED] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[G_LED] |= PORT_PCR_MUX(1);
	PORTE->PCR[B_LED] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[B_LED] |= PORT_PCR_MUX(1);
	PORTE->PCR[Y_LED] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[Y_LED] |= PORT_PCR_MUX(1);
	PORTB->PCR[BUTTON] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[BUTTON] |= PORT_PCR_MUX(1);
	
	PTE->PDDR |= MASK(R_LED) | MASK(G_LED) | MASK(B_LED) | MASK(Y_LED); //set LED I/O to output
	PTB->PDDR &= ~MASK(BUTTON); //set Button I/O to input
	
	PTE->PDOR |= MASK(R_LED); //initialize to 1
	PTE->PDOR |= MASK(G_LED); 
	PTE->PDOR |= MASK(B_LED);
	PTE->PDOR |= MASK(Y_LED);
}

void Read_Button_State( void ){
	
	if(PTB->PDIR == 0){ //when switch is not pressed
		ETS = 0;
		FLS = 1;
		OFS = 1;
	}
	else{ //switch pressed
		ETS = 1;
		FLS = 0;
		OFS = 0;
	}
}

void FSM ( void ) {
	
	switch (next_state) {
		case START:
			if(ETS == 1) next_state = TANK_EMPTY;
			break;
		
		case TANK_EMPTY:
			if(ETS == 0) next_state = WATER_IN_TANK;
			break;
		
		case WATER_IN_TANK:
			if(FLS == 1) next_state = TANK_FULL;
			else if(ETS == 1) next_state = TANK_EMPTY;
			break;
		
		case TANK_FULL:
			if(OFS == 1) next_state = TANK_OVERFLOW;
			else if(FLS == 0) next_state = WATER_IN_TANK;
			break;
		
		case TANK_OVERFLOW:
			if(OFS == 0) next_state = TANK_FULL;
			break;
		
		default:
			next_state = next_state;
			break;
	}
}

void LED ( void ) {
	
	switch (next_state) {
		case START:
			//NO LEDs on
			PTE->PCOR = MASK(R_LED);
			PTE->PCOR = MASK(G_LED);
			PTE->PCOR = MASK(B_LED);
			PTE->PCOR = MASK(Y_LED);
			break;
		
		case TANK_EMPTY:
			//Only Blue on
			PTE->PCOR = MASK(R_LED);
			PTE->PCOR = MASK(G_LED);
			PTE->PSOR = MASK(B_LED);
			PTE->PCOR = MASK(Y_LED);
			break;
		
		case WATER_IN_TANK:
			//Green and Blue on
			PTE->PCOR = MASK(R_LED);
			PTE->PSOR = MASK(G_LED);
			PTE->PSOR = MASK(B_LED);
			PTE->PCOR = MASK(Y_LED);
			break;
		
		case TANK_FULL:
			//Blue and Yellow on
			PTE->PCOR = MASK(R_LED);
			PTE->PCOR = MASK(G_LED);
			PTE->PSOR = MASK(B_LED);
			PTE->PSOR = MASK(Y_LED);
			break;
		
		case TANK_OVERFLOW:
			//Only Red on
			PTE->PSOR = MASK(R_LED);
			PTE->PCOR = MASK(G_LED);
			PTE->PCOR = MASK(B_LED);
			PTE->PCOR = MASK(Y_LED);
			break;
		
		default:
			//NO LEDs on
			PTE->PCOR = MASK(R_LED);
			PTE->PCOR = MASK(G_LED);
			PTE->PCOR = MASK(B_LED);
			PTE->PCOR = MASK(Y_LED);
			break;
	}
}

void Delay( volatile unsigned int time_del) {
	while(time_del--) { }
}
