/** lab10.c
* ===========================================================
* Name: Jacob Dunn / 9 SEP 2020
* Section: M3
* Project: Lab10
* Purpose: Learn Code
* ===========================================================
*/

#include "lab10functs.h"

int main() {

    char alpha, bravo, charlie;
    /*assert(isFirstHalfAlpha(65) == true);
    assert(isFirstHalfAlpha(80) == false);

    assert(typeOfChar('a') == 1);
    assert(typeOfChar('b') == 0);

    assert(isMagicChar('@') == true);
    assert(isMagicChar('$') == false);*/

    printf("Enter a single character to pass to isFirstHalfAlpha():\n");
    scanf(" %c", &alpha);
    //isFirstHalfAlpha(alpha);
    if (isFirstHalfAlpha(alpha) == true){
        printf("A %c is in the first half of the alphabet.\n", alpha);
    }
    else{
        printf("A %c is NOT in the first half of the alphabet.\n", alpha);
    }


    printf("Enter a single character to pass to typeOfChar():\n");
    scanf(" %c", &bravo);
    //typeOfChar(bravo);
    if (typeOfChar(bravo) == 1){
        printf("A %c is a vowel.\n", bravo);
    }
    else if (typeOfChar(bravo) == 0){
        printf("A %c is a consonant.\n", bravo);
    }
    else{
        printf("A %c is neither a vowel nor a consonant.\n", bravo);
    }


    printf("Enter a single character to pass to isMagicChar():\n");
    scanf(" %c", &charlie);
    //isMagicChar(charlie);
    if (isMagicChar(charlie) == true){
        printf("A %c is the magic character %c.", charlie, MAGIC_CHAR);
    }
    else{
        printf("A %c is NOT the magic character %c.", charlie, MAGIC_CHAR);
    }

    char c;
    scanf(" %c", &c);
}