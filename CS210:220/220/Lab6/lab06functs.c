/** lab06functs.c
 * ===========================================================
 * Name: Jacob Dunn
 * Section: T5
 * Project: Lab 6 - Selection / Insertion Sorts
 * ===========================================================
 */
#include "lab06functs.h"

#include <stdio.h>
#include <stdlib.h>

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

void insertionSort(int numbers[], int numbersSize) {
    for (int i = 1; i < numbersSize; ++i) {
        int j = i;
        while (j > 0 && numbers[j] < numbers[j-1]) {
            int temp = numbers[j];
            numbers[j] = numbers[j-1];
            numbers[j-1] = temp;
            --j;
        }
    }
}

void selectionSort(int numbers[], int numbersSize) {
    for (int i = 0; i < numbersSize-1; ++i) {
        int indexSmallest = i;
        for (int j = i+1; j < numbersSize; ++j) {
            if (numbers[j] < numbers[indexSmallest]) {
                indexSmallest = j;
            }
        }
        int temp = numbers[i];
        numbers[i] = numbers[indexSmallest];
        numbers[indexSmallest] = temp;
    }
}