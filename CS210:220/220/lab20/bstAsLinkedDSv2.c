/** bstAsLinkedDTv2.c
 * ================================================================
 * Name: first last
 * Section: xxx
 * Project: Header for BST library
 * =================================================================
 */
#include "bstAsLinkedDSv2.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// May be useful for heightBST
int myMax(int a, int b) {
    if (a >= b) {
        return a;
    }
    return b;
}

BSTnode *searchBST(BSTnode *node, int item) {
    return node;
}

bool containsBST(BSTnode *node, int item) {
    return false;
}

int sizeBST(BSTnode *node) {
    return 0;
}

int heightBST(BSTnode *curr) {
    return 0;
}

void destroyBST(BSTnode *node) {
}

BSTnode *deleteNodeBST(BSTnode *node, int item) {
    return node;
}

BSTnode *insertBST(BSTnode *node, int item) {
    return node;
}

void printInorderBST(BSTnode *node) {
    if (node == NULL) {
        return;
    }
    printInorderBST(node->left);
    printf("%d ", node->data);
    printInorderBST(node->right);
}

void printPreorderBST(BSTnode *node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    printPreorderBST(node->left);
    printPreorderBST(node->right);
}

void printPostorderBST(BSTnode *node) {
    if (node == NULL) {
        return;
    }
    printPostorderBST(node->left);
    printPostorderBST(node->right);
    printf("%d ", node->data);
}

/** Optional Functions for Displaying a BST **/
void toArray(int *items, const BSTnode *curr, int index) {
    if (curr != NULL) {
        items[index] = curr->data;
        toArray(items, curr->left, index * 2 + 1);
        toArray(items, curr->right, index * 2 + 2);
    }
}

void displayBST(BSTnode *node) {
    printf("\n");
    // If the tree is any taller than 6, it will be too wide to display horizontally.
    int items[64] = {0};  // Max number of items in a binary tree of six levels.
    toArray(items, node, 0);
    int lineWidthOfDeepestLevel =
        (int)pow(2.0, heightBST(node) - 1) * 4;  // Two-digit numbers plus two spaces between.
    int spacesOnCurrentLevel = lineWidthOfDeepestLevel / 2;
    int itemsOnCurrentLevel = 1;
    for (int level = 0; level < heightBST(node); level++) {
        int start = (int)pow(2.0, level) - 1;  // Starting index in the array.
        for (int i = 0; i < itemsOnCurrentLevel; i++) {
            for (int spaces = 0; spaces < spacesOnCurrentLevel - 2; spaces++)
                printf(" ");
            if (items[start + i] > 0)
                printf("%d", items[start + i]);
            else
                printf("  ");
            for (int spaces = 0; spaces < spacesOnCurrentLevel; spaces++)
                printf(" ");
        }
        printf("\n\n");

        // Increment these variables for the next iteration.
        spacesOnCurrentLevel /= 2;
        itemsOnCurrentLevel *= 2;
    }
    printf("\n");
}