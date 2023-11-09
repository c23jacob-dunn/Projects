/** lab06.c
 * ===========================================================
 * Name: First Last
 * Section: xxx
 * Project: Lab 6 - Merge Sorts
 * ===========================================================
 * Instructions:
 *    1) Complete TASKS Below
 */
#include "lab08functs.h"

int main() {
    int nums[N];

    /* TASK 0 - implement the function, mergeSort()
     *  
     */
    fillArray(nums);
    mergeSort(nums, 0, N - 1);
    printArray(nums);

    return 0;
}