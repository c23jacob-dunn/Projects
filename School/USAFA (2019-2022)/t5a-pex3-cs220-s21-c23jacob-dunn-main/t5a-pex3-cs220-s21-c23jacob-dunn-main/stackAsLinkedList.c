/** stackAsLinkedList.c
 * ===========================================================
 * Name: Jacob Dunn
 * Section: T5
 * Project: PEX 3 - RPN Calculator
 * Purpose: Stack ADT library - LIFO
 * ===========================================================
 */
#include "stackAsLinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_MAX 12

/** stackPush()
 * @brief - puts an element onto the top of the stack
 * @param element - ptr to thethe value to push onto the stack
 * @param type - ElementType, REAL_NUMBER or MATH_OPERATOR
 * @pre   - 1. void* pointing to dynamically allocated element
 *          2. stack before element added
 * @post  - stack one element taller
 */
void stackPush(StackAsLinkedList* stack, void* element, ElementType type){
    Node* newNode = malloc(sizeof(Node));
    Node* currNode = stack->head;
    newNode->type = type;

    if(type == REAL_NUMBER){ //Sets data based on type.
        double* itemPtr = malloc(sizeof(double));
        *itemPtr = *(double*)element;
        newNode->data = itemPtr;
    }
    else{
        char* charPtr = malloc(sizeof(char));
        strcpy(charPtr, (char*)element);
        newNode->data = charPtr;
    }

    if(stack->head == NULL){ //Condition for when list is empty.
        stack->head = newNode;
        stack->tail = newNode;
    }
    else{
        stack->head = newNode; //Condition for when list is not empty.
        stack->head->next = currNode;
    }

    stack->numberOfElements++;
}

/** stackPop()
 * @brief  - pops an element off the stack
 * @param  stack - a ptr to the stack structure
 * @param  type - ptr to the enumeration of the node, ElementType *type
 * @return - ptr to the top of the stack on success, NULL on failure
 * @pre    - stack before top element removed; type to be modified unchanged
 * @post   - stack one element element shorter; node type updated; ptr to element returned
 */
void* stackPop(StackAsLinkedList* stack, ElementType* type){
    Node* currNode = stack->head;
    stack->head = stack->head->next; //Remove node by removing its pointer.
    stack->numberOfElements--;
    return currNode->data;
}

/** stackIsEmpty()
 * @brief  - determines if the stack is empty
 * @param stack - a ptr to the stack structure
 * @return - true if the stack is empty or false
 * @pre    - stack unmodified
 * @post   - stack unmodified; and empty status returned
 */
bool stackIsEmpty(StackAsLinkedList* stack){
    if(stack->numberOfElements == 0){
        return true;
    }
    else{
        return false;
    }
}

/** stackIsFull()
 * @brief - determines if the stack is full
 * @param stack - a ptr to the stack structure
 * @return - true if the stack is full or false
 * @pre    - stack unmodified
 * @post   - stack unmodified; always returns false
 */
bool stackIsFull(StackAsLinkedList* stack){
    if(stack->numberOfElements == STACK_MAX){
        return true;
    }
    else{
        return false;
    }
}

/** stackInit()
 * @brief  - initializes the stack structure
 * @return - pointer to stack
 * @pre    - nothing
 * @post   - new empty stack returned
 */
StackAsLinkedList* stackInit(){
    StackAsLinkedList* stack = malloc(sizeof(StackAsLinkedList));
    stack->head = NULL;
    stack->tail = NULL;
    stack->numberOfElements = 0;
    return stack;
}

/** deleteLinkedList(()
 * @brief  - deletes stack, freeing all memory used
 * @param stack - a ptr to the stack structure
 * @pre    - unmodified stack
 * @post   - the stack is erased
 */
void deleteStack(StackAsLinkedList* stack){
    Node* currNode = stack->head; //Frees data from every node starting at head.
    for (int i=0; i<stack->numberOfElements; i++){
        Node* tempNode = currNode;
        currNode = currNode->next;
        free(tempNode); 
    }
    stack->numberOfElements = 0;
}

/** stackPeek()
 * @brief  - returns the item on the top of the
 *           stack but doesn't remove it
 * @param stack - a ptr to the stack structure
 * @param  type - ptr to the enumeration of the node, ElementType *type
 * @return - ptr the item on the top of the stack; NULL on failure
 * @pre    - stack unmodified; type to be updated unchanged
 * @post   - stack unmodified; ptr to top element returned;
 *           type updated with the type of element being returned
 */
void* stackPeek(StackAsLinkedList* stack, ElementType* type){
    Node* currNode = stack->head;
    return currNode->data; 
}

/** stackSize()
 * @brief  - determines the size of the stack
 * @param stack - a ptr to the stack structure
 * @return - number of items in the stack
 * @pre    - stack unmodified
 * @post   - stack unmodified; size of stack returned
 */
int stackSize(StackAsLinkedList* stack){
    return stack->numberOfElements;
}

/** stackPrint()
 * @brief  - outputs the stack to the console
 * @param stack - the stack structure
 * @pre    - stack unmodified
 * @post   - stack unmodified; stack elements printed
 */
void stackPrint(StackAsLinkedList* stack){
    Node* currNode = malloc(sizeof(Node));
    currNode = stack->head;

    for(int i=0; i<stack->numberOfElements; i++){
        if(currNode->type == REAL_NUMBER){
            printf("%.3f -> ", *(double*)currNode->data); //Prints out to 3 decimal places
        }
        else{
            printf("%s -> ", (char*)currNode->data);
        }
        currNode = currNode->next; //Prints each node from head.
    }
    printf("NULL\n"); //Ends with null.
}