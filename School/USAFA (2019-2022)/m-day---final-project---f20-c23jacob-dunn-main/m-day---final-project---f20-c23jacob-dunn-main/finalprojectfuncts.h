/** finalprojectfuncts.H
* ==============================================================
* Name: Jacob Dunn / 3 DEC 2020
* Section: M3/4
* Project: Final Project - Checkers
* Purpose: Create a functioning game of checkers
* ============================================================== 
*/

#ifndef FINALPROJECTFUNCTS_H
#define FINALPROJECTFUNCTS_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LENGTH 8
#define NUM_PIECES 12
#define ASCII_NUM_A 97

typedef struct Checkers_struct
{
    char piecePositions[9];
    int playerTurn;
    int gameOver;
    int countX;
    int countO;
    char endMessage[20];
} Checkers;

/** @fn setPositions()
*   @brief sets all the initial values for the variables
*   @param information gets the current struct data for manipulation
*   @return none
*/
void setPositions(Checkers information[]);

/** @fn drawBoard()
*   @brief draws the board given the current player number and piece positions
*   @param information gets the current struct data for manipulation
*   @return none
*/
void drawBoard(Checkers information[]);

/** @fn playerTurn()
*   @brief gets player turn input and outputs to board if legal
*   @param information gets the current struct data for manipulation
*   @return none
*/
void playerTurn(Checkers information[]);

/** @fn isLegalMove()
*   @brief checks if the inputted move is legal
*   @param information gets the current struct data for manipulation
*   @param moveFrom1 number associated with the inputted number of the piece that is in the location that is being moved from.
*   @param moveTo2 number associated with the inputted number of the piece that is in the location that is being moved to.
*   @param moveFromInt number associated with the inputted letter of the piece that is in the location that is being moved from.
*   @param moveToInt number associated with the inputted letter of the piece that is in the location that is being moved to.
*   @return 1 if move is legal and 0 if move is not legal.
*/
int isLegalMove(Checkers information[], int moveFrom1, int moveTo2, int moveFromInt, int moveToInt);

/** @fn gameOver()
*   @brief checks if the game is over
*   @param information gets the current struct data for manipulation
*   @return 1 if game is over or 0 if game is not over.
*/
int gameOver(Checkers information[]);

/** @fn displayEndMessage()
*   @brief prints message to screen of which player wins
*   @param information gets the current struct data for manipulation
*   @return none
*/
void displayEndMessage(Checkers information[]);

#endif