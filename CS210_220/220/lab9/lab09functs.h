/** lab09.h
 * ===========================================================
 * Name: CS220
 * Section: n/a
 * Project: Lab 9 - Quick Sort
 * ===========================================================
 */
#ifndef LAB09_H
#define LAB09_H

// constant representing size of input
#define N 8

// function prototypes
/** -------------------------------------------------------------------
 * @brief Perform a quick sort on a portion of an array, from lBound
 * to rBound
 * @param array - the array to sort
 * @param lBound - the starting index of the sublist to sort
 * @param rBound - the ending index of the sublist to sort
 * @pre parameters are populated with proper values
 * @post numbers is sorted
 */
void quickSort(int array[], int lBound, int rBound);

/** -------------------------------------------------------------------
 * @brief Fills an array with random values between 0 and 29
 * @param array - the array to fill
 * @pre numbers has been allocated
 * @post array is filled with random numbers
 */
void fillArray(int array[]);

/** -------------------------------------------------------------------
 * @brief Prings an array
 * @param nums - the array to print
 * @param n - items in list
 * @pre numbers has been allocated and initialized
 * @post array is printed nums is unmodified
 */
void printArray(int nums[], int n);

#endif  // LAB09_H
