/** pex2sorts.c
 * ===========================================================
 * Name: Jacob Dunn
 * Section: T5
 * Project: PEX2
 * Purpose: Sorting algoritms
 * Documentation: C3C Devin Wasilefski explained to me how the command line arguments worked
 * for this PEX.
 * =========================================================== */
#include "pex2sorts.h"

#include "pex2setup.h"

/** -------------------------------------------------------------------
 * @brief Perform an selection sort on an array
 * @param array - the array to sort
 * @param N - the size of the array to sort
 * @pre array[] contains data N contains # of items
 * @post array[] is sorted in ascending order
 */
void selectionSort(int array[], int N) {
    for (int i = 0; i < N - 1; ++i) {
        int indexSmallest = i;
        for (int j = i + 1; j < N; ++j) {
            if (array[j] > array[indexSmallest]) {
                indexSmallest = j;
            }
        }
        int temp = array[i];
        array[i] = array[indexSmallest];
        array[indexSmallest] = temp;
    }
}

/** -------------------------------------------------------------------
 * @brief Perform an insertion sort on an array
 * @param array - the array to sort
 * @param N - the size of the array to sort
 * @pre array[] contains data N contains # of items
 * @post array[] is sorted in ascending order
 */
void insertionSort(int array[], int N) {
    for (int i = 1; i < N; ++i) {
        int j = i;
        while (j > 0 && array[j] > array[j - 1]) {
            int temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
            --j;
        }
    }
}

/** -------------------------------------------------------------------
 * @brief - Perform anbubble sort on an array
 * @param array - the array to sort
 * @param N - the size of the array to sort
 * @pre parameters are populated with proper values
 * @post numbers is sorted
 */
void bubbleSort(int array[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (array[j] < array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

/** -------------------------------------------------------------------
 * @brief Perform the merging for the array
 * @param numbers - the array to sort
 * @param lBound - the left bound of the array
 * @param mid - the midpoint of the array currently being sorted
 * @param rBound - the right bound of the array
 * @pre numbers[] contains data rBound - lBound contains # of items
 * @post numbers[] is sorted in ascending order
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
        if (numbers[leftPos] >= numbers[rightPos]) {
            mergedNumbers[mergePos] = numbers[leftPos];
            ++leftPos;
        } else {
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

/**
 * @brief Given two sorted sublists array[lBound..mid] and array[mid+1..rBound],
 * @param array - the array to sort
 * @param N - the size of the array to sort
 * @pre parameters are populated with proper values
 * @post numbers is sorted
 */
void mergeSort(int array[], int N) {
    realMergeSort(array, 0, N);
}

/**
 * @brief Given two sorted sublists array[lBound..mid] and array[mid+1..rBound],
 * merge them into a single sorted list in array[lBound..rBound]
 * @param numbers - the array to sort
 * @param lBound - the lowest index of the first sublist
 * @param rBound - the highest index of the second sublist
 */
void realMergeSort(int numbers[], int lBound, int rBound) {
    int j = 0;
    if (lBound < rBound) {
        j = (lBound + rBound) / 2;

        realMergeSort(numbers, lBound, j);
        realMergeSort(numbers, j + 1, rBound);

        merge(numbers, lBound, j, rBound);
    }
}