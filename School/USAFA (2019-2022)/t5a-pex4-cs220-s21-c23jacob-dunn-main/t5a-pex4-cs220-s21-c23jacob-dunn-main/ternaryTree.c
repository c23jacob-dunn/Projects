/** ternaryTree.c
 * ===========================================================
 * Name: Dunn Jacob
 * Section: T5
 * Project: PEX4
 * Purpose: Use a ternary tree hold a dictionary for a spell checker
 * ===========================================================
 */
#include "ternaryTree.h"

/**
 * @brief puts the list in the order it should be insterted into the tree.
 * @param information - varibale to access TernaryTree struct.
 * @param filename - name of file to be used.
 * @param lineNumber - holds the number at the middle of the remaining list
 * @return none
 */
void treeOrder(WordList* list, char filename[], int lines){
    
}

/**
 * @brief prints the current contents of the ternary tree
 * @param information - varibale to access TernaryTree struct.
 * @return none
 */
void printTernaryTree(TernaryTree* tree){

}

/**
 * @brief creates the initial nodes for the ternary tree
 * @return pointer to data in struct
 */
TernaryTree* createTernaryTree(){

    TernaryTree* tree = malloc(sizeof(TernaryTree));
    tree->head = NULL; //initializes nodes for the ternary tree
    tree->tail = NULL;

    return tree;
}

/**
 * @brief deletes the contents of the ternary tree
 * @param information - varibale to access TernaryTree struct.
 * @return none
 */
void deleteTernaryTree(TernaryTree* tree){
    /* Node* currNode = tree->head;
    for (int i=0; i<tree->numLines; i++){
        Node* tempNode = currNode;
        currNode = currNode->leftChild;
        free(tempNode); //frees each node the code encounters beginning with the leftmost pointer
    }
    tree->numLines = 0; */
}

/**
 * @brief inserts a word into the ternary tree
 * @param information - varibale to access TernaryTree struct.
 * @param word - word to be inserted
 * @return none
 */
void insertTernaryTree(WordList* list, char word[]){
/*     TernaryTree* currNode = malloc(sizeof(TernaryTree));

    if(tree->head == NULL){ //Empty tree condition
        for(int i=0; i<strlen(word); i++){
            
        }
    else{ //traverse tree and go left if less than and right if greater than
        
    //insert null pointer to the end of words so only that word will count as spelled correctly
    }
} */

    if(list->test == true){ //Only prints for test cases, would be unruly for dictionary file
        printf("Inserting %s complete\n", word);
    }
    
}

/**
 * @brief 
 * @param information - varibale to access TernaryTree struct.
 * @param word - word to be inserted
 * @param lines - number of lines in the file
 * @return none
 */
void spellCheck(WordList* list, char word[], int lines){
    int correct = 0;
    for(int i=0; i<lines; i++){
        if(!strcmp(word, list->words[i])){
            correct = 1; //sets to one when word is spelled correctly
        }
        else{
        }
    }

    if(correct == 1){
            printf("%s is spelled correctly\n", word);
        }
        else{
            printf("%s is not spelled correctly\n", word);
        }

}