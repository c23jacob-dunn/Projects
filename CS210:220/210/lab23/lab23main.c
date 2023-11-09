/** lab23main.c
* ==============================================================
* Name: Jacob Dunn / 18 Oct 2020
* Section: M3
* Project: Lab23
* Purpose: Write Code
* Documentation Statement: None
* ==============================================================
*/

#include "lab23functs.h"

int main()
{
    int numRecs = getNumRecs("lab23Data.txt");
    printf("Reading number of records in the data file.\n%d records in the data file.\n", numRecs);

    CadetInfoStructType* cadetRecPtr = malloc(numRecs * sizeof(CadetInfoStructType));

    getDataText(cadetRecPtr, numRecs, "lab23Data.txt");

    printf("The first cadet is:\n");
    printCadetInfo(cadetRecPtr[0]);
    printf("The last cadet is:\n");
    printCadetInfo(cadetRecPtr[numRecs-1]);

    free(cadetRecPtr);
    return 0;
}