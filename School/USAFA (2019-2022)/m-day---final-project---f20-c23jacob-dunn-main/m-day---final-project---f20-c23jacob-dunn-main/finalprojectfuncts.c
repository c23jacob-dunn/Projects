/** finalprojectfuncts.c
* ==============================================================
* Name: Jacob Dunn / 3 DEC 2020
* Section: M3/4
* Project: Final Project - Checkers
* Purpose: Create a functioning game of checkers
* ============================================================== 
*/

#include "finalprojectfuncts.h"

/** @fn setPositions()
*   @brief sets all the initial values for the variables
*   @param information gets the current struct data for manipulation
*   @return none
*/
void setPositions(Checkers information[])
{
    information->playerTurn = 1; //Initializes all the data held within the struct.
    information->countX = 0;
    information->countO = 0;
    information->gameOver = 0;
    strcpy(information[0].piecePositions, " O O O O");
    strcpy(information[1].piecePositions, "O O O O ");
    strcpy(information[2].piecePositions, " O O O O");
    strcpy(information[3].piecePositions, "        ");
    strcpy(information[4].piecePositions, "        ");
    strcpy(information[5].piecePositions, "X X X X ");
    strcpy(information[6].piecePositions, " X X X X");
    strcpy(information[7].piecePositions, "X X X X ");
    printf("Player 1: X\nPlayer 2: O\n\n");
    drawBoard(information); //Calls drawBoard with the initial informaiton now in place.
}

/** @fn drawBoard()
*   @brief draws the board given the current player number and piece positions
*   @param information gets the current struct data for manipulation
*   @return none
*/
void drawBoard(Checkers information[])
{
    printf("Player %d's turn", information->playerTurn); //Displays which player's turn it is above the board.
    printf("\n     A       B       C       D       E       F       G       H\n");
    printf(" -----------------------------------------------------------------\n"); //The information below calls each character associated with the position its identifier represents.
    printf(" |       |       |       |       |       |       |       |       |\n");
    printf("8|   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |8\n",information[0].piecePositions[0],information[0].piecePositions[1],information[0].piecePositions[2],information[0].piecePositions[3],information[0].piecePositions[4],information[0].piecePositions[5],information[0].piecePositions[6],information[0].piecePositions[7]);
    printf(" |       |       |       |       |       |       |       |       |\n");
    printf(" -----------------------------------------------------------------\n");
    printf(" |       |       |       |       |       |       |       |       |\n");
    printf("7|   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |7\n",information[1].piecePositions[0],information[1].piecePositions[1],information[1].piecePositions[2],information[1].piecePositions[3],information[1].piecePositions[4],information[1].piecePositions[5],information[1].piecePositions[6],information[1].piecePositions[7]);
    printf(" |       |       |       |       |       |       |       |       |\n");
    printf(" -----------------------------------------------------------------\n");
    printf(" |       |       |       |       |       |       |       |       |\n");
    printf("6|   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |6\n",information[2].piecePositions[0],information[2].piecePositions[1],information[2].piecePositions[2],information[2].piecePositions[3],information[2].piecePositions[4],information[2].piecePositions[5],information[2].piecePositions[6],information[2].piecePositions[7]);
    printf(" |       |       |       |       |       |       |       |       |\n");
    printf(" -----------------------------------------------------------------\n");
    printf(" |       |       |       |       |       |       |       |       |\n");
    printf("5|   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |5\n",information[3].piecePositions[0],information[3].piecePositions[1],information[3].piecePositions[2],information[3].piecePositions[3],information[3].piecePositions[4],information[3].piecePositions[5],information[3].piecePositions[6],information[3].piecePositions[7]);
    printf(" |       |       |       |       |       |       |       |       |\n");
    printf(" -----------------------------------------------------------------\n");
    printf(" |       |       |       |       |       |       |       |       |\n");
    printf("4|   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |4\n",information[4].piecePositions[0],information[4].piecePositions[1],information[4].piecePositions[2],information[4].piecePositions[3],information[4].piecePositions[4],information[4].piecePositions[5],information[4].piecePositions[6],information[4].piecePositions[7]);
    printf(" |       |       |       |       |       |       |       |       |\n");
    printf(" -----------------------------------------------------------------\n");
    printf(" |       |       |       |       |       |       |       |       |\n");
    printf("3|   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |3\n",information[5].piecePositions[0],information[5].piecePositions[1],information[5].piecePositions[2],information[5].piecePositions[3],information[5].piecePositions[4],information[5].piecePositions[5],information[5].piecePositions[6],information[5].piecePositions[7]);
    printf(" |       |       |       |       |       |       |       |       |\n");
    printf(" -----------------------------------------------------------------\n");
    printf(" |       |       |       |       |       |       |       |       |\n");
    printf("2|   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |2\n",information[6].piecePositions[0],information[6].piecePositions[1],information[6].piecePositions[2],information[6].piecePositions[3],information[6].piecePositions[4],information[6].piecePositions[5],information[6].piecePositions[6],information[6].piecePositions[7]);
    printf(" |       |       |       |       |       |       |       |       |\n");
    printf(" -----------------------------------------------------------------\n");
    printf(" |       |       |       |       |       |       |       |       |\n");
    printf("1|   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |   %c   |1\n",information[7].piecePositions[0],information[7].piecePositions[1],information[7].piecePositions[2],information[7].piecePositions[3],information[7].piecePositions[4],information[7].piecePositions[5],information[7].piecePositions[6],information[7].piecePositions[7]);
    printf(" |       |       |       |       |       |       |       |       |\n");
    printf(" -----------------------------------------------------------------\n");
    printf("     A       B       C       D       E       F       G       H\n\n");
}

/** @fn playerTurn()
*   @brief gets player turn input and outputs to board if legal
*   @param information gets the current struct data for manipulation
*   @return none
*/
void playerTurn(Checkers information[])
{
    char moveFromA = ' '; //Initializes then sets the four following variables.
    char moveToB = ' ';
    int moveFrom1 = 0;
    int moveTo2 = 0;
    printf("Enter the coordinates that corrrespond to your move (ex. G3 H4): ");
    scanf(" %c %d %c %d", &moveFromA, &moveFrom1, &moveToB, &moveTo2);

    moveFrom1 = LENGTH - moveFrom1; //Associates the inputted number with the correct value in the struct array.
    moveTo2 = LENGTH - moveTo2;
    int moveFromInt = (tolower(moveFromA)) - ASCII_NUM_A; //Associated the inputted number with the correct value in the piecePositions array.
    int moveToInt = (tolower(moveToB)) - ASCII_NUM_A;

    if(isLegalMove(information, moveFrom1, moveTo2, moveFromInt, moveToInt) == 1) //Calls isLegalMove() to see if the inputted move is allowed.
    {
        switch(information->playerTurn)
        {
        case 1: //If it's player one's turn.
            information[moveTo2].piecePositions[moveToInt] = 'X'; //New position becomes X.
            information[moveFrom1].piecePositions[moveFromInt] = ' '; //Old position becomes ' '.
            information->playerTurn = 2; //Changes the player's turn.
            break;
        
        case 2: //If it's player two's turn.
            information[moveTo2].piecePositions[moveToInt] = 'O'; //New position becomes O.
            information[moveFrom1].piecePositions[moveFromInt] = ' '; //Old position becomes ' '.
            information->playerTurn = 1; //Changes the player's turn.
            break;

        default: //Never actually runs, just here as a default.
            break;
        }
    }
    drawBoard(information); //Draws board with new information.
}

/** @fn isLegalMove()
*   @brief checks if the inputted move is legal
*   @param information gets the current struct data for manipulation
*   @param moveFrom1 number associated with the inputted number of the piece that is in the location that is being moved from.
*   @param moveTo2 number associated with the inputted number of the piece that is in the location that is being moved to.
*   @param moveFromInt number associated with the inputted letter of the piece that is in the location that is being moved from.
*   @param moveToInt number associated with the inputted letter of the piece that is in the location that is being moved to.
*   @return 1 if move is legal and 0 if move is not legal.
*/
int isLegalMove(Checkers information[], int moveFrom1, int moveTo2, int moveFromInt, int moveToInt)
{
    switch(information->playerTurn)
    {
        case 1:
            if((moveTo2 == moveFrom1 - 1) && (moveFromInt == moveToInt - 1)) //If move is 1 space up and one space left.
            {
                if(information[moveFrom1-1].piecePositions[moveFromInt+1] == ' ') //If 1 space up and one space left is blank.
                    {
                        return 1;
                    }
            }
            if((moveTo2 == moveFrom1 - 1) && (moveFromInt == moveToInt + 1)) //If move is 1 space up and one space left.
            {
                if(information[moveFrom1-1].piecePositions[moveFromInt-1] == ' ') //If 1 space up and one space right is blank.
                {
                    return 1;
                }
            }
            if((moveTo2 == moveFrom1 - 2) && (moveFromInt == moveToInt - 2) && (information[moveFrom1-1].piecePositions[moveFromInt+1] == 'O')) //If move is 2 spaces up, 2 to the left and there is an 'O' one space up and one to the left.
            {
                information[moveFrom1-1].piecePositions[moveFromInt+1] = ' '; //Set piece being jumped over to ' '.
                information->countO++; //Add 1 to the count number for that piece.
                if(information->countO == NUM_PIECES) //When count is 12 (all pieces are gone).
                {
                    information->gameOver = 1; //Set gameOver to 1 (true).
                }
                return 1;
            }
            if((moveTo2 == moveFrom1 - 2) && (moveFromInt == moveToInt + 2) && (information[moveFrom1-1].piecePositions[moveFromInt-1] == 'O')) //If move is 2 spaces up, 2 to the right and there is an 'O' one space up and one to the right.
            {
                information[moveFrom1-1].piecePositions[moveFromInt-1] = ' '; //Set piece being jumped over to ' '.
                information->countO++; //Add 1 to the count number for that piece.
                if(information->countO == NUM_PIECES) //When count is 12 (all pieces are gone).
                {
                    information->gameOver = 1; //Set gameOver to 1 (true).
                }
                return 1;
            }
            break;

        case 2:
            if((moveTo2 == moveFrom1 + 1) && (moveFromInt == moveToInt - 1)) //If move is 1 space down and one space left.
            {
                if(information[moveFrom1+1].piecePositions[moveFromInt+1] == ' ') //If 1 space down and one space left is blank.
                    {
                        return 1;
                    }
            }
            if((moveTo2 == moveFrom1 + 1) && (moveFromInt == moveToInt + 1)) //If move is 1 space down and one space left.
            {
                if(information[moveFrom1+1].piecePositions[moveFromInt-1] == ' ') //If 1 space down and one space right is blank.
                {
                    return 1;
                }
            }
            if((moveTo2 == moveFrom1 + 2) && (moveFromInt == moveToInt - 2) && (information[moveFrom1+1].piecePositions[moveFromInt+1] == 'X')) //If move is 2 spaces down, 2 to the left and there is an 'O' one space down and one to the left.
            {
                information[moveFrom1+1].piecePositions[moveFromInt+1] = ' '; //Set piece being jumped over to ' '.
                information->countX++; //Add 1 to the count number for that piece.
                if(information->countX == NUM_PIECES) //When count is 12 (all pieces are gone).
                {
                    information->gameOver = 1; //Set gameOver to 1 (true).
                }
                return 1;
            }
            if((moveTo2 == moveFrom1 + 2) && (moveFromInt == moveToInt + 2) && (information[moveFrom1+1].piecePositions[moveFromInt-1] == 'X')) //If move is 2 spaces down, 2 to the right and there is an 'O' one space down and one to the right.
            {
                information[moveFrom1+1].piecePositions[moveFromInt-1] = ' '; //Set piece being jumped over to ' '.
                information->countX++; //Add 1 to the count number for that piece.
                if(information->countX == NUM_PIECES) //When count is 12 (all pieces are gone).
                {
                    information->gameOver = 1; //Set gameOver to 1 (true).
                }
                return 1;
            }
            break;
    }
    return 0;
}

/** @fn gameOver()
*   @brief checks if the game is over
*   @param information gets the current struct data for manipulation
*   @return 1 if game is over or 0 if game is not over.
*/
int gameOver(Checkers information[])
{
    if(information->gameOver == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/** @fn displayEndMessage()
*   @brief prints message to screen of which player wins
*   @param information gets the current struct data for manipulation
*   @return none
*/
void displayEndMessage(Checkers information[])  
{
    printf("\n\n");
    FILE* inFile = fopen("endMessage.txt", "r"); //opens the file
    for(int i=0; i<2; i++)
    {
        fscanf(inFile, " %[^\n]", information[i].endMessage);
    }
    fclose(inFile);
    
    if(information->countO == NUM_PIECES) //If player 1 wins print this.
    {
        printf("%s\n\n\n", information[0].endMessage);
    }
    
    if(information->countX == NUM_PIECES) //If player 2 wins print this.
    {
        printf("%s\n\n\n", information[1].endMessage);
    }
}