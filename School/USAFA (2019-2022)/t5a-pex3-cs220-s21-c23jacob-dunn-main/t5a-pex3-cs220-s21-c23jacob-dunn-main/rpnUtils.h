/** rpnUtils.c
 * ===========================================================
 * Name: Jacob Dunn
 * Section: T5
 * Project: PEX 3 - RPN Calculator
 * Purpose: Reverse polish notation utilities library
 * ===========================================================
 */

#ifndef RPNUTILS_H
#define RPNUTILS_H
#define _CRT_SECURE_NO_WARNINGS  // Hide "unsafe, deprecated" warnings, must be at the top

// What other includes do you need?
#include <string.h>
#include <stdio.h>

#include "queueAsLinkedList.h"
#include "stackAsLinkedList.h"

// prototypes for utility functions

/**
* @brief gets input from the user
* @return full queue
* @pre none
* @post initialized queue
*/
QueueAsLinkedList* getInput();

//StackAsLinkedList* rpnCalculator(QueueAsLinkedList* queue);

#endif  // RPNUTILS_H
