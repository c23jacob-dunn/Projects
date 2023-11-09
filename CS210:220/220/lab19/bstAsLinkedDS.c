/** bstAsLinkedDT.c
 * ================================================================
 * Name: first last
 * Section: xxx
 * Project: Header for BST library
 * =================================================================
 */
#include "bstAsLinkedDS.h"

#include <stdio.h>
#include <stdlib.h>

BSTnode* insertBST(BSTnode* node, int item) {
    if (node->data == NULL) {
        node->data = item;
    }
    else {
        node->data = item;
        while (node->data != NULL) {
            if (node->data < node->left->data) {
                if (node->left == NULL) {
                    node->left = node
                    currentNode = null
                }
                else {
                    currentNode = currentNode⇢left
                }
            }  
            else {
                if (currentNode⇢right is null) {
                    currentNode⇢right = node
                    currentNode = null
                }
                else {
                    currentNode = currentNode⇢right
                }
            }
        }
    }

    return node;
}

void printInorderBST(BSTnode* node) {
    printInorderBST(node->left);
    printf("%d", node->data);
    printInorderBST(node->right);
}

void printPreorderBST(BSTnode* node) {
    printf("%d", node->data);
    printPreorderBST(node->left);
    printPreorderBST(node->right);
}

void printPostorderBST(BSTnode* node) {
    printPostorderBST(node->left);
    printPostorderBST(node->left);
    printf("%d", node->data);
}