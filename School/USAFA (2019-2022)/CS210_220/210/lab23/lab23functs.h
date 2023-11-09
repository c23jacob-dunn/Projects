/** lab23functs.h
* ==============================================================
* Name: Jacob Dunn / 18 Oct 2020
* Section: M3
* Project: Lab23
* Purpose: Write Code
* ==============================================================
*/

#ifndef lab23functs_h
#define lab23functs_h
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct CadetInfoStruct {
    char name[50];
    int age;
    int squad;
    int year;
} CadetInfoStructType;

/** ----------------------------------------------------------
 * Reads the number of records from the data file
 * @param dataFile is a string that indicates the path to and filename of the datafile
 * @return number of records in the file or -1 on error
 * ----------------------------------------------------------
 */
int getNumRecs(FILE* dataFile);

/** ----------------------------------------------------------
 * Reads CadetInfoStructType records from a text file
 * @param cadetRecords is the array of cadet records
 * @param numRecs is the number of records in the file
 * @param dataFile is a string that indicates the path to and filename of the datafile
 * ----------------------------------------------------------
 */
void getDataText(CadetInfoStructType cadetRecords[], int numRecs, char dataFile[]);

void printCadetInfo(CadetInfoStructType cadetRecord);

#endif