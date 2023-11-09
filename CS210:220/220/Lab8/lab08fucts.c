/** lab08functs.c
 * ===========================================================
 * Name: CS220
 * Section: n/a
 * Project: Lab 8 - Merge Sort
 * ===========================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lab08functs.h"

/**
 * @brief Given two sorted sublists array[lBound..mid] and array[mid+1..rBound],
 * merge them into a single sorted list in array[lBound..rBound]
 * @param array - the array to sort
 * @param lBound - the lowest index of the first sublist
 * @param mid - the highest index of the first sublist
 * @param rBound - the highest index of the second sublist
 */
void merge(int numbers[], int lBound, int mid, int rBound) {
    int mergedSize = rBound - lBound + 1;
    int mergePos = 0;
    int leftPos = 0;
    int rightPos = 0;
    int mergedNumbers[mergedSize];
   
    leftPos = lBound;
    rightPos = mid + 1;
   
    while (leftPos <= mid && rightPos <= rBound) {
        if (numbers[leftPos] <= numbers[rightPos]) {
            mergedNumbers[mergePos] = numbers[leftPos];
            ++leftPos;
        }
        else {
            mergedNumbers[mergePos] = numbers[rightPos];
            ++rightPos;
         
        }
        ++mergePos;
    }
   
    while (leftPos <= mid) {
        mergedNumbers[mergePos] = numbers[leftPos];
        ++leftPos;
        ++mergePos;
    }

    while (rightPos <= rBound) {
        mergedNumbers[mergePos] = numbers[rightPos];
        ++rightPos;
        ++mergePos;
    }
   
    for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
        numbers[lBound + mergePos] = mergedNumbers[mergePos];
    }
}

// mergeSort
void mergeSort(int numbers[], int lBound, int rBound) {
    int j = 0;
   
    if (lBound < rBound) {
        j = (lBound + rBound) / 2;

        mergeSort(numbers, lBound, j);
        mergeSort(numbers, j + 1, rBound);
      
        merge(numbers, lBound, j, rBound);
    }
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

// printArray
void printArray(int nums[]) {
    for (int i = 0; i < N; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}