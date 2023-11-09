/** lab09.c
 * ===========================================================
 * Name: First Last
 * Section: xxx
 * Project: Lab 9 - Quick Sort
 * ===========================================================
 * Instructions:
 *    1) Complete TASKS Below
 */
#include "lab09functs.h"

int main() {
    int nums[N];

    /* TASK 0 - implement the function, quickSort() below
     * Help - the partition prototype is given to you above
     */
    fillArray(nums);
    quickSort(nums, 0, N - 1);
    printArray(nums, N);

    return 0;
}