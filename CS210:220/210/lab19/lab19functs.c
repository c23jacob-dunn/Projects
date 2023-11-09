/** lab19functs.c
* ==============================================================
* Name: Jacob Dunn / 3 October 2020
* Section: M3/4
* Project: lab19
* Purpose: Learn Code
* ==============================================================
*/

/** @fn functionName
*   @brief function description
*   @param variableName variable description
*   @return describes what function returns
*/

#include "lab19functs.h"

void replStr(char str[], char aChar, char bChar)
{
    for(int i = 0; i<MAX_STR_LEN; ++i)
    {
        if(str[i] == aChar)
        {
            str[i] = bChar;
        }
    }
    printf("New string (between Arrows): -->%s<--\n\n", str);
}

void replMultiChar(char str[], char searchChars[], char rChar)
{
    char ch = '\0';while ((ch = getchar()) != '\n' && ch != EOF);
    int length = strlen(str);
    int length1 = strlen(searchChars);
    for(int i = 0; i<length; ++i)
    {
        for(int j = 0; j<length1; ++j)
        {
            if(str[i] == searchChars[j] && str[i] != ' ')
            {
                str[i] = rChar;
            }
        }
    }
    printf("New string (between Arrows): -->%s<--\n\n", str);
}

int findLocations(char str[], int locations[], char searchChar)
{
    int count = 0;
    int length = strlen(str);
    for(int i = 0; i<length; ++i)
    {
        if(str[i] == searchChar)
        {
            locations[i] = 1;
            ++count;
        }
        else
        {
            locations[i] = 0;
        }

    }
    printf("There are %d occurances of %c.\n", count, searchChar);
    for(int j = 0; j < length; ++j)
    {
        if(locations[j] == 1)
        {
            printf("%c found at location %d.\n", searchChar, j);
        }
    }
    return count;
}