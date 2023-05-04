/** rpnUtils.c
 * ===========================================================
 * Name: Jacob Dunn
 * Section: T5
 * Project: PEX 3 - RPN Calculator
 * Purpose: Reverse polish notation utilities library
 * ===========================================================
 */

#include "rpnUtils.h"
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

/**
* @brief gets input from the user
* @return full queue
* @pre none
* @post initialized queue
*/
QueueAsLinkedList* getInput(){
    QueueAsLinkedList* queue;
    printf("RPN Expression: "); //Prompt user for input.
    char input[30];
    scanf("%[^\n]", input); //Full input string.
    char* inputTok = strtok(input, " \n"); //Tokens input.

    while(inputTok != NULL){ //Takes token and enqueues it based on what type of data it is.
        void* itemPtr = malloc(sizeof(void));
        if(atof(inputTok)){
            *(double*)itemPtr = atof(inputTok);
            queueEnqueue(queue, itemPtr, REAL_NUMBER);
        }
        else{
            char* charPtr = inputTok;
            *(char*)itemPtr = *charPtr;
            queueEnqueue(queue, itemPtr, MATH_OPERATOR);
        }
        inputTok = strtok(NULL, " \n"); //Starts next token from null.
    }

    return queue;
}

/* StackAsLinkedList* rpnCalculator(QueueAsLinkedList* queue){
    StackAsLinkedList* stack;
    void* itemPtr1 = malloc(sizeof(void));
    void* itemPtr2 = malloc(sizeof(void));
    void* itemPtr3 = malloc(sizeof(void));

    while(queue->numberOfElements != 0){
        while(queue->head->type == REAL_NUMBER){
            stackPush(stack, queueDequeue(queue, &queue->head->type), REAL_NUMBER);
            queue->head = queue->head->next;
        }
        if(queue->head->type == MATH_OPERATOR){
            stackPush(stack, queueDequeue(queue, &queue->head->type), MATH_OPERATOR);
            queue->head = queue->head->next;
        }
        stackPop(stack, MATH_OPERATOR);

        if(queue->head->data == '+'){
            itemPtr1 = stackPop(stack, REAL_NUMBER);
            itemPtr2 = stackPop(stack, REAL_NUMBER);
            *(double*)itemPtr3 = *(double*)itemPtr2 + *(double*)itemPtr1;
        }
        else if(queue->head->data == '-'){
            itemPtr1 = stackPop(stack, REAL_NUMBER);
            itemPtr2 = stackPop(stack, REAL_NUMBER);
            *(double*)itemPtr3 = *(double*)itemPtr2 - *(double*)itemPtr1;
        }
        else if(queue->head->data == '*'){
            itemPtr1 = stackPop(stack, REAL_NUMBER);
            itemPtr2 = stackPop(stack, REAL_NUMBER);
            *(double*)itemPtr3 = *(double*)itemPtr2 * *(double*)itemPtr1;
        }
        else if(queue->head->data == '/'){
            itemPtr1 = stackPop(stack, REAL_NUMBER);
            itemPtr2 = stackPop(stack, REAL_NUMBER);
            *(double*)itemPtr3 = *(double*)itemPtr2 / *(double*)itemPtr1;
        }
        else if(queue->head->data == '^'){
            itemPtr1 = stackPop(stack, REAL_NUMBER);
            itemPtr2 = stackPop(stack, REAL_NUMBER);
            *(double*)itemPtr3 = pow(*(double*)itemPtr2, *(double*)itemPtr1);
        }

        stackPush(stack, itemPtr3, REAL_NUMBER);
    }

    return stack;
} */