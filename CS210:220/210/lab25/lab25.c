/** lab25.c
* ==============================================================
* Name: Jacob Dunn / 21 Oct 2020
* Section: M3
* Project: Lab25
* Purpose: Write Code
* ==============================================================
*/

#include "lab25.h"

int main()
{
    Point userPoint1;
    Point userPoint2;
    getPoints(&userPoint1, &userPoint2);
    printf("Calculated Distance = %.2lf\n", getDistance(userPoint1, userPoint2));

    USAFBaseData** baseDataPtr = malloc(getNumLines("lab25Data.csv") * sizeof(USAFBaseData));
        for(int i = 0; i<getNumLines("lab25Data.csv"); i++)
        {
            baseDataPtr[i] = malloc(sizeof(USAFBaseData));
        }

    readFile("lab25Data.csv", baseDataPtr, getNumLines("lab25Data.csv"));

    printData(baseDataPtr, getNumLines("lab25Data.csv"));

    return 0;
}



void getPoints(Point* point1, Point* point2)
{
    printf("Enter two numbers seperated by a space: ");
    scanf("%d %d", &point1 -> x, &point1 -> y);
    scanf("%d %d", &(*point2).x, &(*point2).y);
}

double getDistance(Point point1, Point point2)
{
    double distance = sqrt(((point1.x - point2.x) * (point1.x - point2.x)) - ((point1.y - point2.y) * (point1.y - point2.y)));
    return distance;
}

int getNumLines(char filename[])  
{  
    char c;  
    int count = 0;  
    // Open the file  
    FILE* fp = fopen(filename, "r");  

    // Check if file exists  
    if (fp == NULL) {  
        fprintf(stderr, "Could not open file %s", filename);  
        return -1;  
    }  

    // Extract characters from file and store in character c  
    for (c = getc(fp); c != EOF; c = getc(fp)) {  
        // count newline chars 
        if (c == '\n') { 
           count++;
        }
    }  

    // Close the file  
    fclose(fp); 

    return count;  
}

void readFile(char fileName[], USAFBaseData** baseDataPtr, int lines)
{
    FILE* inFile = fopen(fileName, "r");

    for(int i = 0; i<lines; i++)
    {
        fscanf(inFile, "%[^,], %d, %d, %[^,], %[^\n]", (baseDataPtr[i] -> baseName), &(baseDataPtr[i] -> bldgsOwned), &baseDataPtr[i] -> structsOwned, baseDataPtr[i] -> city, baseDataPtr[i] -> state);
    }
    
    fclose(inFile);
}

void printData(USAFBaseData** baseDataPtr, int numBases)
{
    for (int i=1; i<numBases; ++i)
    {
        printf("%s, %d, %d, %s, %s\n\n", (baseDataPtr[i] -> baseName), (baseDataPtr[i] -> bldgsOwned), (baseDataPtr[i] -> structsOwned), (baseDataPtr[i] -> city), (baseDataPtr[i] -> state));
    }
}