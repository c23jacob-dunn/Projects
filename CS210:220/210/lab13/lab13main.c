/** lab13.c
* ===========================================================
* Name: Jacob Dunn / 15 SEP 2020
* Section: M3
* Project: Lab13
* Purpose: Learn Code
* ===========================================================
*/

#include "lab13functs.h"
#include <stdio.h>

int main(){

    int scanInput1, scanInput2;
    printf("Input class year: ");
    scanf("%d", &scanInput1);
    printf("Input favorite number: ");
    scanf("%d", &scanInput2);
    swapPassByValue(scanInput1, scanInput2);

    swapPassByReference(scanInput1, scanInput2);

    /*int input1, input2;
    int* pointInput1 = NULL;
    int* pointInput2 = NULL;
    printf("Enter point values: ");
    scanf("%d %d", &input1, &input2);
    pointInput1 = &input1;
    pointInput2 = &input2;
    printf("The sum of %d and %d = %d\n\n", input1, input2, pointerSum(pointInput1, pointInput2));*/

    int factInput;
    long factLong;
    printf("Enter int: ");
    scanf("%d", &factInput);
    findFactorial(factInput, factLong);

    return 0;
}