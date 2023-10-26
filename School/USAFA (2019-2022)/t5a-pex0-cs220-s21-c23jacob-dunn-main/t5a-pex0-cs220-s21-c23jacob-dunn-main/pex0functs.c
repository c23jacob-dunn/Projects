// Be sure to follow DFCS Programming Standard COMPLETELY

/** pex0functs.c
 * =========================================================== 
 * Name: Jacob Dunn, 10 Jan 21
 * Section: T5A 
 * Project: PEX0
 * Purpose: high level description of purpose of the program 
 *          could be multiple lines 
 * =========================================================== */

#include "pex0functs.h"

void parseIt(char string[]){

    for(int i=0; i<strlen(string); i++){ //Modifies the given string based on the function needs.

        if(string[i] == ' '){
            string[i] = '-';
        }

        if((string[i] == 't') || (string[i] == 'T')){
            string[i] = ' ';
        }
    }
}

char* modifyIt(char string[]){
    char prefix[] = "start->";
    char suffix[] = "<-end";
    int length = strlen(string);
    char *newString = malloc(length * sizeof(int)); //dynamically allocates the memory required.
    strcat(newString, prefix); //Adds a "start->" to the beginning of the string.
    strcat(newString, string); //Adds the string contents behind the prefix.
    strcat(newString, suffix); //Adds a "<-end" to the end of the string
    return newString;
}

void getInfo(StudentRecType *variable){ //Populates struct variables.
    fgets(variable->name, SENTLENGTH, stdin);
    fscanf(stdin, "%d", &variable->age); 
}

void fillIt(int twoDArray[][8]){
    
}

void dumpIt(int twoDArray[][8], char filename[]){
    
}