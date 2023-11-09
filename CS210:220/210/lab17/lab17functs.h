/** lab17functs.h
* ==============================================================
* Name: Jacob Dunn / 27 SEP 20
* Section: M3/4
* Project: Lab17
* Purpose: Programming Practice
* ==============================================================
*/

#ifndef PEX1FUNCTS_H
#define PEX1FUNCTS_H
#include <stdio.h>
#include <string.h>
#define NUM_RES 5


int loadVals(int fillArray[]);
void reversePrint(int fillArray[], int arrayLength);

int countVowels(char stringInput[]);

void captureOhms(double resVals[NUM_RES]);
void calculateCurrent(int resVals[], int circVolt, int* currentVal);
void voltageDrop(double vDrop[], double resVals[], double current);
void printDrop(int vDrop[]);

int performOperation(char opInput, int opInput1, int opInput2);

void getMinMax(int MMArray[], int MMInput, int *MMpointer1, int *MMpointer2);


#endif