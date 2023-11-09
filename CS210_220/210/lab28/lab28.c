/** lab28.c
* ===========================================================
* Name: Jacob Dunn, October 28 2020
* Section: M3
* Project: Progamming Assessment 3 Practice
* Documentation: None
* ===========================================================  */

#include "lab28.h"

int main(void)
{
    //int getNumLines(char*);
    int lines = getNumLines("Employee_Recs.txt");
    printf("%d\n", lines);
 
    // PROBLEM 1 - STRING MANIPULATION
    //      a.) Define a function called numVowels that takes in a character array and outputs
    //      an integer.  The function itself finds the number of vowels within the provided character
    //      array. The character array may contain spaces and punctuation.

    int vowels = numVowels("The quick brown fox jumps over the lazy dog");
    printf("%d\n\n", vowels);

    //      b.) Define a function called sortString that expects an array of characters and
    //      and returns a pointer to an array of characters.  The function sorts the characters
    //      in the string in alphabetic order, stores them in this order, and returns a pointer to
    //      this sorted array of characters.
    //      The character array may contain spaces and punctuation. When sorting, spaces and punctuation
    //      should be ignored and all alphabetic characters should be changed to lowercase for
    //      sorting and output.
    //      NOTE: In order to return a pointer to an array of characters that has scope outside a
    //          function call, the memory used to store the sorted array must by dynamically
    //          allocated.

    char charArray[] = "The quick brown fox jumps over the lazy dog";
    printf("%s", sortString(charArray));
    printf("\n\n");

    // PROBLEM 2 - Manipulate Employee Data
    //      You are tasked to create a program that will pull employee records from a simple
    //      text file that contains name and birthdate.  The ultimate goal is to allow a user
    //      to input a month that will result in output to the screen displaying all of the
    //      employees with birthdays for the specified month.  This will assist the squadron
    //      commander with ensuring that all employee birthdays are recognized at the
    //      monthly staff meeting.

    //      a.) Define a structure type, named EmployeeBD, with appropriate members
    //      to store data from the Employee_Recs.txt file. Use the fields names:
    //      FirstName, lastName, birthMonth, and birthDate.

    //      b.) Use the getNumLines function provided to capture the number of records to be read from
    //      from the Employee_Recs.txt file, then dynamically allocate memory to store the employee data
    //      from the text file.

    int eLines = getNumLines("Employee_Recs.txt");
    EmployeeBD* birthdayPtr = malloc(eLines * sizeof(EmployeeBD));

    //      c.) Create a user-defined function called readFile, which requires the filename,
    //      memory passed by reference, and the number of records to be passed as parameters
    //      (in that order).  This function returns the integer value corresponding to the number
    //      of records successfully read.

    char fileName[] = "Employee_Recs.txt";
    int linesRead = readFile(fileName, birthdayPtr, eLines);

    //      d.) Create a user-defined function called IDEmpBDMonth to print the employee records
    //      for all employees born in a specified month.  This function accepts three parameters
    //      being the stored records passed by reference, the number of records, and the specified
    //      month for record printing (in that order).  It returns the number of records with the
    //      specified month.
    //      NOTE:  In main, ask the user to provide an integer from 1 - 12 that corresponds with the
    //          birth month they would like to query.
    //      Format the output to the screen as follows:
    //          Example if the user enters 10:
    //              Requested Birthdays are:
    //              Lastname	Firstname	Birthday
    //              *********************************************
    //              Smith		Brian		October 13

    int month = 12;
    IDEmpBDMonth(birthdayPtr, linesRead, month);

    //      e.) Create a user-defined function called readEmployeeArchive, which requires an index,
    //      an int, which identifies a specific Employee entry in the binary archive. 
    //      This function returns the EmployeeBD structre found at the provided index in the archive.
    //      The filename of the binary file is "EmployeeBDData.archive", provided by the lab.

    int index = 0;
    EmployeeBD structureVariable = readEmployeeArchive(index);
    printf("%s %s %s %d\n\n", structureVariable.firstName, structureVariable.lastName, structureVariable.birthMonth, structureVariable.birthDate);

    //      f.) There is a note from the previous exec that the first two members of the
    //      record (Brian Smith & Angie Thomas) have left the unit but the 15th & 17th entries
    //      in the archive still remain in the unit.  In your main(), update the first (0th) and the second
    //      (1st) entries in memory with the data in the 15 and 17th entries in the data file, use
    //      readEmployeeArchive() to read these entries from the file.  After updating the entries call
    //      IDEmpBDMonth(____, ___, 11) to print new November results.

    FILE* inFile = fopen("EmployeeBDData.archive", "w");
    fwrite(, sizeof(EmployeeBD), , inFile);
    readEmployeeArchive(15);
    readEmployeeArchive(17);
    fclose(inFile);

    return 0;
}

int getNumLines(char filename[])
{
    char c;
    int count = 0;
    // Open the file
    FILE* fp = fopen(filename, "r");

    // Check if file exists
    if (fp == NULL)
    {
        printf("Could not open file %s", filename);
        return 0;
    }

    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;

    // Close the file
    fclose(fp);
    //printf("The file %s has %d lines\n ", filename, count);

    return count;
}

int numVowels(char fileName[])
{
    int count = 0;
    int length = strlen(fileName);
    for(int i=0; i<length; i++)
    {
        switch(fileName[i])
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                count++;
        }
    }
    return count;
}

char* sortString(char charArray[])
{
    int numElements = strlen(charArray);
    char *strPtr;
    strPtr = (char*)malloc(numElements * sizeof(char));
    int j=0;
    for(int i=0; i<numElements; i++)
    {
        if (isalpha(charArray[i])==1)
        {
            charArray[i] = tolower(charArray[i]);
            strPtr[j] = charArray[i];
            j++;
        }
    }
    int len = strlen(strPtr);
    for(int i=0; i<(len * len); i++)
    {
        for(j=0; j<len-(i +1); j++)
        {
            if((strPtr[j] - strPtr[j+1]) > 0)
            {
                char holdChar;
                holdChar = strPtr[j];
                strPtr[j] = strPtr[j+1];
                strPtr[j+1] = holdChar;
            }
        }
    }
    return strPtr;
}

int readFile(char fileName[], EmployeeBD* birthdayPtr, int eLines)
{
    int numRecords = 0;
    FILE* inFile = fopen(fileName, "r");
    for(int i=0; i<eLines; i++)
    {
        fscanf(inFile, "%s %s %s %d", birthdayPtr[i].firstName, birthdayPtr[i].lastName, birthdayPtr[i].birthMonth, &birthdayPtr[i].birthDate);
        numRecords++;
    }
    fclose(inFile);
    return numRecords;
}

int IDEmpBDMonth(EmployeeBD* birthdayPtr, int linesRead, int month)
{
    FILE* inFile = fopen("Employee_Recs.txt", "r");
    int count = 0;
    printf("Lastname\tFirstname\tBirthday\n*********************************************\n");
    for(int i=0; i<linesRead; i++)
    {
        switch(month)
        {
            case 1:
                if(strcmp(birthdayPtr[i].birthMonth, "January") == 0)
                {
                    printf("%-12s\t%-12s\t%s %d\n", birthdayPtr[i].lastName, birthdayPtr[i].firstName, birthdayPtr[i].birthMonth, birthdayPtr[i].birthDate);
                    count++;
                }
                break;
            case 2:
                if(strcmp(birthdayPtr[i].birthMonth, "February") == 0)
                {
                    printf("%-12s\t%-12s\t%s %d\n", birthdayPtr[i].lastName, birthdayPtr[i].firstName, birthdayPtr[i].birthMonth, birthdayPtr[i].birthDate);
                    count++;
                }
                break;
            case 3:
                if(strcmp(birthdayPtr[i].birthMonth, "March") == 0)
                {
                    printf("%-12s\t%-12s\t%s %d\n", birthdayPtr[i].lastName, birthdayPtr[i].firstName, birthdayPtr[i].birthMonth, birthdayPtr[i].birthDate);
                    count++;
                }
                break;
            case 4:
                if(strcmp(birthdayPtr[i].birthMonth, "April") == 0)
                {
                    printf("%-12s\t%-12s\t%s %d\n", birthdayPtr[i].lastName, birthdayPtr[i].firstName, birthdayPtr[i].birthMonth, birthdayPtr[i].birthDate);
                    count++;
                }
                break;
            case 5:
                if(strcmp(birthdayPtr[i].birthMonth, "May") == 0)
                {
                    printf("%-12s\t%-12s\t%s %d\n", birthdayPtr[i].lastName, birthdayPtr[i].firstName, birthdayPtr[i].birthMonth, birthdayPtr[i].birthDate);
                    count++;
                }
                break;
            case 6:
                if(strcmp(birthdayPtr[i].birthMonth, "June") == 0)
                {
                    printf("%-12s\t%-12s\t%s %d\n", birthdayPtr[i].lastName, birthdayPtr[i].firstName, birthdayPtr[i].birthMonth, birthdayPtr[i].birthDate);
                    count++;
                }
                break;
            case 7:
                if(strcmp(birthdayPtr[i].birthMonth, "July") == 0)
                {
                    printf("%-12s\t%-12s\t%s %d\n", birthdayPtr[i].lastName, birthdayPtr[i].firstName, birthdayPtr[i].birthMonth, birthdayPtr[i].birthDate);
                    count++;
                }
                break;
            case 8:
                if(strcmp(birthdayPtr[i].birthMonth, "August") == 0)
                {
                    printf("%-12s\t%-12s\t%s %d\n", birthdayPtr[i].lastName, birthdayPtr[i].firstName, birthdayPtr[i].birthMonth, birthdayPtr[i].birthDate);
                    count++;
                }
                break;
            case 9:
                if(strcmp(birthdayPtr[i].birthMonth, "September") == 0)
                {
                    printf("%-12s\t%-12s\t%s %d\n", birthdayPtr[i].lastName, birthdayPtr[i].firstName, birthdayPtr[i].birthMonth, birthdayPtr[i].birthDate);
                    count++;
                }
                break;
            case 10:
                if(strcmp(birthdayPtr[i].birthMonth, "October") == 0)
                {
                    printf("%-12s\t%-12s\t%s %d\n", birthdayPtr[i].lastName, birthdayPtr[i].firstName, birthdayPtr[i].birthMonth, birthdayPtr[i].birthDate);
                    count++;
                }
                break;
            case 11:
                if(strcmp(birthdayPtr[i].birthMonth, "November") == 0)
                {
                    printf("%-12s\t%-12s\t%s %d\n", birthdayPtr[i].lastName, birthdayPtr[i].firstName, birthdayPtr[i].birthMonth, birthdayPtr[i].birthDate);
                    count++;
                }
                break;
            case 12:
                if(strcmp(birthdayPtr[i].birthMonth, "December") == 0)
                {
                    printf("%-12s\t%-12s\t%s %d\n", birthdayPtr[i].lastName, birthdayPtr[i].firstName, birthdayPtr[i].birthMonth, birthdayPtr[i].birthDate);
                    count++;
                }
                break;
        }
    }
    fclose(inFile);
    printf("\n");
    return count;
}

EmployeeBD readEmployeeArchive(int index)
{
    EmployeeBD entry;
    FILE* inFile = fopen("EmployeeBDData.archive", "rb");
    fseek(inFile,sizeof(EmployeeBD)*index,SEEK_SET);
    fread(&entry, sizeof(EmployeeBD), 1, inFile);
    fclose(inFile);
    return entry;
}