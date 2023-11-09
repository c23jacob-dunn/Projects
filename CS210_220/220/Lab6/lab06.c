/** lab06.c
 * ===========================================================
 * Name: Jacob Dunn
 * Section: T5
 * Project: Lab 6 - Selection / Insertion Sorts
 * Documentation: None
 * ===========================================================
 * Instructions:
 *    1) Complete TASKS Below
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lab06functs.h"

int main() {
    int nums[N];

    // seed random number generator
    //srand((unsigned)(time(NULL))); // use for development/debugging
    srand(2023); // uncomment for submission

    // fill the array with random numbers
    fillArray(nums);

    /* TASK 0 - implement the function, SelectionSort()
     * 0) Call the function and verify that it works
     */
    selectionSort(nums, N);
    printArray(nums);

    /* TASK 1 - implement the function, InsertionSort()
     * 0) Refill the array to get a new random set of
     * numbers.
     * 1) Call the function and verify that it works
     * A helper function that swaps values might be helpful
     */
    fillArray(nums);
    insertionSort(nums, N);
    printArray(nums);

    return 0;
}