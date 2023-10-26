/*
Programmer: Jacob Dunn
Date: 17Mar2023
Class: ECE4721 Winter
Title: Seven Segment Display with Switches
*/

#include "MKL25Z4.h"
#define MASK(x) (1UL << (x))

void Init( void );
void Read_Button_State( void );
void Seven_Segment_Display ( void );
void Delay( volatile unsigned int time_del);


#define SW_1 (8) //PORTB
#define SW_2 (9)
#define SW_3 (10)
#define SW_4 (11)

#define a (4) //PORTE
#define b (29)
#define c (22)
#define d (20)
#define e (2)
#define f (5)
#define g (23)
#define DP (21)

static int switch1=0, switch2=0, switch3=0, switch4=0;


int main ( void ) {
	
	Init();
	
	while(1){
		Read_Button_State();
		Seven_Segment_Display();
		Delay(20000);
	}
}


void Init( void ) {	
	
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK | SIM_SCGC5_PORTB_MASK; //enable clock on port E and B
	
	PORTB->PCR[SW_1] &= ~PORT_PCR_MUX_MASK; //clear GPIO
	PORTB->PCR[SW_1] |= PORT_PCR_MUX(1); //set GPIO
	PORTB->PCR[SW_2] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[SW_2] |= PORT_PCR_MUX(1);
	PORTB->PCR[SW_3] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[SW_3] |= PORT_PCR_MUX(1);
	PORTB->PCR[SW_4] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[SW_4] |= PORT_PCR_MUX(1);
	
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
	
	PTE->PDDR |= MASK(a) | MASK(b) | MASK(c) | MASK(d) | MASK(e) | MASK(f) | MASK(g) | MASK(DP); //set SevSegDisp I/O to output
	
	PTB->PDDR &= ~MASK(SW_1); //set Button I/O to input
	PTB->PDDR &= ~MASK(SW_2);
	PTB->PDDR &= ~MASK(SW_3);
	PTB->PDDR &= ~MASK(SW_4);
	
	PTE->PSOR = MASK(a); //initialize to 0
	PTE->PSOR = MASK(b);
	PTE->PSOR = MASK(c);
	PTE->PSOR = MASK(d);
	PTE->PSOR = MASK(e);
	PTE->PSOR = MASK(f);
	PTE->PSOR = MASK(g);
	PTE->PCOR = MASK(DP); //initialize to 1
}

void Read_Button_State( void ){
	if(PTB->PDIR & MASK(SW_1))	switch1 = 1; //when button is pressed, set to 1
	else switch1 = 0;
	
	if(PTB->PDIR & MASK(SW_2))	switch2 = 1;
	else switch2 = 0;
	
	if(PTB->PDIR & MASK(SW_3))	switch3 = 1;
	else switch3 = 0;
	
	if(PTB->PDIR & MASK(SW_4))	switch4 = 1;
	else switch4 = 0;
		
}

void Seven_Segment_Display ( void ) {
	if(switch4==0 && switch3==0 && switch2==0 && switch1==0){ //0
		PTE->PCOR = MASK(a);
		PTE->PCOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PCOR = MASK(d);
		PTE->PCOR = MASK(e);
		PTE->PCOR = MASK(f);
		PTE->PSOR = MASK(g);
	}
	
	else if(switch4==0 && switch3==0 && switch2==0 && switch1==1){ //1
		PTE->PSOR = MASK(a);
		PTE->PCOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PSOR = MASK(d);
		PTE->PSOR = MASK(e);
		PTE->PSOR = MASK(f);
		PTE->PSOR = MASK(g);
	}
	
	else if(switch4==0 && switch3==0 && switch2==1 && switch1==0){ //2
		PTE->PCOR = MASK(a);
		PTE->PCOR = MASK(b);
		PTE->PSOR = MASK(c);
		PTE->PCOR = MASK(d);
		PTE->PCOR = MASK(e);
		PTE->PSOR = MASK(f);
		PTE->PCOR = MASK(g);
	}
	
	else if(switch4==0 && switch3==0 && switch2==1 && switch1==1){ //3
		PTE->PCOR = MASK(a);
		PTE->PCOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PCOR = MASK(d);
		PTE->PSOR = MASK(e);
		PTE->PSOR = MASK(f);
		PTE->PCOR = MASK(g);
	}
	
	else if(switch4==0 && switch3==1 && switch2==0 && switch1==0){ //4
		PTE->PSOR = MASK(a);
		PTE->PCOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PSOR = MASK(d);
		PTE->PSOR = MASK(e);
		PTE->PCOR = MASK(f);
		PTE->PCOR = MASK(g);
	}
	
	else if(switch4==0 && switch3==1 && switch2==0 && switch1==1){ //5
		PTE->PCOR = MASK(a);
		PTE->PSOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PCOR = MASK(d);
		PTE->PSOR = MASK(e);
		PTE->PCOR = MASK(f);
		PTE->PCOR = MASK(g);
	}
	
	else if(switch4==0 && switch3==1 && switch2==1 && switch1==0){ //6
		PTE->PCOR = MASK(a);
		PTE->PSOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PCOR = MASK(d);
		PTE->PCOR = MASK(e);
		PTE->PCOR = MASK(f);
		PTE->PCOR = MASK(g);
	}
	
	else if(switch4==0 && switch3==1 && switch2==1 && switch1==1){ //7
		PTE->PCOR = MASK(a);
		PTE->PCOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PSOR = MASK(d);
		PTE->PSOR = MASK(e);
		PTE->PSOR = MASK(f);
		PTE->PSOR = MASK(g);
	}
	
	else if(switch4==1 && switch3==0 && switch2==0 && switch1==0){ //8
		PTE->PCOR = MASK(a);
		PTE->PCOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PCOR = MASK(d);
		PTE->PCOR = MASK(e);
		PTE->PCOR = MASK(f);
		PTE->PCOR = MASK(g);
	}
	
	else if(switch4==1 && switch3==0 && switch2==0 && switch1==1){ //9
		PTE->PCOR = MASK(a);
		PTE->PCOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PSOR = MASK(d);
		PTE->PSOR = MASK(e);
		PTE->PCOR = MASK(f);
		PTE->PCOR = MASK(g);
	}
	
	else { //10+
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
