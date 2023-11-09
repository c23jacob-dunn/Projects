/** lab17functs.h
* ==============================================================
* Name: Jacob Dunn / 27 SEP 20
* Section: M3/4
* Project: Lab17
* Purpose: Programming Practice
* Documentation Statement: Garth Knutson explained pointers 
  further on these examples as well as assited with debugging 
  these functions so that they worked before PA #2
* ==============================================================
*/

#include "lab17functs.h"

int main()
{
    int fillArray[20];
    int arrayLength = loadVals(fillArray);
    printf("Num values in array: %d\n\n", arrayLength);
    reversePrint(fillArray, arrayLength);

    char stringInput[] = "hello, this is a test.";
    printf("The number of vowels is: %d\n\n", countVowels(stringInput));

    double resVals[NUM_RES];
    double circVolt = 12;
    double vDrop[NUM_RES];
    double currentVal;
    captureOhms(resVals);
    calculateCurrent(resVals, circVolt, &currentVal);
    voltageDrop(vDrop, resVals, currentVal);
    printDrop(vDrop);

    int userInput;
    scanf("%d", &userInput);
    switch(userInput)
    {
        case 10:
            printf("Outstanding\n\n");
            break;
        case 9:
        case 8:
            printf("Excellent\n\n");
            break;
        case 7:
        case 6:
            printf("Good\n\n");
            break;
        case 5:
            printf("Average\n\n");
            break;
        case 4:
        case 3:
            printf("Below Average\n\n");
            break;
        case 2:
        case 1:
            printf("Awful\n\n");
            break;
        case 0:
            printf("Horrible\n\n");
            break;
        default:
            printf("You did not enter a value between 0 and 10.\n\n");
            break;
    }

    char opInput;
    int opInput1, opInput2;
    printf("%d", performOperation(opInput, opInput1, opInput2));

    int MMArray[NUM_RES];
    int MMInput;
    int *MMpointer1;
    int *MMpointer2;
    getMinMax(MMArray, MMInput, *MMpointer1, *MMpointer2);

    return 0;
}