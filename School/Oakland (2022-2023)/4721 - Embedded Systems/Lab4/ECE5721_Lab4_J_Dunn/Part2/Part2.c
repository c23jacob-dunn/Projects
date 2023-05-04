/*
Programmer: Jacob Dunn
Date: 4Apr2023
Class: ECE4721 Winter
Title: Proximity Detector
*/

#include "MKL25Z4.h"
#define MASK(x) (1UL << (x))


void Init_ADC(void);
void Init_RGB_LEDs(void);
void Init_IR_LED(void);
void Control_RGB_LEDs(int RED, int GREEN, int BLUE);
void Control_IR_LED(unsigned int led_on);
unsigned int Measure_IR(void);
void Display_Range(int b);
void Delay( volatile unsigned int time_del);


#define NUM_RANGE_STEPS 6
#define T_DELAY_OFF 1000
#define T_DELAY_ON 1000
#define NUM_SAMPLES_TO_AVG 10

#define IR_LED_POS 21 //PE7
#define RED_LED_POS 29 //PE4
#define GREEN_LED_POS 23 //PE3
#define BLUE_LED_POS 22 //PE0
#define IR_PHOTOTRANSISTOR_CHANNEL 30 //PE5

#define RED 1
#define GREEN 0
#define BLUE 2

static int Threshold[NUM_RANGE_STEPS] = {34000, 27000, 20000, 14000, 8000, 0};

static const int Colors[NUM_RANGE_STEPS][3] = {{1,1,1}, //white
																						 	 {1,0,1}, //magenta
																						 	 {1,0,0}, //red
																						 	 {1,1,0}, //yellow
																							 {0,0,1}, //blue
																							 {0,1,0}  //green
};


int main (void) {
	static unsigned int on_brightness=0, off_brightness=0;
	static int avg_diff;
	static int diff;
	unsigned n;
	
	Init_ADC();
	Init_RGB_LEDs();
	Init_IR_LED();

 	while(1) {
		diff=0;
		for(n=0; n<NUM_SAMPLES_TO_AVG; n++) {
			//measure IR level with IRLED off
			Control_IR_LED(0);
			Delay(T_DELAY_OFF);
			on_brightness = Measure_IR();
			
			//measure IR level with IRLED on
			Control_IR_LED(1);
			Delay(T_DELAY_ON);
			on_brightness = Measure_IR();
			
			//calculate difference
			diff += on_brightness - off_brightness;
		}
		//calc average difference
		avg_diff = diff/NUM_SAMPLES_TO_AVG;
		//light RGB LED according to range
		Display_Range(avg_diff);
	}
}

void Init_ADC(void) {
	
	SIM->SCGC6 |= (1UL << SIM_SCGC6_ADC0_SHIFT);
	
	//low power, long sample time, 16 bit single end conversion, bus clock input
	ADC0->CFG1 = ADC_CFG1_ADLPC_MASK | ADC_CFG1_ADIV(0) | ADC_CFG1_ADLSMP_MASK | ADC_CFG1_MODE(3) | ADC_CFG1_ADICLK(0); //16 bit conversion
	ADC0->SC2 = ADC_SC2_REFSEL(0); //default voltage reference pins
}

void Init_RGB_LEDs(void){
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK; //enable clock on port E
	
	PORTE->PCR[RED_LED_POS] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[RED_LED_POS] |= PORT_PCR_MUX(1);
	PORTE->PCR[GREEN_LED_POS] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[GREEN_LED_POS] |= PORT_PCR_MUX(1);
	PORTE->PCR[BLUE_LED_POS] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[BLUE_LED_POS] |= PORT_PCR_MUX(1);
	
	PTE->PDDR |= MASK(RED_LED_POS) | MASK(GREEN_LED_POS) | MASK(BLUE_LED_POS);
	
	Control_RGB_LEDs(0,0,0); //start with turned off	
}

void Init_IR_LED(void){
	PORTE->PCR[IR_LED_POS] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[IR_LED_POS] |= PORT_PCR_MUX(1);
	
	PTE->PDDR |= MASK(IR_LED_POS);
	
	Control_IR_LED(0); //start with turned off
}

void Control_RGB_LEDs(int r_on, int g_on, int b_on){
	if(r_on){
		PTE->PSOR = MASK(RED_LED_POS);
	}
	else{
		PTE->PCOR = MASK(RED_LED_POS);
	}
	
	if(g_on){
		PTE->PCOR = MASK(GREEN_LED_POS);
	}
	else{
		PTE->PSOR = MASK(GREEN_LED_POS);
	}
	
	if(b_on){
		PTE->PCOR = MASK(BLUE_LED_POS);
	}
	else{
		PTE->PSOR = MASK(BLUE_LED_POS);
	}
}

void Control_IR_LED(unsigned int led_on){
	if(led_on){
		PTE->PCOR = MASK(IR_LED_POS);
	}
	else{
		PTE->PSOR = MASK(IR_LED_POS);
	}
}

unsigned int Measure_IR(void){
	volatile unsigned res=0;
	
	ADC0->SC1[0] = IR_PHOTOTRANSISTOR_CHANNEL;
	
	while(!(ADC0->SC1[0] & ADC_SC1_COCO_MASK));
	
	res = ADC0->R[0];
	
	return 0xFFFF-res;
}

void Display_Range(int b) {
	unsigned i;
	for(i=0; i<NUM_RANGE_STEPS-1; i++) {
		if(b>Threshold[i])
			break;
	}
	
	Control_RGB_LEDs(Colors[i][RED], Colors[i][GREEN], Colors[i][BLUE]);
}

void Delay( volatile unsigned int time_del) {
	while(time_del--) { }
}
