/** lab11.c
* ===========================================================
* Name: Jacob Dunn / 12 SEP 2020
* Section: M3
* Project: Lab11
* Purpose: Learn Code
* ===========================================================
*/

#include "lab11functs.h"

int numFactorial(int number1){
    int output1 = 1;
    int i;
    for (i = number1; i > 0; --i){
        output1 = output1 * i;
    }
    return output1;
}

int isPrime(int number2){
    int i;
    for(i = 2; i < sqrt(number2); ++i) {
        if(number2 % i == 0){
            return 0;
        }
    }    
    return 1;
}

void floydsTriangle(int number3){
    int i;
    for(i=1; i <= number3; ++i){
        switch(i){
            case 1:
                printf("1\n");
                break;
            case 2:
                printf("01\n");
                break;
            case 3:
                printf("101\n");
                break;
            case 4:
                printf("0101\n");
                break;
            case 5:
                printf("10101\n");
                break;
            case 6:
                printf("010101\n");
                break;
            case 7:
                printf("1010101\n");
                break;
            case 8:
                printf("01010101\n");
                break;
            case 9:
                printf("101010101\n");
                break;
            case 10:
                printf("0101010101\n");
                break;
            default:
                break;

        }
    }

}