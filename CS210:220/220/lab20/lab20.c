/** lab20.c
* ================================================================
* Name: first last
* Section: xxx
* Project: Header for BST library
* =================================================================
*/
#include "bstAsLinkedDSv2.h"

#include <stdio.h>
/* Instructions - Complete the following tasks
 *
 * Task0 - complete the remaining operations on
 * the BST as defined in the header file,
 * bstAsLinkedDS.h (new version for this lab).
 * Test with the code below.  Feel free to
 * add / change tests below to meet your needs.
 */
int main() {
    BSTnode* root = NULL;
    root = insertBST(root,5);
    root = insertBST(root,10);
    root = insertBST(root,1);
    root = insertBST(root,7);
    root = insertBST(root,3);
    root = insertBST(root,6);
    printInorderBST(root);printf("\n");
    printPreorderBST(root);printf("\n");
    printPostorderBST(root);printf("\n");
    BSTnode* curNode = searchBST(root,10);
    if (curNode == NULL) {
        printf("Error - Not found.\n");
    } else {
        printf("found -> %d\n", curNode->data);
    }
    printf("contains? -> %d\n", containsBST(root,3));
    printf("size -> %d\n",sizeBST(root));
    printf("height -> %d\n",heightBST(root));
    root = deleteNodeBST(root,6);
    root = deleteNodeBST(root,3);
    root = deleteNodeBST(root,5);
    destroyBST(root);
}

