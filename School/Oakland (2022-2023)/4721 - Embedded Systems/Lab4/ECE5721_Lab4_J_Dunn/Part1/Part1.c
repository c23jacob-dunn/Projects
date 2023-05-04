/*
Programmer: Jacob Dunn
Date: 4Apr2023
Class: ECE4721 Winter
Title: Thermistor with 7 Segment Displays
*/

#include "MKL25Z4.h"
#include "math.h"
#define MASK(x) (1UL << (x))


void Init_ADC(void);
void Init_SevenSegmentDisplay(void);
float Measure_Temperature(void);
void Seven_Segment_Display(int port, int number, int a, int b, int c, int d, int e, int f, int g);
void Delay(volatile unsigned int time_del);


#define ADC_POS (9) //PORTC

#define a1 (4) //PORTE
#define b1 (29)
#define c1 (22)
#define d1 (20)
#define e1 (2)
#define f1 (5)
#define g1 (23)
#define DP1 (21)

#define a2 (11) //PORTC
#define b2 (5)
#define c2 (3)
#define d2 (7)
#define e2 (6)
#define f2 (10)
#define g2 (4)
#define DP2 (0)

#define port1 1 //identifiers for different 7seg displays
#define port2 2

static int number1 = 0; //number to be passed to 7seg display
static int number2 = 0;


int main (void) {
	Init_ADC();
	Init_SevenSegmentDisplay();
	
	while(1){
		float temp = Measure_Temperature();
		
		number2 = (int)temp % 10; //gets the digit in the ones place
		number1 = ((int)temp - number2) / 10; //gets the digit in the tens place
		
		Seven_Segment_Display(port1, number1, a1, b1, c1, d1, e1, f1, g1);
		Seven_Segment_Display(port2, number2, a2, b2, c2, d2, e2, f2, g2);
		
		Delay(500000);
	}
}

void Init_ADC(void) {
	
	SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK;
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
	
	//select analog
	PORTC->PCR[ADC_POS] &= ~PORT_PCR_MUX_MASK;
	PORTC->PCR[ADC_POS] |= PORT_PCR_MUX(0);
	
	//low power, long sample time, 16 bit single end conversion, bus clock input
	ADC0->CFG1 = ADC_CFG1_ADLPC_MASK | ADC_CFG1_ADLSMP_MASK | ADC_CFG1_MODE(3) | ADC_CFG1_ADICLK(0);
	
	//software trigger, compare function disabled, DMA disabled, VREFH and VREFL
	ADC0->SC2 = ADC_SC2_REFSEL(0);
}

void Init_SevenSegmentDisplay(void) {

	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK | SIM_SCGC5_PORTC_MASK; //enable clock on port E and C
	
	PORTE->PCR[a1] &= ~PORT_PCR_MUX_MASK; //clear analog
	PORTE->PCR[a1] |= PORT_PCR_MUX(1); //set analog
	PORTE->PCR[b1] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[b1] |= PORT_PCR_MUX(1);
	PORTE->PCR[c1] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[c1] |= PORT_PCR_MUX(1);
	PORTE->PCR[d1] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[d1] |= PORT_PCR_MUX(1);
	PORTE->PCR[e1] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[e1] |= PORT_PCR_MUX(1);
	PORTE->PCR[f1] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[f1] |= PORT_PCR_MUX(1);
	PORTE->PCR[g1] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[g1] |= PORT_PCR_MUX(1);
	PORTE->PCR[DP1] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[DP1] |= PORT_PCR_MUX(1);
	
	PORTC->PCR[a2] &= ~PORT_PCR_MUX_MASK;
	PORTC->PCR[a2] |= PORT_PCR_MUX(1);
	PORTC->PCR[b2] &= ~PORT_PCR_MUX_MASK;
	PORTC->PCR[b2] |= PORT_PCR_MUX(1);
	PORTC->PCR[c2] &= ~PORT_PCR_MUX_MASK;
	PORTC->PCR[c2] |= PORT_PCR_MUX(1);
	PORTC->PCR[d2] &= ~PORT_PCR_MUX_MASK;
	PORTC->PCR[d2] |= PORT_PCR_MUX(1);
	PORTC->PCR[e2] &= ~PORT_PCR_MUX_MASK;
	PORTC->PCR[e2] |= PORT_PCR_MUX(1);
	PORTC->PCR[f2] &= ~PORT_PCR_MUX_MASK;
	PORTC->PCR[f2] |= PORT_PCR_MUX(1);
	PORTC->PCR[g2] &= ~PORT_PCR_MUX_MASK;
	PORTC->PCR[g2] |= PORT_PCR_MUX(1);
	PORTC->PCR[DP2] &= ~PORT_PCR_MUX_MASK;
	PORTC->PCR[DP2] |= PORT_PCR_MUX(1);
	
	PTE->PDDR |= MASK(a1) | MASK(b1) | MASK(c1) | MASK(d1) | MASK(e1) | MASK(f1) | MASK(g1) | MASK(DP1); //set SevSegDisp I/O to output
	PTC->PDDR |= MASK(a2) | MASK(b2) | MASK(c2) | MASK(d2) | MASK(e2) | MASK(f2) | MASK(g2) | MASK(DP2); //set SevSegDisp I/O to output
	
	PTE->PSOR = MASK(a1); //initialize to 0
	PTE->PSOR = MASK(b1);
	PTE->PSOR = MASK(c1);
	PTE->PSOR = MASK(d1);
	PTE->PSOR = MASK(e1);
	PTE->PSOR = MASK(f1);
	PTE->PSOR = MASK(g1);
	PTE->PSOR = MASK(DP1); //initialize to 0
	
	PTC->PSOR = MASK(a2); //initialize to 0
	PTC->PSOR = MASK(b2);
	PTC->PSOR = MASK(c2);
	PTC->PSOR = MASK(d2);
	PTC->PSOR = MASK(e2);
	PTC->PSOR = MASK(f2);
	PTC->PSOR = MASK(g2);
	PTC->PCOR = MASK(DP2); //initialize to 1
}

float Measure_Temperature(void) {
	float n=0, temp=0, r1 = 5000, thermVolt, thermRes;
	
	ADC0->SC1[0] = 0x00; //start conversion on channel 0
	
	//wait for conversion to finish
	while(!(ADC0->SC1[0] & ADC_SC1_COCO_MASK));
		
	//read result convert to float
	n = (float) ADC0->R[0];
	
	//convert to a voltage
	thermVolt = n*(3.3/(pow(2,16)-1)); //CHANGE TO WHATEVER THAT OTHER VALUE WAS?
	
	//thermistor resistance
	thermRes = r1*((3.3/thermVolt)-1); //CHANGE REF VOLTAGE?
	
	//calc temp (K) using poly equation,
	//assumes ADC is in 16 bit mode, VRef = 3.3V
	temp = (1/(3.354016E-03) + (2.909670E-04*log(thermRes/1000)) + (1.632136E-06*(pow(log(thermRes/1000), 2))) + (7.192200E-08*(pow(log(thermRes/1000), 3))));
	//temp = (1/(3.354016E-03) + (2.909670E-04*log(1000/5000)) + (1.632136E-06*(pow(log(1000/5000), 2))) + (7.192200E-08*(pow(log(1000/5000), 3))));

	//temp in C
	temp = temp - 273.15;
	
	return temp;
}

void Seven_Segment_Display(int port, int number, int a, int b, int c, int d, int e, int f, int g) {
	
	if(port == 1){ //7seg display for tens digit
		if(number == 0){ 
			PTE->PCOR = MASK(a);
			PTE->PCOR = MASK(b);
			PTE->PCOR = MASK(c);
			PTE->PCOR = MASK(d);
			PTE->PCOR = MASK(e);
			PTE->PCOR = MASK(f);
			PTE->PSOR = MASK(g);
		}
		
		else if(number == 1){ 
			PTE->PSOR = MASK(a);
			PTE->PCOR = MASK(b);
			PTE->PCOR = MASK(c);
			PTE->PSOR = MASK(d);
			PTE->PSOR = MASK(e);
			PTE->PSOR = MASK(f);
			PTE->PSOR = MASK(g);
		}
		
		else if(number == 2){ 
			PTE->PCOR = MASK(a);
			PTE->PCOR = MASK(b);
			PTE->PSOR = MASK(c);
			PTE->PCOR = MASK(d);
			PTE->PCOR = MASK(e);
			PTE->PSOR = MASK(f);
			PTE->PCOR = MASK(g);
		}
		
		else if(number == 3){ 
			PTE->PCOR = MASK(a);
			PTE->PCOR = MASK(b);
			PTE->PCOR = MASK(c);
			PTE->PCOR = MASK(d);
			PTE->PSOR = MASK(e);
			PTE->PSOR = MASK(f);
			PTE->PCOR = MASK(g);
		}
		
		else if(number == 4){ 
			PTE->PSOR = MASK(a);
			PTE->PCOR = MASK(b);
			PTE->PCOR = MASK(c);
			PTE->PSOR = MASK(d);
			PTE->PSOR = MASK(e);
			PTE->PCOR = MASK(f);
			PTE->PCOR = MASK(g);
		}
		
		else if(number == 5){ 
			PTE->PCOR = MASK(a);
			PTE->PSOR = MASK(b);
			PTE->PCOR = MASK(c);
			PTE->PCOR = MASK(d);
			PTE->PSOR = MASK(e);
			PTE->PCOR = MASK(f);
			PTE->PCOR = MASK(g);
		}
		
		else if(number == 6){ 
			PTE->PCOR = MASK(a);
			PTE->PSOR = MASK(b);
			PTE->PCOR = MASK(c);
			PTE->PCOR = MASK(d);
			PTE->PCOR = MASK(e);
			PTE->PCOR = MASK(f);
			PTE->PCOR = MASK(g);
		}
		
		else if(number == 7){ 
			PTE->PCOR = MASK(a);
			PTE->PCOR = MASK(b);
			PTE->PCOR = MASK(c);
			PTE->PSOR = MASK(d);
			PTE->PSOR = MASK(e);
			PTE->PSOR = MASK(f);
			PTE->PSOR = MASK(g);
		}
		
		else if(number == 8){ 
			PTE->PCOR = MASK(a);
			PTE->PCOR = MASK(b);
			PTE->PCOR = MASK(c);
			PTE->PCOR = MASK(d);
			PTE->PCOR = MASK(e);
			PTE->PCOR = MASK(f);
			PTE->PCOR = MASK(g);
		}
		
		else if(number == 9){ 
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
	
	else if (port == 2) { //7seg display for ones digit
		if(number == 0){ 
			PTC->PCOR = MASK(a);
			PTC->PCOR = MASK(b);
			PTC->PCOR = MASK(c);
			PTC->PCOR = MASK(d);
			PTC->PCOR = MASK(e);
			PTC->PCOR = MASK(f);
			PTC->PSOR = MASK(g);
		}
		
		else if(number == 1){ 
			PTC->PSOR = MASK(a);
			PTC->PCOR = MASK(b);
			PTC->PCOR = MASK(c);
			PTC->PSOR = MASK(d);
			PTC->PSOR = MASK(e);
			PTC->PSOR = MASK(f);
			PTC->PSOR = MASK(g);
		}
		
		else if(number == 2){ 
			PTC->PCOR = MASK(a);
			PTC->PCOR = MASK(b);
			PTC->PSOR = MASK(c);
			PTC->PCOR = MASK(d);
			PTC->PCOR = MASK(e);
			PTC->PSOR = MASK(f);
			PTC->PCOR = MASK(g);
		}
		
		else if(number == 3){ 
			PTC->PCOR = MASK(a);
			PTC->PCOR = MASK(b);
			PTC->PCOR = MASK(c);
			PTC->PCOR = MASK(d);
			PTC->PSOR = MASK(e);
			PTC->PSOR = MASK(f);
			PTC->PCOR = MASK(g);
		}
		
		else if(number == 4){ 
			PTC->PSOR = MASK(a);
			PTC->PCOR = MASK(b);
			PTC->PCOR = MASK(c);
			PTC->PSOR = MASK(d);
			PTC->PSOR = MASK(e);
			PTC->PCOR = MASK(f);
			PTC->PCOR = MASK(g);
		}
		
		else if(number == 5){ 
			PTC->PCOR = MASK(a);
			PTC->PSOR = MASK(b);
			PTC->PCOR = MASK(c);
			PTC->PCOR = MASK(d);
			PTC->PSOR = MASK(e);
			PTC->PCOR = MASK(f);
			PTC->PCOR = MASK(g);
		}
		
		else if(number == 6){ 
			PTC->PCOR = MASK(a);
			PTC->PSOR = MASK(b);
			PTC->PCOR = MASK(c);
			PTC->PCOR = MASK(d);
			PTC->PCOR = MASK(e);
			PTC->PCOR = MASK(f);
			PTC->PCOR = MASK(g);
		}
		
		else if(number == 7){ 
			PTC->PCOR = MASK(a);
			PTC->PCOR = MASK(b);
			PTC->PCOR = MASK(c);
			PTC->PSOR = MASK(d);
			PTC->PSOR = MASK(e);
			PTC->PSOR = MASK(f);
			PTC->PSOR = MASK(g);
		}
		
		else if(number == 8){ 
			PTC->PCOR = MASK(a);
			PTC->PCOR = MASK(b);
			PTC->PCOR = MASK(c);
			PTC->PCOR = MASK(d);
			PTC->PCOR = MASK(e);
			PTC->PCOR = MASK(f);
			PTC->PCOR = MASK(g);
		}
		
		else if(number == 9){ 
			PTC->PCOR = MASK(a);
			PTC->PCOR = MASK(b);
			PTC->PCOR = MASK(c);
			PTC->PSOR = MASK(d);
			PTC->PSOR = MASK(e);
			PTC->PCOR = MASK(f);
			PTC->PCOR = MASK(g);
		}
		
		else { //10+
			PTC->PSOR = MASK(a);
			PTC->PSOR = MASK(b);
			PTC->PSOR = MASK(c);
			PTC->PSOR = MASK(d);
			PTC->PSOR = MASK(e);
			PTC->PSOR = MASK(f);
			PTC->PSOR = MASK(g);
		}
	}
}

void Delay( volatile unsigned int time_del) {
	while(time_del--) { }
}
