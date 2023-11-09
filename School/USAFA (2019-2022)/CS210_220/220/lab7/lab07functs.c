/** lab07functs.c
 * ===========================================================
 * Name: First Last
 * Section: n/a
 * Project: Lab 7 - Bubble / Shell Sorts
 * ===========================================================
 */
#include "lab07functs.h"
#include <stdlib.h>
#include <stdio.h>

// Bubble Sort
void bubbleSort(int numbers[], int numbersSize) {
    for (int i = 0; i < numbersSize - 1; i++) {
        for (int j = 0; j < numbersSize - i - 1; j++) {
            if (numbers[j] > numbers[j+1]) {
            int temp = numbers[j];
            numbers[j] = numbers[j + 1];
            numbers[j + 1] = temp;
            }
        }
    }
}

// Shell Sort
void shellSort(int numbers[], int numbersSize, int gapValues[], int gapSize) {
    for(int k = 0; k<3; ++k) {
        gapSize = gapValues[k];
        for (int i = gapSize; i < numbersSize; i += 1) { 
            int temp = numbers[i]; 
            int j = 0;
            for (j = i; j >= gapSize && numbers[j - gapSize] > temp; j -= gapSize) {
                numbers[j] = numbers[j - gapSize];
            }
            numbers[j] = temp;
        }
    }
}


    

// fills an array of size n with random values
void fillArray(int array[]) {
    // fill array with random ints from 0 to 29
    for (int i = 0; i < N; i++) {
        array[i] = (int)random() % 30;
    }
}

void printArray(int nums[]) {
    for (int i = 0; i < N; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
