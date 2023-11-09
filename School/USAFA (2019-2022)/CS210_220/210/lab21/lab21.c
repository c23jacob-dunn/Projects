/** lab21.c
* ==============================================================
* Name: Jacob Dunn / 8 Oct 2020
* Section: M3
* Project: Lab21
* Purpose: Write Code
* Documentation Statement: None
* ==============================================================
*/

#include <stdio.h>

int main()
{
    FILE* inFile = NULL;
    FILE* outFile = NULL;
    char* firstName[10], lastName[10];
    int heightFeet[10], heightInches[10], i = 0;
    double weightKgs[10];
    
    inFile = fopen("football.txt", "r");
    outFile = fopen("fbConvert.txt", "w");
    while (i < 2)
    {
        fscanf(inFile, "%s %s %d %d %lf", &firstName[i], &lastName[i], &heightFeet[i], &heightInches[i], &weightKgs[i]);
        weightKgs[i] = weightKgs[i] * 2.204;
        fprintf(outFile, "%s %s %d %d %.1lf\n", &firstName[i], &lastName[i], heightFeet[i], heightInches[i], weightKgs[i]);
        ++i;
    }

    fclose(inFile);
    fclose(outFile);

}