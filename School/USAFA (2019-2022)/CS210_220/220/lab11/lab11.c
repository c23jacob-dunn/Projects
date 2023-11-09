/** lab11.c
 * ================================================================
 * Name: First, Last
 * Section:
 * Project: Lab11 - Queue ADT implemented with C array
 * =================================================================
 *
 * Instructions:  This lab is similar to the stack ADT implementation
 * only with a circular queue.  You will insert appropriate function
 * calls in the template below to implement a waiting ticket system ala your
 * local DMV.
 *
 * Complete the tasks below after completing the tasks in the queueAsArray.c
 * file
 */
#include <stdio.h>
#include <stdlib.h>

#include "queueAsArray.h"

// local function prototypes
void printMenu();

int main() {
    /** TASK 0 - Add functionality to this file to enable the DMV
     * application to run.
     * 0) ensure that you have completed implementation of
     * the functions in queueAsArray.c prior to starting this task.
     * 1) Call appropriate functions in the switch statement below
     * 2) use printQueue to test your functionality
     * Note: you MUST use the queue library in completing
     * this task.
     */

    QueueAsArray dmvQueue;
    queueInit(&dmvQueue);

    int choice = 0;
    do {
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: { // take a number - generate a random number between 1 and 50 then enqueue
                int randomNum = rand()%50 + 1;
                enqueue(&dmvQueue, randomNum);
                break;
            }
            case 2: {  // dequeue the number at the front of the line and print it
                dequeue(&dmvQueue);
                break;
            }
            case 3: {  // display the total number of people waiting
                printf("\n%d\n\n", queueSize(&dmvQueue));
                break;
            }
            case 4: {  // display the current wait list from fist to last
                queuePrint(&dmvQueue);
                break;
            }
            case 5: {  // exit the application
                break;
            }
            default: {  // invalid choice
                break;
            }
        }
    } while (choice != 5);

    return 0;
}

/** printMenu() - prints a menu for our DMV app
 */
void printMenu() {
    printf("      Menu\n");
    printf("Take a number-----1\n");
    printf("Call a number-----2\n");
    printf("Number waiting----3\n");
    printf("Display waiting---4\n");
    printf("Exit--------------5\n");
    printf("Enter option: ");
}