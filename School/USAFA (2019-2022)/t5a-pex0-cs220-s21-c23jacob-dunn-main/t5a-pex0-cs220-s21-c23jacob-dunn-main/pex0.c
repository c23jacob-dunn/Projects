// Be sure to follow DFCS Programming Standard COMPLETELY

/** pex0.c
 * =========================================================== 
 * Name: Jacob Dunn, 10 Jan 21
 * Section: T5A 
 * Project: PEX0
 * Purpose: high level description of purpose of the program 
 *          could be multiple lines
 * Documentation Statement: NONE. 
 * =========================================================== */

#include "pex0functs.h"

int main(int argc, char *argv[]){

    char sentence1[SENTLENGTH];
    printf("Enter sentence 1: ");
    fgets(sentence1, SENTLENGTH, stdin);

    parseIt(sentence1);
    printf("%s", sentence1);

    char sentence2[SENTLENGTH];
    printf("Enter sentence 2: ");
    fgets(sentence2, SENTLENGTH, stdin);

    modifyIt(sentence2);
    printf("%s", sentence2);

    StudentRecType *variable;
    getInfo(variable);
    printf("%s %d", variable->name, variable->age);

    //I cannot figure out dynamically declaring 2d array with the authorized resources.

    /*int *twoDArray = malloc(argv[2] * sizeof(int));
    fillIt(twoDArray);

    dumpIt(twoDArray, argv[1]);*/

    printf("This assignment took 110 minutes to complete.");
}