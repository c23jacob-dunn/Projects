/** listAsLinkedList.c
 * ===========================================================
 * Name: Jacob Dunn
 * Section: T5
 * Project: PEX 3 - RPN Calculator
 * Purpose: List ADT as linked list
 * Documentation: C3C Garth Knutson explained void pointers and how the structs and enum worked
 *      for PEX3P1. He then walked through my code with me to find what was causing EXCEPTION 
 *      errors and gave me tips on some of the things I needed to be checking for in the functions 
 *      (ie. when tail pointers needed to be changed). He also assisted with notation and clarified
 *      some of the logic behind the funcitons by walking me through them on paper. 
 * ===========================================================
 */

#include "listAsLinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** createLinkedList()
 * @brief  - initializes the linked list structure
 * @return - pointer to linked list
 * @pre    - nothing
 * @post   - new empty linked list returned
 */
LinkedList* createLinkedList(){

    LinkedList* list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->numberOfElements = 0;

    return list;
}

/** deleteLinkedList(()
 * @brief  - deletes linked list, freeing all memory used
 * @param list - a ptr to the linked list structure
 * @pre    - unmodified linked list
 * @post   - the linked list is erased, all elements freed
 */
void deleteLinkedList(LinkedList* list){
    
    Node* currNode = list->head;
    for (int i=0; i<list->numberOfElements; i++){
        Node* tempNode = currNode;
        currNode = currNode->next;
        free(tempNode);
    }
    list->numberOfElements = 0;
}

/** appendElementLinkedList()
 * @brief - addes a new element to the end of the linked list
 * @param list - a ptr to the linked list structure
 * @param element - ptr to the value to append to the list
 * @param type - enum ElementType, REAL_NUMBER or MATH_OPERATOR
 * @pre   - 1. void* pointing to dynamically allocated element
 *          2. linked list before element added
 * @post  - modified linked list; node with pointer to element added
 */
void appendElementLinkedList(LinkedList* list, void* element, ElementType type){    

    Node* newNode = malloc(sizeof(Node));
    newNode->type = type;

    if(type == REAL_NUMBER){
        double* itemPtr = malloc(sizeof(double));
        *itemPtr = *(double*)element;
        newNode->data = itemPtr;
    }
    else{
        char* charPtr = malloc(sizeof(char));
        strcpy(charPtr, (char*)element);
        newNode->data = charPtr;
    }

    if(list->head == NULL){
        list->head = newNode;
        list->tail = newNode;
    }
    else{
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->numberOfElements++;
}

/** lengthOfLinkedList()
 * @brief  - returns the size of the linked list
 * @param list - a ptr to the linked structure
 * @return - number of items in the linked list
 * @pre    - linked list unmodified
 * @post   - linked list unmodified; size of linked list returned
 */
int lengthOfLinkedList(LinkedList* list){
    
    return list->numberOfElements;
}

/** printLinkedList()
 * @brief  - outputs the linked list to the console
 * @param list - the linked list structure
 * @pre    - linked list unmodified
 * @post   - linked list unmodified; linked list elements printed
 */
void printLinkedList(LinkedList* list){

    Node* currNode = malloc(sizeof(Node));
    currNode = list->head;

    for(int i=0; i<list->numberOfElements; i++){
        if(currNode->type == REAL_NUMBER){
            printf("%.3f -> ", *(double*)currNode->data);
        }
        else{
            printf("%s -> ", (char*)currNode->data);
        }
        currNode = currNode->next;
    }
    printf("NULL\n");
}

/** getElementLinkedList()
 * @brief  - retrieves element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value requested
 * @param  type - ptr to the enumeration of the node, ElementType *type
 * @return - value at 'position', NULL on failure
 * @pre    - unmodified linked list; unmodified element type to be updated
 * @post   - unmodified linked list; pointer to element at 'position' returned;
 *           type updated
 */
void* getElementLinkedList(LinkedList* list, int position, ElementType* type){   
    
    Node* currNode = list->head;
    for(int i=1; i<position; i++){
        currNode = currNode->next;
    }
    return currNode->data;
}

/** deleteElementLinkedList()
 * @brief  - deletes element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value to delete
 * @pre    - unmodified linked list
 * @post   - modified linked list; node at 'position' removed;
 *           element of node being removed is freed;
 *           node removed is freed
 */
void deleteElementLinkedList(LinkedList* list, int position){
    
    Node* currNode;
    Node* prevNode = list->head;
    Node* nextNode;

    for(int i=1; i<position-1; i++){
        prevNode = prevNode->next;
    }

    currNode = prevNode->next;

    if(currNode->next == NULL){
        prevNode->next = NULL;
        if(list->tail == currNode){
            list->tail = prevNode;
        }
        else{
            currNode = prevNode->next;
            nextNode = prevNode->next->next;
            prevNode->next = nextNode;
        }
    }
    else{
        prevNode->next = currNode->next;
    }

    list->numberOfElements--;
}

/** insertElementLinkedList()
 * @brief  - adds element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value to add
 * @param  element - ptr to value to be added
 * @param type - ElementType, REAL_NUMBER or MATH_OPERATOR
 * @pre    - 1. void* pointing to dynamically allocated element
 *           2. linked list before element added
 * @post   - modified linked list; node with pointer to element added at 'position'
 */
void insertElementLinkedList(LinkedList* list, int position, void* element, ElementType type){
    Node* currNode = list->head;
    Node* nextNode = list->head->next;
    Node* newNode = malloc(sizeof(Node));
    newNode->data = element;
    newNode->type = type;

    for(int i=1; i<position-1; i++){
        nextNode = nextNode->next;
        currNode = currNode->next;
    }

    currNode->next = newNode;
    newNode->next = nextNode;

    list->numberOfElements++;
}

/** changeElementLinkedList()
 * @brief  - changes element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value to add
 * @param  element - ptr to new value
 * @param  type - ElementType, REAL_NUMBER or MATH_OPERATOR
 * @pre    - 1. void* pointing to dynamically allocated element
 *           2. linked list before element added
 * @post   - 1. modified linked list; node changed at 'position' with new pointer to a new element
 *           2. memory allocated to previous element freed
 */
void changeElementLinkedList(LinkedList* list, int position, void* newElement, ElementType type){
    Node* currNode = list->head;
    Node* prevNode = list->head;
    Node* nextNode = list->head->next;
    Node* newNode = malloc(sizeof(Node));
    newNode->data = newElement;
    newNode->type  = type;

    for(int i=1; i<position; i++){
        currNode = currNode->next;
        nextNode = nextNode->next;
        
        if(i==1){
            prevNode = prevNode;
        }
        else{
            prevNode = prevNode->next;
        }
    }
    prevNode->next = newNode;
    newNode->next = nextNode;
}