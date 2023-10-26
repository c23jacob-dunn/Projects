/** ternaryTreeUnitTest.c
 * ===========================================================
 * Name: Dunn Jacob
 * Section: T5
 * Project: PEX4
 * Purpose: Use a ternary tree hold a dictionary for a spell checker
 * ===========================================================
 */

#include "ternaryTree.h"

/**
 * @brief 
 * @param list - varibale to access WordList struct.
 * @param filename - name of the file to be used.
 * @param lines - number of lines in the file
 * @return 0 if test failed to run, 1 if succeeded
 */
int testHarness(WordList* list, char fileName1[], char fileName2[], int lines){

    // Takes the filename from argv[1] and runs the test for that appropriate file.
    int file = 0;
    if(!strcmp(fileName1, "test_dict2.txt")){
        file = 1;
    }
    else if(!strcmp(fileName1, "test_dict1.txt")){
        file = 2;
    }
    else if(!strcmp(fileName1, "test_dict3.txt")){
        file = 3;
    }
    else{
        printf("Invalid Test File Name.\n");
        return 0; //Program failed to run
    }

    switch (file)
    {
    case 1: //test_dict2.txt
        //Balanced Tree Insertion
        treeOrder(list, "test_dict2.txt", lines);
        printf("Expecting 'SUCCESS' -> %s\n", list->words[0]);
        printf("Expecting 'SUCCEED' -> %s\n", list->words[1]);
        printf("Expecting 'SUCCUMB' -> %s\n\n", list->words[2]);

        //Tree Insertion
        insertTernaryTree(list, "SUCCESS");
        insertTernaryTree(list, "SUCCEED");
        insertTernaryTree(list, "SUCCUMB");
        printf("\n");

        //Spell Check
        spellCheck(list, "SUCCESS", lines);
        spellCheck(list, "SUCCEED", lines);
        spellCheck(list, "SUCCUMB", lines);

        spellCheck(list, "SUCCB", lines);
        spellCheck(list, "ABSOLUTE", lines);
        break;

    case 2: //test_dict1.txt
        //Balanced Tree Insertion
        treeOrder(list, "test_dict1.txt", lines);
        printf("Expecting 'CAT' -> %s\n", list->words[0]);
        printf("Expecting 'CAD' -> %s\n", list->words[1]);
        printf("Expecting 'CAB' -> %s\n", list->words[2]);
        printf("Expecting 'CAR' -> %s\n", list->words[3]);
        printf("Expecting 'COT' -> %s\n", list->words[4]);
        printf("Expecting 'COP' -> %s\n", list->words[5]);
        printf("Expecting 'COW' -> %s\n", list->words[6]);
        printf("Expecting 'CUT' -> %s\n\n", list->words[7]);

        //Tree Insertion
        insertTernaryTree(list, "CAT");
        insertTernaryTree(list, "CAD");
        insertTernaryTree(list, "CAB");
        insertTernaryTree(list, "CAR");
        insertTernaryTree(list, "COT");
        insertTernaryTree(list, "COP");
        insertTernaryTree(list, "COW");
        insertTernaryTree(list, "CUT");
        printf("\n");

        //Spell Check
        spellCheck(list, "CAT", lines);
        spellCheck(list, "CAD", lines);
        spellCheck(list, "CAB", lines);
        spellCheck(list, "CAR", lines);
        spellCheck(list, "COT", lines);
        spellCheck(list, "COP", lines);
        spellCheck(list, "COW", lines);
        spellCheck(list, "CUT", lines);

        spellCheck(list, "CAL", lines);
        spellCheck(list, "CB", lines);
        spellCheck(list, "COG", lines);
        spellCheck(list, "LAT", lines);
        break;

    case 3: //test_dict3.txt
        //Balanced Tree Insertion
        treeOrder(list, "test_dict3.txt", lines);
        printf("Expecting 'CATCH' -> %s\n", list->words[0]);
        printf("Expecting 'CAR' -> %s\n", list->words[1]);
        printf("Expecting 'CAN' -> %s\n", list->words[2]);
        printf("Expecting 'CAT' -> %s\n", list->words[3]);
        printf("Expecting 'COT' -> %s\n", list->words[4]);
        printf("Expecting 'CORK' -> %s\n", list->words[5]);
        printf("Expecting 'CUT' -> %s\n\n", list->words[6]);

        //Tree Insertion
        insertTernaryTree(list, "CATCH");
        insertTernaryTree(list, "CAR");
        insertTernaryTree(list, "CAN");
        insertTernaryTree(list, "CAT");
        insertTernaryTree(list, "COT");
        insertTernaryTree(list, "CORK");
        insertTernaryTree(list, "CUT");
        printf("\n");

        //Spell Check
        spellCheck(list, "CATCH", lines);
        spellCheck(list, "CAR", lines);
        spellCheck(list, "CAN", lines);
        spellCheck(list, "CAT", lines);
        spellCheck(list, "COT", lines);
        spellCheck(list, "CORK", lines);
        spellCheck(list, "CUT", lines);

        spellCheck(list, "CA", lines);
        spellCheck(list, "CY", lines);
        spellCheck(list, "CARR", lines);
        spellCheck(list, "DOM", lines);
        break;
    
    default:
        break;
    }

    return 1; //Program executed successfully
}