/** lab09functs.c
 * ===========================================================
 * Name: First Last
 * Section: xxx
 * Project: Lab 10 - 2D Arrays
 * ===========================================================
 */
#include "lab10functs.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

PixelType** allocate2DPixelType(int width, int height) {
    return NULL;
}

void fillPic(PixelType** picture, int width, int height) {
    // set up for and then seed random number generator
    static int seedDone = 0;  // static variables retain their value between calls

    // if random number generator has been seeded already don't do it again
    if (!seedDone) {
        //srand((unsigned)(time(NULL)));  // use for development/debugging
        srand(2023); // uncomment for submission
        seedDone = 1;
    }

    // fill pixels with random ints between 0 and 255
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            picture[row][col].red = rand() % 256;
            picture[row][col].green = rand() % 256;
            picture[row][col].blue = rand() % 256;
        }
    }
}

void printPic(PixelType** picture, int width, int height) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            printf("%d", picture[row][col].red);
            printf("%d", picture[row][col].blue);
            printf("%d", picture[row][col].green);
        }
    }
}

PixelType** addPic(PixelType** picture1, PixelType** picture2, int width, int height) {
    return NULL;
}

void deallocPic(PixelType** picture, int width, int height) {
}