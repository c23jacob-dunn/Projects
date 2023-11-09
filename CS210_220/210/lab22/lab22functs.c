/** lab22functs.h
 * ===========================================================
 * Name: Jacob Dunn / 10Oct2020
 * Section: M3/4
 * Project: Lab 22
 * ===========================================================
 */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "lab22functs.h"

/** ----------------------------------------------------------
 * writeDataBlk() is used to the entire cadet record array
 * to a binary file
 * @param cadetRecords is the array of cadet records
 * @param numCadets is the total number of cadets to write
 * @return number of records wrote
 * ----------------------------------------------------------
 */
int writeDataBlk(MyCadetInfo cadetRecords[], int numCadets) {

    // Open an output file for writing
    FILE *out = fopen("lab22Data.bin", "wb");
    if (out == NULL) {
        printf("Error creating data file: %s.\n", strerror(errno));
        exit(1);
    }

    size_t retVal = fwrite(cadetRecords,sizeof(MyCadetInfo), numCadets, out);
    fclose(out);
    return retVal;

}

/** ----------------------------------------------------------
 * writeCadetBlk() is used to write a single cadet records
 * to a binary file the previous contents of the file are
 * not changed
 * @param cadet is the address of the cadet structure to write
 * @param location is the offset from the from of the file to
 *                 write the record to
 * @return number of records wrote
 * ----------------------------------------------------------
 */
int writeCadetBlk(MyCadetInfo* cadet, int location) {

    // Open an output file for writing
    FILE *out = fopen("lab22Data.bin", "rb+");
    if (out == NULL) {
        printf("Error creating data file: %s.\n", strerror(errno));
        exit(1);
    }
    fseek(out, sizeof(MyCadetInfo) * (long) location, SEEK_SET);
    int retVal = fwrite(cadet,sizeof(MyCadetInfo), 1, out);
    fclose(out);
    return retVal;
}

/** ----------------------------------------------------------
 * getDataText() is used to read MyCadetInfo typed records
 * from a file
 * @param cadetRecords is the array of cadet records
 * @return number of records read
 * ----------------------------------------------------------
 */
int getDataText(MyCadetInfo cadetRecords[]) {

    // Open an input file for reading
    FILE *in = fopen("lab22Data.txt", "r");
    if (in == NULL) {
        printf("Error opening data file: %s.\n", strerror(errno));
        exit(1);
    }

    char firstName[30];
    char lastName[45];
    int numRead = 0;

    while (numRead < MAXSTUDENTS && !feof(in)) {
        fscanf(in, "%s %s %d %d", firstName, lastName, &cadetRecords[numRead].squad,
               &cadetRecords[numRead].classYear);
        strcat(firstName, " ");
        strcpy(cadetRecords[numRead].name, strcat(firstName, lastName));
        numRead++;
    }
    fclose(in);
    return numRead;
}

/** ----------------------------------------------------------
 * printCadetInfo() is used to print a MyCadetInfo typed variable
 * to the console
 * @param cadetRecord is the cadet info struct to be printed
 * @return n/a
 */
void printCadetInfo(MyCadetInfo cadetRecord) {
    printf("Cadet name = \t%s\n", cadetRecord.name);
    printf("Cadet squad = \t%d\n", cadetRecord.squad);
    printf("Cadet year = \t%d\n\n", cadetRecord.classYear);
}

/** ----------------------------------------------------------
 * printData() is used to print MyCadetInfo typed records
 * from a file
 * @param datums is the array of cadet records
 * @param numCadets is the number of cadets in datums
 * @return n/a
 */
void printData(MyCadetInfo* datums, int numCadets) {
    for (int i = 0; i < numCadets; i++) {
        printCadetInfo(datums[i]);
    }
}

MyCadetInfo readCadetBlk(long someRecord)
{
    FILE* inFile = NULL;
    inFile = fopen("lab22data.txt", "rb");
    if (inFile == NULL) 
    {
      printf("Could not open file myfile.txt.\n");
      exit(1);
    }
    
    MyCadetInfo tempCadet;

    fseek(inFile, sizeof(MyCadetInfo) * (long) someRecord, SEEK_SET);
    fread(&tempCadet, sizeof(MyCadetInfo), 1, inFile);
    fclose(inFile);
    return tempCadet;
}

int updateClassYearNameBlk(MyCadetInfo cadetRecords[], int numCadets)
{
    char tempName[50];
    for(int i = 0; i < numCadets; i++)
    {
        if (cadetRecords[i].classYear == 2022)
        {
            strncpy(tempName, "C3C ", 5);
            strncpy(&tempName[4], cadetRecords[i].name, 46);
        }
        else if (cadetRecords[i].classYear == 2021)
        {
            strncpy(tempName, "C2C ", 5);
            strncpy(&tempName[4], cadetRecords[i].name, 46);
        }
        else
        {
            strncpy(tempName, "C1C ", 5);
            strncpy(&tempName[4], cadetRecords[i].name, 46);
        }
        strncpy(cadetRecords[i].name, tempName, 50);
    }
    FILE* out = fopen("lab22Data.bin", "wb");
    if (out == NULL) 
    {
      printf("Could not open file myfile.txt.\n");
      exit(1);
    }

    size_t retVal = fwrite(cadetRecords, sizeof(MyCadetInfo), numCadets, out);
    fclose(out);
    return retVal;
}

int updateSqdBlk(char* name, int newSquad, MyCadetInfo cadetRecords[], int numCadets)
{
    int location = -1;
    for (int i = 0; i < numCadets; i++)
    {
        if (strcmp(cadetRecords[i].name, name) == 0)
        {
            location = i;
        }
    }

    if (location == -1)
    {
        return -1;
    }

    FILE* out = fopen("lab22Data.bin", "wb");
    if (out == NULL) 
    {
      printf("Could not open file myfile.txt.\n");
      exit(1);
    }
    cadetRecords[location].squad = newSquad;
    fseek(out, sizeof(MyCadetInfo) * (long) location, SEEK_SET);
    int retVal = fwrite(&cadetRecords[location], sizeof(MyCadetInfo), 1, out);
    fclose(out);
    return retVal;
}