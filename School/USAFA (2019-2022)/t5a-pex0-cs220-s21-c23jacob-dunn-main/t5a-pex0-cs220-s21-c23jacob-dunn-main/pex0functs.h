// Be sure to follow DFCS Programming Standard COMPLETELY

/** pex0functs.c
 * =========================================================== 
 * Name: Jacob Dunn, 10 Jan 21
 * Section: T5A 
 * Project: PEX0 
 * Purpose: high level description of purpose of the program 
 *          could be multiple lines 
 * =========================================================== */

//TIME ESTIMATE: 4 Hours

#ifndef PEX0FUNCTS_h
#define PEX0FUNCTS_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SENTLENGTH 80

typedef struct StudentRecType_Struct{
    char name[64];
    int age;
} StudentRecType;

/** 
 * @brief This function changes spaces to dashes and t's or T's to spaces.
 * @param string This is the string of characters that becomes modified.
 * @return none
 * @pre string needs to be less than 80 characters.
 * @post String is modified to new character values. */
void parseIt(char string[]);

/** 
 * @brief This function provides a prefix and suffix to a given string.
 * @param string is the sentence that gets modified.
 * @return This function returns the new, modified string.
 * @pre String must be less than 80 characters.
 * @post String will have a prefix and suffix associated with it. */
char* modifyIt(char string[]);

/** 
 * @brief This function sets the member values of the structure pointed to by the input parameter.
 * @param variable gives the function access to the information inside the struct.
 * @return none
 * @pre The struct must be successfully implemented.
 * @post Struct variable will have initial values. */
void getInfo(StudentRecType *variable);

/** 
 * @brief This function will take the given 2D array and will populate it with integers from 1-100.
 * @param twoDArray provides the empty 2d array to be populated.
 * @return none
 * @pre The 2d array must be dynamically allocated.
 * @post The 2d array will have initialized values. */
void fillIt(int twoDArray[][8]);

/** 
 * @brief This function outputs the 2D array to the filename provided.
 * @param twoDArray is the populated array being output.
 * @return none
 * @pre twoDArray must be populated.
 * @post The file will contain the contents of the 2d array. */
void dumpIt(int twoDArray[][8], char filename[]);

#endif //PEX0FUNCTS_h