/** lab07.c
* ===========================================================
* Name: Jacob Dunn
* Section: M3
* Project: Lab07
* Purpose: Verify install of CS210 software.
* Documentation:  N/A
* ===========================================================
*/
#include <stdio.h>
#include "myFuncts.h"   // function prototypes we create declared
                        // in this file

int main() {
    printf("This short program validates install of CS210 software\n");
    printf("and correct setup and configuration of VSC with GitHub\n");
    printf("Classroom.\n");


    // TODO 1.0
    // Call cubeIt() with a value of 3 and print the result
    cubeIt(3); {
    printf("%d", cubeIt(3));
    }


    // The following line prevents the debugging/run window
    // from immediately closeing.  You will need to hit enter
    // to close the terminal/cmd window
    char c = '\0';scanf("%c", &c);
    return 0;
}