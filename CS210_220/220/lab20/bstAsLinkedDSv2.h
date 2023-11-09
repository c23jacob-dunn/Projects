/** bstAsLinkedDTv2.h
* ================================================================
* Name: first last
* Section: xxx
* Project: Header for BST library
* =================================================================
*/

#ifndef BSTASLINKEDDSV2_H
#define BSTASLINKEDDSV2_H

#include <stdio.h>
#include <stdbool.h>

typedef struct _bstNode {
    int data;
    struct _bstNode* left;
    struct _bstNode* right;
} BSTnode;

/** ----------------------------------------------------------
 * @brief searches for an item in a BST
 * @param node - a pointer to the root of the BST to search
 * @param item - the data item to search for
 * @return returns a pointer to the found node NULL if not found
 * @pre none
 * @post none
 * ----------------------------------------------------------
 */
BSTnode* searchBST(BSTnode* node, int item);

/** ----------------------------------------------------------
 * @brief searches for an item in a BST
 * @param node a pointer to the root of the BST to search
 * @param item the data item to search for
 * @return returns true if found or false if not
 * @pre none
 * @post none
 * ----------------------------------------------------------
 */
bool containsBST(BSTnode* node, int item);


/** ----------------------------------------------------------
 * @brief counts the nodes in a BST
 * @param node a pointer to the root of the BST
 * @return returns number of nodes
 * @pre none
 * @post none
 * ----------------------------------------------------------
 */
int sizeBST(BSTnode* node);


/** ----------------------------------------------------------
 * @brief calcuates the height of the BST
 * @param node a pointer to the root of the BST
 * @return returns height
 * @pre none
 * @post none
 * ----------------------------------------------------------
 */
int heightBST(BSTnode* node);


/** ----------------------------------------------------------
 * destroyBST() frees memory in a BST
 * @param node - a pointer to the root of the BST
 * @pre none
 * @post BST is dellocated
 * ----------------------------------------------------------
 */
void destroyBST(BSTnode* node);


/** ----------------------------------------------------------
 * @brief deletes a single node from a BST
 * @param node a pointer to the root of the BST
 * @param item the item to find and delete
 * @return pointer to remaining tree after item was
 * deleted.
 * @pre none
 * @post tree modified with node removed
 * ----------------------------------------------------------
 */
BSTnode* deleteNodeBST(BSTnode* node, int item);

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


/** ----------------------------------------------------------
 * displayBST() displays a binary tree upto 6 levels
 * @param node - a pointer to the root of the BST
 * ----------------------------------------------------------
 */
void displayBST(BSTnode* node);
#endif // BSTASLINKEDDSV2_H