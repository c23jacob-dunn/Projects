/** lab12.c
* ===========================================================
* Name: Jacob Dunn / 12 SEP 2020
* Section: M3
* Project: Lab12
* Purpose: Learn Code
* ===========================================================
*/

#include "lab12functs.h"

int main(){


    int userInput;
    printf("Enter userInput: \n");
    scanf("%d", &userInput);
    if (isArmstrong(userInput) == 1){
        printf("%d is an Armstrong number.\n\n", userInput);
    }
    else{
        printf("%d is not an Armstrong number.\n\n", userInput);
    }


    int input1, input2;
    printf("Enter input1 and input2: \n");
    scanf("%d %d", &input1, &input2);
    printf("GCD = %d\n\n", findGCD(input1, input2));


    int rangeInput1, rangeInput2;
    printf("Enter range inputs: \n");
    scanf("%d %d", &rangeInput1, &rangeInput2);
    printRange(rangeInput1, rangeInput2);


    char c;
    scanf(" %c", &c);

    return 0;

}