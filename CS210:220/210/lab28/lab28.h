/** lab28.c
* ===========================================================
* Name: Jacob Dunn, October 28 2020
* Section: M3
* Project: Progamming Assessment 3 Practice
* Documentation: None
* ===========================================================  */

#ifndef MYEXE_LAB28_H
#define MYEXE_LAB28_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct EmployeeBD_struct{
    char firstName[30];
    char lastName[30];
    char birthMonth[15];
    int birthDate;
} EmployeeBD;

int getNumLines(char fileName[]);
int numVowels(char filename[]);
char* sortString(char charArray[]);

int readFile(char fileName[], EmployeeBD* birthdayPtr, int eLines);
int IDEmpBDMonth(EmployeeBD* birthdayPtr, int linesRead, int month);
EmployeeBD readEmployeeArchive(int index);

#endif //MYEXE_LAB28_H