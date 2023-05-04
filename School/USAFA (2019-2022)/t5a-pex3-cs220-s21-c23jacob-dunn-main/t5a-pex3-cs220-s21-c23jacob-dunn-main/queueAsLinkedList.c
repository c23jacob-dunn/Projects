/** queueAsLinkedList.c
 * ===========================================================
 * Name: Jacob Dunn
 * Section: T5
 * Project: PEX 3 - RPN Calculator
 * Purpose: Queue ADT library - FIFO
 * ===========================================================
 */
#include "queueAsLinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_MAX 12

/** queueEnqueue()
 * @brief - puts an element onto the back of the queue
 * @param queue - a ptr to the queue structure
 * @param element - ptr to the value to add to the back of the queue
 * @param type - ElementType, REAL_NUMBER or MATH_OPERATOR
 * @pre   - 1. void* pointing to dynamically allocated element
 *          2. queue before element added
 * @post  - queue one element longer
 */
void queueEnqueue(QueueAsLinkedList* queue, void* element, ElementType type){
    Node* newNode = malloc(sizeof(Node));
    Node* currNode = malloc(sizeof(Node));
    currNode = queue->tail;
    newNode->type = type;

    if(type == REAL_NUMBER){ //Sets the data of the new node to the input.
        double* itemPtr = malloc(sizeof(double));
        *itemPtr = *(double*)element;
        newNode->data = itemPtr;
    }
    else{
        char* charPtr = malloc(sizeof(char));
        strcpy(charPtr, (char*)element);
        newNode->data = charPtr;
    }

    if(queue->tail == NULL){ //Sets new node when list is empty.
        queue->head = newNode;
        queue->tail = newNode;
        queue->tail->next = NULL;
    }
    else{
        queue->tail->next = newNode; //Sets new node when list is not empty.
        queue->tail = newNode;
    }

    queue->numberOfElements++;
}

/** queueDequeue()
 * @brief - removes an element from the front of the queue
 * @param queue - a ptr to the queue structure
 * @param  type - ptr to the enumeration of the node, ElementType *type
 * @return - ptr to the value removed, type void*; NULL on failure
 * @pre   - queue before element removed from the front; type to be updated unmodified
 * @post  - queue one element shorter; node type updated; ptr to element returned
 */
void* queueDequeue(QueueAsLinkedList* queue, ElementType* type){
    Node* currNode = queue->head;
    queue->head = queue->head->next; //Removes by setting the head node to the next node.
    queue->numberOfElements--;
    return currNode->data;
}

/** queueIsEmpty()
 * @brief  - determines if the queue is empty
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is empty or false
 * @pre    - queue unmodified
 * @post   - queue unmodified; and empty status returned
 */
bool queueIsEmpty(QueueAsLinkedList* queue){
    if(queue->numberOfElements == 0){ //numberOfElements is always determined correctly elsewhere.
        return true;
    }
    else{
        return false;
    }
}

/** queueIsFull()
 * @brief - determines if the queue is full
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is full or false
 * @pre    - queue unmodified
 * @post   - queue unmodified; always returns false
 */
bool queueIsFull(QueueAsLinkedList* queue){
    if(queue->numberOfElements == QUEUE_MAX){
        return true;
    }
    else{
        return false;
    }
}

/** queueInit()
 * @brief  - initializes the queue structure
 * @return - pointer to queue
 * @pre    - nothing
 * @post   - ptr to new empty queue returned
 */
QueueAsLinkedList* queueInit(){
    QueueAsLinkedList* queue = malloc(sizeof(QueueAsLinkedList));//dynamically allocate the momory.
    queue->head = NULL;
    queue->tail = NULL;
    queue->numberOfElements = 0;
    return queue;
}

/** deleteQueue()
 * @brief  - deletes queue, freeing all memory used
 * @param queue - a ptr to the queue structure
 * @pre    - unmodified queue
 * @post   - the queue is erased, all elements freed
 */
void deleteQueue(QueueAsLinkedList* queue){
    Node* currNode = queue->head; //Starting at head, free each node's data.
    for (int i=0; i<queue->numberOfElements; i++){
        Node* tempNode = currNode;
        currNode = currNode->next;
        free(tempNode);
    }
    queue->numberOfElements = 0; //Reset numberOfElements.
}

/** queuePeek()
 * @brief  - returns the item in the front of the
 *           queue but doesn't remove it
 * @param queue - a ptr to the queue structure
 * @param  type - ptr to the enumeration of the node, ElementType *type
 * @return - ptr to the value at the front of the queue, type void*;
 *           NULL if queue is empty
 * @pre    - queue unmodified; type to be updated unmodified
 * @post   - queue unmodified; ptr to front element returned;
 *           type updated with the type of element being returned
 */
void* queuePeek(QueueAsLinkedList* queue, ElementType* type){
    Node* currNode = queue->head;
    return currNode->data; //Returns data without deleting it.
}

/** queueSize()
 * @brief  - determines the size of the queue
 * @param queue - a ptr to the queue structure
 * @return - number of items in the queue
 * @pre    - queue unmodified
 * @post   - queue unmodified; size of queue returned
 */
int queueSize(QueueAsLinkedList* queue){
    return queue->numberOfElements; 
}

/** queuePrint()
 * @brief  - outputs the queue to the console
 * @param queue - the queue structure
 * @pre    - queue unmodified
 * @post   - queue unmodified; queue elements printed
 */
void queuePrint(QueueAsLinkedList* queue){
    Node* currNode = malloc(sizeof(Node));
    currNode = queue->head;

    for(int i=0; i<queue->numberOfElements; i++){
        if(currNode->type == REAL_NUMBER){
            printf("%.3f -> ", *(double*)currNode->data); //Prints out to 3 decimal places.
        }
        else{
            printf("%s -> ", (char*)currNode->data);
        }
        currNode = currNode->next;
    }
    printf("NULL\n");
}