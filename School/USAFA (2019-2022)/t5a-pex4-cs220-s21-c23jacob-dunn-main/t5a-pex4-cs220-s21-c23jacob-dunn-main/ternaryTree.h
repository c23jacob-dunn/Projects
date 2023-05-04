/** ternaryTree.h
 * ===========================================================
 * Name: Dunn Jacob
 * Section: T5
 * Project: PEX4
 * Purpose: Use a ternary tree hold a dictionary for a spell checker
 * ===========================================================
 */
#ifndef TERNARYTREE_H
#define TERNARYTREE_H

#include "wordList.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node_struct { //Struct to access the three possibly children of each node.
    char* letter;
    struct Node_struct* leftChild;
    struct Node_struct* rightChild;
    struct Node_struct* middleChild;
} Node;

typedef struct ternaryTreeStruct { //Struct to hold necessary data used throughout code.
    Node* head;
    Node* tail;
} TernaryTree;

/**
 * @brief puts the list in the order it should be insterted into the tree.
 * @param information - varibale to access TernaryTree struct.
 * @param filename - name of file to be used.
 * @param lineNumber - holds the number at the middle of the remaining list
 * @return none
 */
void treeOrder(WordList* list, char filename[], int lines);

/**
 * @brief prints the current contents of the ternary tree
 * @param information - varibale to access TernaryTree struct.
 * @return none
 */
void printTernaryTree(TernaryTree information[]);

/**
 * @brief creates the initial nodes for the ternary tree
 * @return pointer to data in struct
 */
TernaryTree* createTernaryTree();

/**
 * @brief deletes the contents of the ternary tree
 * @param information - varibale to access TernaryTree struct.
 * @return none
 */
void deleteTernaryTree(TernaryTree information[]);

/**
 * @brief inserts a word into the ternary tree
 * @param list - varibale to access WordList struct.
 * @param word - word to be inserted
 * @return none
 */
void insertTernaryTree(WordList* list, char word[]);

/**
 * @brief 
 * @param information - varibale to access TernaryTree struct.
 * @param word - word to be inserted
 * @param lines - number of lines in the file
 * @return none
 */
void spellCheck(WordList* list, char word[], int lines);

/**
 * @brief 
 * @param list - varibale to access WordList struct.
 * @param filename - name of the file to be used.
 * @param lines - number of lines in the file
 * @return 0 if test failed to run, 1 if succeeded
 */
int testHarness(WordList* list, char fileName1[], char fileName2[], int lines);

#endif  // TERNARYTREE_H