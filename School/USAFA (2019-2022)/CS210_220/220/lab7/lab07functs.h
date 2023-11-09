/** lab07functs.h
 * ===========================================================
 * Name: First Last
 * Section: n/a
 * Project: Lab 7 - Bubble / Shell Sorts
 * ===========================================================
 */
#ifndef LAB07_H
#define LAB07_H

// constant representing size of input
#define N 8

/** -------------------------------------------------------------------
 * @brief - Perform anbubble sort on an array
 * @param numbers - the array to sort
 * @param numbersSize - the size of the array to sort
 * @pre parameters are populated with proper values
 * @post numbers is sorted
 */
void bubbleSort(int numbers[], int numbersSize);

/** -------------------------------------------------------------------
 * @brief Perform a shell sort on a an array
 * @param numbers - the array to sort
 * @param numbersSize - the size of the array to sort
 * @pre parameters are populated with proper values
 * @post numbers is sorted
 */
void shellSort(int numbers[], int numbersSize, int gapValues[], int gapSize);

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
 * @pre numbers has been allocated and initialized
 * @post array is printed nums is unmodified
 */
void printArray(int nums[]);

#endif  // LAB07_H
