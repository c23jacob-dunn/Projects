/** lab19main.c
* ==============================================================
* Name: Jacob Dunn / 3 October 2020
* Section: M3/4
* Project: lab19
* Purpose: Learn Code
* Documentation Statement: None
* ==============================================================
*/

#include "lab19functs.h"

int main()
{
    char str[MAX_STR_LEN], searchChars[MAX_STR_LEN];
    int locations[MAX_STR_LEN];
    char aChar, bChar, rChar, searchChar;

    printf("Enter a string: ");
    scanf("%[^\n]s", str);
    printf("Enter a test Char followed by a serach Char: ");
    scanf(" %c %c", &aChar, &bChar);
    replStr(str, aChar, bChar);

    printf("Enter a string: ");
    scanf(" %[^\n]s", str);
    printf("Enter a string of search Chars: ");
    scanf(" %[^\n]s", searchChars);
    printf("Enter replacement Char: ");
    scanf(" %c", &rChar);
    replMultiChar(str, searchChars, rChar);

    printf("Enter a string: ");
    scanf(" %[^\n]s", str);
    printf("Enter a character whose locations you wish to find: ");
    scanf(" %c", &searchChar);
    findLocations(str, locations, searchChar);
}