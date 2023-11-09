/** lab19functs.h
* ==============================================================
* Name: Jacob Dunn / 3 October 2020
* Section: M3/4
* Project: lab19
* Purpose: Learn Code
* ==============================================================
*/

#ifndef lab19functs_h
#define lab19functs_h
#define MAX_STR_LEN 81
#include <stdio.h>
#include <string.h>

void replStr(char str[], char aChar, char bChar);
void replMultiChar(char str[], char searchChars[], char rChar);
int findLocations(char str[], int locations[], char searchChar);

#endif