/** lab11.c
* ===========================================================
* Name: Jacob Dunn / 12 SEP 2020
* Section: M3
* Project: Lab11
* Purpose: Learn Code
* ===========================================================
*/

#include "lab11functs.h"

int main(){

    int number1;
    printf("Input Number: \n");
    scanf("%d", &number1);
    printf("The factorial of %d is %d.\n", number1, numFactorial(number1));

    int number2;
    printf("Input Number: \n");
    scanf("%d", &number2);
    if (isPrime(number2) == 1){
        printf("%d is a prime number.\n", number2);
    }
    else{
        printf("%d is not a prime number.\n", number2);
    }

    int number3;
    printf("Input Number: \n");
    scanf("%d", &number3);
    floydsTriangle(number3);

}