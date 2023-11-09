/** lab20functs.h
* ==============================================================
* Name: Jacob Dunn / 4 October 2020
* Section: M3/4
* Project: lab20
* Purpose: Write Code
* ==============================================================
*/

/** @fn functionName
*   @brief function description
*   @param variableName variable description
*   @return describes what function returns
*/

#include "lab20functs.h"

double fToC(double degF)
{ 
    double degC = degF - 32;
    return degC * 5 / 9;
}

double cToK(double degC)
{
    double degK = degC + 273.15;
    return degK;
}

void printTable(double degFlow, double degFhigh, double degFstep)
{
    double degC = (degFlow - 32);
    degC = degC * 5 / 9;
    double degK = degC + 273.15;
    fprintf(stdout, "\n|-----------------------------|\n|                             |\n|   Temperature Conversions   |\n|                             |\n|-----------------------------|\n|Farenheit| Celsius | Kelvin  |\n|-----------------------------|\n");
    while (degFlow <= degFhigh)
    {
        fprintf(stdout, "|%9.2lf|%9.2lf|%9.2lf|\n", degFlow, degC, degK);
        degFlow += degFstep;
        degC = (degFlow - 32);
        degC = degC * 5 / 9;
        degK = degC + 273.15;
    }
    fprintf(stdout, "|-----------------------------|");
}

double getInput(char title[], double min, double max)
{
    double val;
    int variable = 0;
    while (variable == 0)
    {
        fprintf(stdout, "%s", title);
        fscanf(stdin, "%lf", &val);
        if(val > min && val < max)
        {
            variable = 1;
        }
        else
        {
            fprintf(stdout, "Your input is outside of the range %.2lf to %.2lf.\nPlease re-enter.\n", min, max);
            variable = 0;
        }
    }
    return val;
}

bool again()
{
    char c;
    fprintf(stdout, "\n\nWould you like to do this again?\n");
    fscanf(stdin, " %c", &c);
    if (c == 'y' || c == 'Y')
    {
        return true;
    }
    else
    {
        return false;
    }
    fprintf(stdout, "\n");
}