/** lab20functs.h
* ==============================================================
* Name: Jacob Dunn / 4 October 2020
* Section: M3/4
* Project: lab20
* Purpose: Write Code
* Documentation Statement: None
* ==============================================================
*/

#include <stdio.h>
#include "lab20functs.h"

int main() 
{
    /*double degF, degC;
    fscanf(stdin, "%lf %lf", &degF, &degC);
    fprintf(stdout, "%.2lf\n%.2lf", fToC(degF), cToK(degC));*/
    double minF=0.0, maxF=0.0, stepF=0.0;
    do
    {
        minF = getInput("Minimum Farenheit temperature: ", -459.67, 10706.0);
        maxF = getInput("Maximum Farenheit temperature: ", minF,10706.0);
        stepF = getInput("What step size: ", 0, (maxF - minF)/2);
        printTable(minF, maxF, stepF);
    }
    while(again());
    return 0;
}