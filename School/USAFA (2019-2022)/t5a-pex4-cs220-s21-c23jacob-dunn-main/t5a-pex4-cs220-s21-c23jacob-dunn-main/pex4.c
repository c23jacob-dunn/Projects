/** pex4.c
 * ===========================================================
 * Name: Dunn Jacob
 * Section: T5
 * Project: PEX4
 * Purpose: Use a ternary tree hold a dictionary for a spell checker
 * Documentation: C3C Garth Knutson explained to me why my almost complete loadWordList
 * function was not working. This help took less than 10 minutes and he found a small error
 * that was easily fixed. Once the const char in my fscanf was fixed, I stopped receiveing 
 * his help.
 * ===========================================================
 */
#include "ternaryTree.h"

int main(int argc, char *argv[]) {

    WordList* list = wordListCreate();
    int lines = wordListSize(list);
    loadWordList(list, argv[1]); 
    //wordListPrint(list);
    wordListDelete(list);

    treeOrder(list, argv[1], lines);

    list->test = true; //set to true to run test, false to run live program

    if(list->test == false){
        testHarness(list, argv[1], argv[2], lines);
    }
    else{
        treeOrder(list, argv[1], lines); //orders list to how it should be passed into tree

        createTernaryTree(); 
        for(int i=0; i<lines; i++){
            insertTernaryTree(list, list->words[i]);
        }
        
        char word[MAXSTRINGLENGTH];
        printf("Enter a word to Spell Check: ");
        scanf("%s", word);

        spellCheck(list, word, lines);
     }

    return 0;
}