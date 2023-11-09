/** lab23functs.c
* ==============================================================
* Name: Jacob Dunn / 18 Oct 2020
* Section: M3
* Project: Lab23
* Purpose: Write Code
* ==============================================================
*/

/** @fn functionName
*   @brief function description
*   @param variableName variable description
*   @return describes what function returns
*/

#include "lab23functs.h"

int getNumRecs(FILE* dataFile)
{
    FILE* myFile = NULL;
    myFile = fopen("lab23Data.txt", "r");
    int fileNum;
    fscanf(myFile, "%d", &fileNum);
    //fclose(myFile);
    return fileNum;
}

void getDataText(CadetInfoStructType cadetRecords[], int numRecs, char dataFile[])
{
    FILE* in = fopen(dataFile, "r");
    if (in == NULL)
    {
        printf("Error opening data file: %s.\n", strerror(errno));
        exit(1);
    }

    char firstName[30];
    char lastName[45];
    int numRead = 0;

    fgets(lastName, 80, in);
    while (numRead < numRecs && !feof(in))
    {
        fscanf(in, "%s %s %d %d %d", lastName, firstName, &cadetRecords[numRead].age, &cadetRecords[numRead].squad, &cadetRecords[numRead].year);
        strcat(firstName, " ");
        strcpy(cadetRecords[numRead].name, strcat(firstName, lastName));
        numRead++;
    }
    fclose(in);
}

void printCadetInfo(CadetInfoStructType cadetRecord)
{
    printf("Cadet name = %s\n", cadetRecord.name);
}