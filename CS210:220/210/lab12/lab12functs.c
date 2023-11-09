/** lab12.c
* ===========================================================
* Name: Jacob Dunn / 12 SEP 2020
* Section: M3
* Project: Lab12
* Purpose: Learn Code
* ===========================================================
*/

#include "lab12functs.h"

int isArmstrong(int userInput){
    /*switch(userInput){
        case 0:
        case 1:
        case 153:
        case 370:
        case 371:
        case 407:
            return 1;
            break;
        default:
            return 0;
            break;
    }*/

    int rightNumber;
    int sum = 0;
    int user = userInput;

    while(user>0){
        rightNumber = user % 10;
        sum = sum + (rightNumber*rightNumber*rightNumber);
        user = user / 10;
    }

    if (userInput == sum){
        return 1;
    }
    else {
        return 0;
    }

}


int findGCD(int input1, int input2){
    int GCD;
    int i = 1;
    char userChar;

        if(input1 < input2){
            while(i<=input1){
                if((input1 % i == 0) && (input2 % i == 0)){
                    GCD = i;
                }
                else{
                    GCD = GCD;
                }
                ++i;
            }
        }

        else{
            while(i<=input2){
                if((input2 % i ==0) && (input1 % i == 0)){
                    GCD = i;
                }
                else{
                    GCD = GCD;
                }
                ++i;
            }
        }
    return GCD;
}


void printRange(int rangeInput1, int rangeInput2){
    int i = rangeInput1;
    while(i<=rangeInput2){
        printf("%d\n", i);
        ++i;        
    }

}