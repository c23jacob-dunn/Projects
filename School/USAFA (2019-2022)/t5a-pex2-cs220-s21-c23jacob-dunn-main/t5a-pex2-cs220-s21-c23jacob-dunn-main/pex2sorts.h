/** pex2sorts.h
 * ===========================================================
 * Name: Jacob Dunn
 * Section: T5
 * Project: PEX2
 * Purpose: Sorting algoritms
 * Documentation: C3C Devin Wasilefski explained to me how the command line arguments worked
 * for this PEX.
 * =========================================================== */

/** -------------------------------------------------------------------
 * @brief Perform an selection sort on an array
 * @param array - the array to sort
 * @param N - the size of the array to sort
 * @pre array[] contains data N contains # of items
 * @post array[] is sorted in ascending order
 */
void selectionSort(int array[], int N);

/** -------------------------------------------------------------------
 * @brief Perform an insertion sort on an array
 * @param array - the array to sort
 * @param N - the size of the array to sort
 * @pre array[] contains data N contains # of items
 * @post array[] is sorted in ascending order
 */
void insertionSort(int array[], int N);

/** -------------------------------------------------------------------
 * @brief - Perform anbubble sort on an array
 * @param array - the array to sort
 * @param N - the size of the array to sort
 * @pre parameters are populated with proper values
 * @post numbers is sorted
 */
void bubbleSort(int array[], int N);

/** -------------------------------------------------------------------
 * @brief Perform the merging for the array
 * @param numbers - the array to sort
 * @param lBound - the left bound of the array
 * @param mid - the midpoint of the array currently being sorted
 * @param rBound - the right bound of the array 
 * @pre numbers[] contains data rBound - lBound contains # of items
 * @post numbers[] is sorted in ascending order
 */
void merge(int numbers[], int lBound, int mid, int rBound);

/**
 * @brief Given two sorted sublists array[lBound..mid] and array[mid+1..rBound],
 * @param array - the array to sort
 * @param N - the size of the array to sort
 * @pre parameters are populated with proper values
 * @post numbers is sorted
 */
void mergeSort(int array[], int N);

/**
 * @brief Given two sorted sublists array[lBound..mid] and array[mid+1..rBound],
 * merge them into a single sorted list in array[lBound..rBound]
 * @param numbers - the array to sort
 * @param lBound - the lowest index of the first sublist
 * @param rBound - the highest index of the second sublist
 */
void realMergeSort(int array[], int lBound, int rBound);