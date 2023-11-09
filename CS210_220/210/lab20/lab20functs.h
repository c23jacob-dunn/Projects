/** lab20functs.h
* ==============================================================
* Name: Jacob Dunn / 4 October 2020
* Section: M3/4
* Project: lab20
* Purpose: Write Code
* ==============================================================
*/

#ifndef LAB20_LAB20FUNCTS_H
#define LAB20_LAB20FUNCTS_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double fToC(double degF);
double cToK(double degC);
void printTable(double degFlow, double degFhigh, double degFstep);
double getInput(char title[], double min, double max);
bool again();
void printLine(char what, int howMany);

#endif