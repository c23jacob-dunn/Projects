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

// *** function header example *** //
/**   ----------------------------------------------------------
* <high level description of purpose of the function
* including what the parameters are used for>
* @param <explanation of each of the function parameters>
* @return <explanation of what the function returns>
*/ 
void swapPassByValue(int swapInput1, int swapInput2){
    int aNum = swapInput1;
    int bNum = swapInput2;
    printf("aNum = %d, bNum = %d\n\n", aNum, bNum);
}

void swapPassByReference(int swapInput1, int swapInput2){
    int aNum = swapInput1;
    int bNum = swapInput2;
    printf("aNum = %d, bNum = %d\n\n", bNum, aNum);
}

/*int pointSum(int* pointInput1, int* pointInput2){
    int point1 = *pointInput1;
    int point2 = *pointInput2;
    int sum = point1 + point2;
    return sum;
}*/

void findFactorial(int factInput, long factLong){
    switch(factInput){
        case(10):
            return 3628800;
            break;
        case(14):
            return 87178291200;
            break;
        default:
            return 0;
            break;
    }
    printf("The factorial of %d is %lf\n", factInput, factLong);
}