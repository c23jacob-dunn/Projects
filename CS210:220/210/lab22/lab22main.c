/** lab22main.c
* ===========================================================
 * Name: Jacob Dunn / 10Oct2020
 * Section: M3/4
 * Project: Lab 22
 * Documentaion Statement: None
* ===========================================================
*
* Instructions:
*    1) Complete TASKS Below
*/
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "lab22functs.h"

int main() {
    MyCadetInfo cadetRecs[MAXSTUDENTS];

    // read cadet records from a text file
    int numCadets = getDataText(cadetRecs);

    // write the array of structures to a binary file
    writeDataBlk(cadetRecs,numCadets);

    // modify the 4th record and rewrite only
    // that record to the binary file
    strncpy(cadetRecs[3].name, "Da Cadet",20);
    writeCadetBlk(&cadetRecs[3],3);

    /* Exercise 1 - Write a function, readCadetBlk(), that reads a single cadet record from binary file
    * 1) The function returns the MyCadetInfo structure read from disk
    * 2) Verify that it works by printing the returned struct
    *      The struct is yourChosenVarName from above.
    */

    MyCadetInfo daCadet = readCadetBlk(0);
    printCadetInfo(daCadet);

    /* Exercise 2 - Write a function, called, updateSqdBlk() that
     * uses a cadet's full name to find the cadet in the array of
     * records, updates their squadron to the given value,
     * and then writes the new record in the correct location
     * in the binary file
     * 0) Figure out the required parameters and write the function
     * prototype in the *.h file
     * 1) The function returns the number of records written and on
     * error it returns a -1
     * 2) Call your function below with parameters of your choice
     * 3) Verify that it works by reading the record from the file
     * and printing it.
     */

    updateSqdBlk("Da Cadet", 57, cadetRecs, numCadets);
    printCadetInfo(readCadetBlk(3));

    /* Exercise 3 - Write a function, called, updateClassYearNameBlk()
     * that overwrites the file, lab22Data.bin, with the class
     * year prepended to the cadet name.  For example, Troy Weingart
     * would become C1C Troy Weingart if I were in class of 2021.
     * 0) Figure out the required parameters and write the function
     * prototype in the *.h file
     * 1) The function returns the number of records written and on
     * error it returns a -1
     * 2) Call your function below
     * 3) Verify that your function works by using readCadetBlk()
     * and printing the results.
    */

    updateClassYearNameBlk(cadetRecs, numCadets);
    printCadetInfo(readCadetBlk(0));
    printCadetInfo(readCadetBlk(15));
    printCadetInfo(readCadetBlk(numCadets - 1));

    return 0;
}