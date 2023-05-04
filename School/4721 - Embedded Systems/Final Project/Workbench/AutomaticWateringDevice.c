/*
Authors: 
Date: 7Apr2023
Class: ECE4721 Winter
Title: Automatic Watering Device
*/

#include "MKL25Z4.h"
#define MASK(x) (1UL << (x))

void Init_Seven_Segment_Display ( void );
void Init_Pump ( void );
void Seven_Segment_Display ( int num );
void Run_Pump ( int on );
void Delay( volatile unsigned int time_del);

void Init_RGB_LEDs(void);
void Control_RGB_LEDs(unsigned int red_on, unsigned int green_on, unsigned int blue_on);
void Init_Switch ( void );

void Init_WATER_LEV1 (void);
void Init_WATER_LEV2 (void);
void Init_ADC (void);
unsigned Measure_WATER_LEV1 (void);
unsigned Measure_WATER_LEV2 (void);
void seven_segment_water_level ( void );

void FSM ( void );


#define WATER_LEV1 (1) // Might not be needed
#define WATER_LEV2 (2) // Might not be needed
#define WATER_LEV1_CHANNEL (9) // Christmas tree stand water level sensor on port B bit 1
#define WATER_LEV2_CHANNEL (12) // Tank water level sensor on port B bit 2

#define SW_1 (0)            //on port B
#define RED_LED_POS (8)		// on port B
#define GREEN_LED_POS (10)	// on port B
#define BLUE_LED_POS (9)   // on port B

#define a (4) //PORTE
#define b (29)
#define c (22)
#define d (20)
#define e (2)
#define f (5)
#define g (23)
#define DP (21)

#define pump (30) //PORTE

static enum {STATE1, STATE2_WAIT, STATE3, STATE4_WAIT} next_state = STATE1;

unsigned  lev1 = 0, lev2 = 0;



int main ( void ) {
	
	Init_Seven_Segment_Display();
  Init_Pump();
	Init_RGB_LEDs();
	Init_Switch();
	Init_WATER_LEV1();
	Init_WATER_LEV2();
	Init_ADC();
	
	while (1) {
		//int temp = PTB->PDIR & MASK(SW_1);
		int busy = 0;
		
		if(PTB->PDIR & MASK(SW_1)) {
			Run_Pump(1);
			busy = 1;
		}
		else {
			Run_Pump(0);
			busy = 0;
		}
		
		if(busy==0){
			FSM();
		}
	}
}

void FSM ( void ) {

	switch(next_state) {
		case STATE1:										// measure water level in stand
			lev1 = Measure_WATER_LEV1();	// save water level in variable lev1
			lev2 = Measure_WATER_LEV2();
			seven_segment_water_level();	// display water level on seven seg display
			if(lev2 <= 16000){							// if water level below threshold, don't run pump
				Control_RGB_LEDs(1,0,0);		// display red on LED to indicate low reserve tank water level
				next_state = STATE4_WAIT;		// move to delay state before testing water level again
			}
			else if(lev1 <= 14000){							// if water level low, move to state3, to check water level in reserve tank
				next_state = STATE3;
			}
			else{
				Control_RGB_LEDs(0,1,0);
				next_state = STATE2_WAIT;		// if water level good, move to a delay state
			}
			
			break;
			
		case STATE2_WAIT:								// long delay state, used after pump refills tank or water level is determined to be satisfactory
			//Delay(60000);
			next_state = STATE1;
			break;
		
		case STATE3:
			//lev2 = Measure_WATER_LEV2();	// measure water level in reserve tank
			//else{													// if water level is above threshold, run pump
				Control_RGB_LEDs(0,1,0);    // display green on LED to indicate good reserve tank water level
				//while(lev1 < 18000){
				Run_Pump(1);
				Delay(50000000);
				//lev1 = Measure_WATER_LEV1();
				//}
				Run_Pump(0);
				next_state = STATE2_WAIT;
			//}
			break;
		
		case STATE4_WAIT:								// short delay state, used when reserve tank water level is determine to be low
			//Delay(20000);									// delay is shorter because if tank is refilled, we want the level to be updated quickly so the stand can be refilled
			next_state = STATE1;
			break;
		
		default:
			next_state = STATE1;
			break;
		}
}


void Init_Pump ( void ) {
	
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
	
	PORTE->PCR[pump] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[pump] |= PORT_PCR_MUX(1);
	
	PTE->PDDR |= MASK(pump);
	
	PTE->PCOR = MASK(pump);
}

void Run_Pump ( int on ) {
	if(on==1){
		PTE->PSOR = MASK(pump);
	}
	else{
		PTE->PCOR = MASK(pump);
	}
}

// initialize Christmas tree stand water level sensor
void Init_WATER_LEV1 (void) {
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;
	
	PORTB->PCR[WATER_LEV1] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[WATER_LEV1] |= PORT_PCR_MUX (1);
	PTB->PDDR &= ~MASK(WATER_LEV1); // set direction as input
}

// initialize tank water level sensor
void Init_WATER_LEV2 (void) {
	PORTB->PCR[WATER_LEV2] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[WATER_LEV2] |= PORT_PCR_MUX (1);
	PTB->PDDR &= ~MASK(WATER_LEV2); // set direction as input
}

// initialize ADC
void Init_ADC (void) {
	SIM->SCGC6 |= (1UL << SIM_SCGC6_ADC0_SHIFT);
	ADC0->CFG1 = ADC_CFG1_ADLPC_MASK | ADC_CFG1_ADIV(0) | ADC_CFG1_ADLSMP_MASK | ADC_CFG1_MODE(3) | ADC_CFG1_ADICLK(0); // Low-power configuration, clock rate = input clock, long sample time, 16-bit conversion, input clock = bus clock
	ADC0->SC2 = ADC_SC2_REFSEL(0); // select default voltage reference pins VREFH and VREFL
}

void Control_RGB_LEDs(unsigned int red_on, unsigned int green_on, unsigned int blue_on) {
	if (red_on) {
			PTB->PSOR = MASK(RED_LED_POS);
	} else {
			PTB->PCOR = MASK(RED_LED_POS); 
	}
	if (green_on) {
			PTB->PSOR = MASK(GREEN_LED_POS);
	}	else {
			PTB->PCOR = MASK(GREEN_LED_POS); 
	} 
	if (blue_on) {
			PTB->PSOR = MASK(BLUE_LED_POS);
	}	else {
			PTB->PCOR = MASK(BLUE_LED_POS); 
	}
}
void Init_RGB_LEDs(void) {
	// Enable clock to port B
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;
	
	// Make 3 pins GPIO
	PORTB->PCR[RED_LED_POS] &= ~PORT_PCR_MUX_MASK;          
	PORTB->PCR[RED_LED_POS] |= PORT_PCR_MUX(1);          
	PORTB->PCR[GREEN_LED_POS] &= ~PORT_PCR_MUX_MASK;          
	PORTB->PCR[GREEN_LED_POS] |= PORT_PCR_MUX(1);          
	PORTB->PCR[BLUE_LED_POS] &= ~PORT_PCR_MUX_MASK;          
	PORTB->PCR[BLUE_LED_POS] |= PORT_PCR_MUX(1);          
	
	// Set ports to outputs
 	PTB->PDDR |= MASK(RED_LED_POS) | MASK(GREEN_LED_POS) | MASK(BLUE_LED_POS);
	
	Control_RGB_LEDs(0,0,0);
}

	
void Init_Switch ( void ) {
	PORTB->PCR[SW_1] &= ~PORT_PCR_MUX_MASK;          
	PORTB->PCR[SW_1] |= PORT_PCR_MUX(1);
	
	PTB->PDDR &= ~MASK(SW_1);
}

void Init_Seven_Segment_Display ( void ) {	
	
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK; //enable clock on port E
	
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
	
	PTE->PDDR |= MASK(a) | MASK(b) | MASK(c) | MASK(d) | MASK(e) | MASK(f) | 
							 MASK(g) | MASK(DP); //set SevSegDisp I/O to output
	
	PTE->PSOR = MASK(a); //initialize to 0
	PTE->PSOR = MASK(b);
	PTE->PSOR = MASK(c);
	PTE->PSOR = MASK(d);
	PTE->PSOR = MASK(e);
	PTE->PSOR = MASK(f);
	PTE->PSOR = MASK(g);
	PTE->PCOR = MASK(DP); //initialize to 1

}

// read output from water level sensor 1
unsigned Measure_WATER_LEV1 (void) {
	volatile unsigned lev1 = 0; // create an unsigned integer to store digital value for water level sensor 1
	ADC0->SC1[0] = WATER_LEV1_CHANNEL; // start conversion for water level sensor 1 on ADC0 channel 0
	while(!(ADC0->SC1[0] & ADC_SC1_COCO_MASK))
		; // Wait for conversion to complete
	lev1 = ADC0->R[0]; // store result from data result register in integer lev1
	return lev1;
}

// read output from water level sensor 2
unsigned Measure_WATER_LEV2 (void) {
	volatile unsigned lev2 = 0; // create an unsigned integer to store digital value for water level sensor 2
	ADC0->SC1[0] = WATER_LEV2_CHANNEL; // start conversion for water level sensor 2 on ADC0 channel 1
	while(!(ADC0->SC1[0] & ADC_SC1_COCO_MASK))
		; // Wait for conversion to complete
	lev2 = ADC0->R[0]; // store result from data result register in integer lev2
	return lev2;
}

void Seven_Segment_Display ( int num ) {
	if(num==0){ 
		PTE->PCOR = MASK(a);
		PTE->PCOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PCOR = MASK(d);
		PTE->PCOR = MASK(e);
		PTE->PCOR = MASK(f);
		PTE->PSOR = MASK(g);
	}
	
	else if(num==1){ 
		PTE->PSOR = MASK(a);
		PTE->PCOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PSOR = MASK(d);
		PTE->PSOR = MASK(e);
		PTE->PSOR = MASK(f);
		PTE->PSOR = MASK(g);
	}
	
	else if(num==2){ 
		PTE->PCOR = MASK(a);
		PTE->PCOR = MASK(b);
		PTE->PSOR = MASK(c);
		PTE->PCOR = MASK(d);
		PTE->PCOR = MASK(e);
		PTE->PSOR = MASK(f);
		PTE->PCOR = MASK(g);
	}
	
	else if(num==3){ 
		PTE->PCOR = MASK(a);
		PTE->PCOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PCOR = MASK(d);
		PTE->PSOR = MASK(e);
		PTE->PSOR = MASK(f);
		PTE->PCOR = MASK(g);
	}
	
	else if(num==4){ 
		PTE->PSOR = MASK(a);
		PTE->PCOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PSOR = MASK(d);
		PTE->PSOR = MASK(e);
		PTE->PCOR = MASK(f);
		PTE->PCOR = MASK(g);
	}
	
	else if(num==5){ 
		PTE->PCOR = MASK(a);
		PTE->PSOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PCOR = MASK(d);
		PTE->PSOR = MASK(e);
		PTE->PCOR = MASK(f);
		PTE->PCOR = MASK(g);
	}
	
	else if(num==6){ 
		PTE->PCOR = MASK(a);
		PTE->PSOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PCOR = MASK(d);
		PTE->PCOR = MASK(e);
		PTE->PCOR = MASK(f);
		PTE->PCOR = MASK(g);
	}
	
	else if(num==7){ 
		PTE->PCOR = MASK(a);
		PTE->PCOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PSOR = MASK(d);
		PTE->PSOR = MASK(e);
		PTE->PSOR = MASK(f);
		PTE->PSOR = MASK(g);
	}
	
	else if(num==8){ 
		PTE->PCOR = MASK(a);
		PTE->PCOR = MASK(b);
		PTE->PCOR = MASK(c);
		PTE->PCOR = MASK(d);
		PTE->PCOR = MASK(e);
		PTE->PCOR = MASK(f);
		PTE->PCOR = MASK(g);
	}
	
	else if(num==9){ 
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

void seven_segment_water_level ( void ) {
		if(lev1 < 4000) Seven_Segment_Display(0);
		else if(lev1 < 5500) Seven_Segment_Display(1);
		else if(lev1 < 7000) Seven_Segment_Display(2);
		else if(lev1 < 9000) Seven_Segment_Display(3);
		else if(lev1 < 10500) Seven_Segment_Display(4);
		else if(lev1 < 12000) Seven_Segment_Display(5);
		else if(lev1 < 13500) Seven_Segment_Display(6);
		else if(lev1 < 15000) Seven_Segment_Display(7);
		else if(lev1 < 17000) Seven_Segment_Display(8);
		else if(lev1 < 19000) Seven_Segment_Display(9);
		else Seven_Segment_Display(10);
}

void Delay( volatile unsigned int time_del ) {
	while(time_del--) { }
}
