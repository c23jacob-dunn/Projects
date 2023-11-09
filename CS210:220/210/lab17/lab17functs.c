/** lab17functs.h
* ==============================================================
* Name: Jacob Dunn / 27 SEP 20
* Section: M3/4
* Project: Lab17
* Purpose: Programming Practice
* ==============================================================
*/

#include "lab17functs.h"

int loadVals(int fillArray[])
{
    int currentVal = 0;
    int i = 0;
    int j = 0;
    while (j >= 0)
    {
        printf("Enter Value: ");
        scanf("%d", &currentVal);
        if(currentVal >= 0)
        {
            fillArray[i] = currentVal;
            ++i;
        }
        else
        {
            j = -1;
        }
    }
    return i;
}

void reversePrint(int fillArray[], int arrayLength)
{
    int i = arrayLength - 1;
    while(i >= 0)
    {
        printf("%d\n", fillArray[i]);
        i = i - 2;
    }
    printf("\n");
}

int countVowels(char stringInput[])
{
    int i=0;
    int count = 0;
    for (i=0; stringInput[i] != '\0'; ++i)
    {
        if(stringInput[i] == 'a' || stringInput[i] == 'e' || stringInput[i] == 'i' || stringInput[i] == 'o' || stringInput[i] == 'u' || stringInput[i] == 'y')
        {
            ++count;
        }
    }
    
    return count;
}

void captureOhms(double resVals[NUM_RES])
{
    int i = 0;
    double userInput = 0;
    for (i = 0; i < NUM_RES; ++i)
    {
        printf("Enter a value to add to resVals: ");
        scanf("%lf", &userInput);
        resVals[i] = userInput;
    }
    printf("\n\n");
    
}

void calculateCurrent(int resVals[], int circVolt, int* currentVal)
{
    int i = 0;
    int resistorSum = 0;
    for(i=0; i < NUM_RES; ++i)
    {
        resistorSum = resistorSum + resVals[i];
    }
    *currentVal = circVolt / resistorSum;
}

void voltageDrop(double vDrop[], double resVals[], double current)
{
    int i = 0;
    for(i = 0; i < NUM_RES; ++i)
    {
        vDrop[i] = resVals[i] * current;
    }
}

void printDrop(int vDrop[])
{
    int i = 0;
    while (i < NUM_RES)
    {
        printf("%d V\n", vDrop[i]);
        ++i;
    }
    printf("\n");
}

int performOperation(char opInput, int opInput1, int opInput2)
{
    int sum = 0;
    switch(opInput)
    {
        case '+':
            sum = opInput1 + opInput2;
            break;
        case '-':
            sum = opInput1 - opInput2;
            break;
        case '*':
            sum = opInput1 * opInput2;
            break;
        case '/':
            sum = opInput1 / opInput2;
            break;
        default:
            break;
    }
    return sum;
}

void getMinMax(int MMArray[], int MMInput, int *MMpointer1, int *MMpointer2)
{
    int i = 0;
    int min = 999999;
    int max = 0;
    for(i=0; i < MMInput; ++i)
    {
        if(MMArray[i] > max)
        {
            max = MMArray[i];
        }
        if(MMArray[i] < min)
        {
            min = MMArray[i];
        }
    }
    *MMpointer1 = min;
    *MMpointer2 = max;
}
