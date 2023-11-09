/** queueAsArray.c
 * ===========================================================
 * Name: First Last
 * Section: xxx
 * Project: Lab11 - Queue ADT implemented with C array
 * ===========================================================
 */
#include "queueAsArray.h"

#include <stdio.h>

/** Task 0) - write the implementations for circular queue functions
 * 0) implement functions below
 * 1) test each function in Lab09_queue.c prior to completing
 * the DMV application.
 */

/** enqueue() - adds an element to the back of the queue
 * @param queue - a ptr to the queue structure
 * @param element - the item to add to the queue
 * @return 1 on success, -1 on failure
 */
int enqueue(QueueAsArray* queue, int element) {
    queue->number[queue->back] = element;
    queue->back++;
    return 1;
}

/** dequeue() - removes an element from the front of the queue
 * @param queue - a ptr to the queue structure
 * @return - the top of the queue on success, -1 on failure
 */
int dequeue(QueueAsArray* queue) {
    int front = queue->number[0];
    for (int i=0; i< queue->back; i++){
        queue->number[i] = queue->number[i+1];
    }
    --queue->back;
    return front;
}

/** queueIsEmpty() - determines if the queue is empty
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is empty or false
 */
bool queueIsEmpty(QueueAsArray* queue) {
    if((queue->back - queue->front) == 0){
        return true;
    }
    else{
        return false;
    }
}

/** queueIsFull() - determines if the queue is full
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is full or false
 */
bool queueIsFull(QueueAsArray* queue) {
    if((queue->back - queue->front) == QUEUE_MAX_SIZE){
        return true;
    }
    else{
        return false;
    }
}

/** queueInit() - initializes the queue structure
 * @param queue - a ptr to the queue structure
 */
void queueInit(QueueAsArray* queue) {
    queue->back = 0;
    queue->front = 0;
    for(int i=0; i<QUEUE_MAX_SIZE; i++){
        queue->number[i] = i;
    }
}

/** queuePeek() - returns the item on the front of the
 * queue but doesn't remove it
 * @param queue - a ptr to the queue structure
 * @return - the item at the front of the queue or -1 on failure
 */
int queuePeek(QueueAsArray* queue) {
    return queue->number[queue->front];
}

/** queueSize() - determines the size of the queue
 * @param queue - a ptr to the queue structure
 * @return - number of items in the queue
 */
int queueSize(QueueAsArray* queue) {
    return queue->back;
}

/** queuePrint() - outputs the queue to the console
 * @param queue - ptr to the queue structure
 */
void queuePrint(QueueAsArray* queue) {
    for(int i=0; i<(queue->back - queue->front); i++){
        printf("%d ", queue->number[i]);
    }
    printf("\n\n");
}