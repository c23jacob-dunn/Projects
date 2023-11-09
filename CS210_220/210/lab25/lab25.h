/** lab25.h
* ==============================================================
* Name: Jacob Dunn / 21 Oct 2020
* Section: M3
* Project: Lab25
* Purpose: Write Code
* ==============================================================
*/

#ifndef lab25functs_h
#define lab25functs_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct PointStruct {
    int x;
    int y;
} Point;

typedef struct BaseStruct{
    char baseName[50];
    int bldgsOwned;
    int structsOwned;
    char city[50];
    char state[30];
} USAFBaseData;

void getPoints(Point* x, Point* y);

double getDistance(Point x, Point y);

int getNumLines(char filename[]);

void readFile(char fileName[], USAFBaseData** baseDataPtr, int lines);

void printData(USAFBaseData** bases, int numBases);

#endif