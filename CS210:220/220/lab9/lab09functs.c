/** lab09.c
 * ===========================================================
 * Name: CS220
 * Section: n/a
 * Project: Lab 9 - Quick Sort
 * ===========================================================
 */
#include "lab09functs.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// swaps two integer values
void swap(int* x, int* y) {
    int temp;

    temp = *y;
    *y = *x;
    *x = temp;
}

/**
 * @brief - partition the sublist in to two lists
 * of elements larger and smaller than the selected pivot
 * @param array - the array to sort
 * @param lBound - the left bound of the sublist
 * @param rBound - the right bound of the sublist
 */
int partition(int numbers[], int lBound, int rBound) {
    int midpoint = lBound + (rBound - lBound) / 2;
    int pivot = numbers[midpoint];
    bool done = false;

    while (!done) {

        while (numbers[lBound] < pivot) {
            lBound += 1;
        }

        while (pivot < numbers[rBound]) {
            rBound -= 1;
        }

        if (lBound >= rBound) {
            done = true;
        }

        else {
            int temp = numbers[lBound];
            numbers[lBound] = numbers[rBound];
            numbers[rBound] = temp;
         
            lBound += 1;
            rBound -= 1;
        }
    }
    return rBound;
}

void quickSort(int numbers[], int lBound, int rBound) {
    if (lBound >= rBound) {
        return;
    }

    int lowEndIndex = partition(numbers, lBound, rBound);

    quickSort(numbers, lBound, lowEndIndex);
    quickSort(numbers, lowEndIndex + 1, rBound);
}

// fills an array of size n with random values
void fillArray(int array[]) {
    // set up for and then seed random number
    // generator
    static int seedDone = 0;  // static variables retain their value between calls

    // modified so the seed is only done once
    if (!seedDone) {
        //srand((unsigned)(time(NULL)));  // use for development/debugging
        srand(2023); // uncomment for submission
        seedDone = 1;
    }

    // fill array with random ints from 0 to 99
    for (int i = 0; i < N; i++) {
        array[i] = (int)rand() % 100;
    }
}

// prints the array
void printArray(int nums[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}