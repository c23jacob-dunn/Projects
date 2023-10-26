///////////////////////////////////////////////////////////////////////////////
//Authors: Brandon Brennan, Thomas DeSchutter, Jacob Dunn
//Date: 11 Apr 2023
//Class: ECE4721 Winter
//Title: Final Project - Automatic Tree Watering Device
//Description: This code uses an FSM to control 
///////////////////////////////////////////////////////////////////////////////

#include "MKL25Z4.h"
#define MASK(x) (1UL << (x))
 
void Init( void );
void Read_System_State( void );
void Run_Pump ( void );
void Stop_Pump ( void );
void Seven_Segment_Display ( void );
void Delay( volatile unsigned int time_del);


#define SW_1 (8) //PORTB
#define WLS_1 (9)
#define WLS_2 (10)
#define pump (11)
#define led (12)

#define a (4) //PORTE
#define b (29)
#define c (22)
#define d (20)
#define e (2)
#define f (5)
#define g (23)
#define DP (21)

static int switch1=0, waterSensorTank=0, waterSensorCanister=0, runPump=0;


int main ( void ) {
	
	Init();
	
	while(1){
		Read_System_State();
		if(switch1 || runPump) Run_Pump();
		else Stop_Pump();
		Seven_Segment_Display();
		Delay(20000);
	}
}


void Init( void ) {	
	
	//enable clock on port E and B
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK | SIM_SCGC5_PORTB_MASK; 
	
	PORTB->PCR[SW_1] &= ~PORT_PCR_MUX_MASK; //clear GPIO
	PORTB->PCR[SW_1] |= PORT_PCR_MUX(1); //set GPIO
	
	PORTB->PCR[WLS_1] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[WLS_1] |= PORT_PCR_MUX(1);
	PORTB->PCR[WLS_2] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[WLS_2] |= PORT_PCR_MUX(1);
	
	PORTB->PCR[pump] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[pump] |= PORT_PCR_MUX(1);
	
	PORTB->PCR[led] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[led] |= PORT_PCR_MUX(1);
	
	PORTE->PCR[a] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[a] |= PORT_PCR_MUX(1);
	PORTE->PCR[b] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[b] |= PORT_PCR_MUX(1);
	PORTE->PCR[c] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[c] |= PORT_PCR_MUX(1);
	PORTE->PCR[d] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[d] |= PORT_PCR_MUX(1);
	PORTE->PCR[e] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[e] |= PORT_PCR_MUX(1);
	PORTE->PCR[f] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[f] |= PORT_PCR_MUX(1);
	PORTE->PCR[g] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[g] |= PORT_PCR_MUX(1);
	PORTE->PCR[DP] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[DP] |= PORT_PCR_MUX(1);
	
	PTE->PDDR |= MASK(a) | MASK(b) | MASK(c) | MASK(d) | MASK(e) | 
							 MASK(f) | MASK(g) | MASK(DP); //set SevSegDisp to output
	
	PTB->PDDR |= MASK(pump); //set pump to output
	
	PTB->PDDR |= MASK(led); //set LED to output
	
	PTB->PDDR &= ~MASK(SW_1); //set Button to input
	
	PTB->PDDR &= ~MASK(WLS_1); //set water level sensors to input
	PTB->PDDR &= ~MASK(WLS_2);
	
	PTB->PSOR = MASK(pump); //initialize pump to 0
	
	PTB->PSOR = MASK(led); //initialize LED to 0
	
	PTE->PSOR = MASK(a); //initialize LEDs to 0
	PTE->PSOR = MASK(b);
	PTE->PSOR = MASK(c);
	PTE->PSOR = MASK(d);
	PTE->PSOR = MASK(e);
	PTE->PSOR = MASK(f);
	PTE->PSOR = MASK(g);
	PTE->PCOR = MASK(DP); //initialize DP to 1
}

void Read_System_State( void ){
	if(PTB->PDIR & MASK(SW_1))	switch1 = 1; //1 when button is pressed
	else switch1 = 0;		
	
	if(/*WLS_2 < 20% */) {
		runPump = 1;
		if(/*WLS_2 > 80% */) {
			runPump = 0;
		}
	}
	
	if(/*WLS_1 > 90% */) waterSensorTank = 9;
	else if (/*WLS_1 > 80% */) waterSensorTank = 8;
	else if (/*WLS_1 > 70% */) waterSensorTank = 7;
	else if (/*WLS_1 > 60% */) waterSensorTank = 6;
	else if (/*WLS_1 > 50% */) waterSensorTank = 5;
	else if (/*WLS_1 > 40% */) waterSensorTank = 4;
	else if (/*WLS_1 > 30% */) waterSensorTank = 3;
	else if (/*WLS_1 > 20% */) waterSensorTank = 2;
	else if (/*WLS_1 > 10% */) {
		waterSensorTank = 1;
		PTB->PSOR = MASK(led);
	}
	else {
		waterSensorTank = 0;
		PTB->PCOR = MASK(led);
	}
}

void Run_Pump ( void ) {
	PTB->PCOR = MASK(pump); //turn pump on
}

void Stop_Pump ( void ) {
	PTB->PSOR = MASK(pump); //turn pump off
}

void Seven_Segment_Display ( void ) {
	if(waterSensorTank == 0){
		PTE->PCOR = MASK(a);
		PTE->PCOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PCOR = MASK(d);
		PTE->PCOR = MASK(e);
		PTE->PCOR = MASK(f);
		PTE->PSOR = MASK(g);
	}
	
	else if(waterSensorTank == 1){
		PTE->PSOR = MASK(a);
		PTE->PCOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PSOR = MASK(d);
		PTE->PSOR = MASK(e);
		PTE->PSOR = MASK(f);
		PTE->PSOR = MASK(g);
	}
	
	else if(waterSensorTank == 2){
		PTE->PCOR = MASK(a);
		PTE->PCOR = MASK(b);
		PTE->PSOR = MASK(c);
		PTE->PCOR = MASK(d);
		PTE->PCOR = MASK(e);
		PTE->PSOR = MASK(f);
		PTE->PCOR = MASK(g);
	}
	
	else if(waterSensorTank == 3){
		PTE->PCOR = MASK(a);
		PTE->PCOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PCOR = MASK(d);
		PTE->PSOR = MASK(e);
		PTE->PSOR = MASK(f);
		PTE->PCOR = MASK(g);
	}
	
	else if(waterSensorTank == 4){
		PTE->PSOR = MASK(a);
		PTE->PCOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PSOR = MASK(d);
		PTE->PSOR = MASK(e);
		PTE->PCOR = MASK(f);
		PTE->PCOR = MASK(g);
	}
	
	else if(waterSensorTank == 5){
		PTE->PCOR = MASK(a);
		PTE->PSOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PCOR = MASK(d);
		PTE->PSOR = MASK(e);
		PTE->PCOR = MASK(f);
		PTE->PCOR = MASK(g);
	}
	
	else if(waterSensorTank == 6){
		PTE->PCOR = MASK(a);
		PTE->PSOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PCOR = MASK(d);
		PTE->PCOR = MASK(e);
		PTE->PCOR = MASK(f);
		PTE->PCOR = MASK(g);
	}
	
	else if(waterSensorTank == 7){
		PTE->PCOR = MASK(a);
		PTE->PCOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PSOR = MASK(d);
		PTE->PSOR = MASK(e);
		PTE->PSOR = MASK(f);
		PTE->PSOR = MASK(g);
	}
	
	else if(waterSensorTank == 8){
		PTE->PCOR = MASK(a);
		PTE->PCOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PCOR = MASK(d);
		PTE->PCOR = MASK(e);
		PTE->PCOR = MASK(f);
		PTE->PCOR = MASK(g);
	}
	
	else if(waterSensorTank == 9){
		PTE->PCOR = MASK(a);
		PTE->PCOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PSOR = MASK(d);
		PTE->PSOR = MASK(e);
		PTE->PCOR = MASK(f);
		PTE->PCOR = MASK(g);
	}
	
	else { //off
		PTE->PSOR = MASK(a);
		PTE->PSOR = MASK(b);
		PTE->PSOR = MASK(c);
		PTE->PSOR = MASK(d);
		PTE->PSOR = MASK(e);
		PTE->PSOR = MASK(f);
		PTE->PSOR = MASK(g);
	}
}

void Delay( volatile unsigned int time_del) {
	while(time_del--) { }
}
