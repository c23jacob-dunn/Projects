/** bstAsLinkedDT.h
 * ================================================================
 * Name: first last
 * Section: xxx
 * Project: Header for BST library
 * =================================================================
 */

#ifndef BSTASLINKEDDS_H
#define BSTASLINKEDDS_H

#include <stdio.h>

typedef struct _bstNode {
    int data;
    struct _bstNode* left;
    struct _bstNode* right;
} BSTnode;

/** ----------------------------------------------------------
 * @brief inserts an item into a BST
 * @param node a pointer to the root of the BST to insert
 * the item in
 * @param item the data item to insert into the BST
 * @return returns a pointer to the root of the BST
 * @pre none
 * @post node is inserted into the BST
 * ----------------------------------------------------------
 */
BSTnode* insertBST(BSTnode* node, int item);

/** ----------------------------------------------------------
 * @brief traverses and prints the BST inorder
 * @param node a pointer to the root of the BST
 * @pre none
 * @post inorder print of tree to console completed
 * ----------------------------------------------------------
 */
void printInorderBST(BSTnode* nodePtr);

/** ----------------------------------------------------------
 * @brief traverses and prints the BST preorder
 * @param node a pointer to the root of the BST
 * @pre none
 * @post preorder print of tree to console completed
 * ----------------------------------------------------------
 */
void printPreorderBST(BSTnode* nodePtr);

/** ----------------------------------------------------------
 * @brief traverses and prints the BST postorder
 * @param node a pointer to the root of the BST
 * @pre none
 * @post postorder print of tree to console completed
 * ----------------------------------------------------------
 */
void printPostorderBST(BSTnode* nodePtr);
#endif  // BSTASLINKEDDS_H
