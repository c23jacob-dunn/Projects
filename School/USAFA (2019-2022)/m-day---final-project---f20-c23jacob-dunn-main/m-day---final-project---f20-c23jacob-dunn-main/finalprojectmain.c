/** finalprojectmain.c
* ==============================================================
* Name: Jacob Dunn / 3 DEC 2020
* Section: M3/4
* Project: Final Project - Checkers
* Purpose: Create a functioning game of checkers
* Documentation Statement: None
* ============================================================== 
*/

#include "finalprojectfuncts.h"

int main()
{
    Checkers information[LENGTH + 1]; //Add 1 for the null character.
    setPositions(information); //Calls the initial positions of the pieces before running the game.
    while(gameOver(information) == 0)
    {
        playerTurn(information);
    }
    displayEndMessage(information);
    return 0;
}