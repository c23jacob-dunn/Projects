/** lab10.c
 * ===========================================================
 * Name: First Last
 * Section: xxx
 * Project: Lab 10 - 2D Arrays
 * ===========================================================
 * Instructions:
 *    1) Complete TASKS Below
 */
#include <stdio.h>
#include <stdlib.h>

#include "lab10functs.h"

int main(int argc, char** argv) {
    if (3 > argc) {
        fprintf(stderr, "incorrect number of command line arguments.\n");
        fprintf(stderr, "expecting 3; only found: %d\n", argc);
        exit(1);
    }

    /* TASK 0a - In the header file is a struct that defines color values
     *           for a pixel (Red, Green, and Blue).
     *
     *           Implement allocate2DPixelType() to dynamically
     *           allocate a 2D arrays of PixelType with dimensions of width x height.
     *           Use the pointer to pointer method as shown in the slides.
     */

    // TASK 0b - Get width and height parameters from argv
    int width = 0;
    int height = 0;

    // TASK 0c - Allocate myPicOne using allocate2DPixelType()
    PixelType** myPicOne = NULL;

    /* TASK 1 - Implement the function printPic() and call it on
     *          the array allocated above after you have filled
     *          it by calling fillPic()
     *
     *          Example print of 2 x 3 picture RGB values
     *          for each pixel in parentheses
     *          (   2,  34, 118) ( 186, 195, 176)
     *          ( 185,   2, 133) ( 240,  12, 223)
     *          ( 184,  27,  90) (  37,  82,  99)
     */

    fillPic(myPicOne, width, height);
    printPic(myPicOne, width, height);

    /* TASK 2 - Implement the function addPic(), allocate and fill
     *           another array of the same size using the pointer to
     *           pointer method.  Call the addPic() function using
     *           the array allocated in task 0 and the new one and
     *           print the resulting picture.
     *
     *           Name the pointer to the pointer myPicTwo.
     */

    // TASK 2a - Allocate myPicOne using allocate2DPixelType()
    PixelType** myPicTwo = NULL;

    fillPic(myPicTwo, width, height);
    printPic(myPicTwo, width, height);

    PixelType** myPicThree = addPic(myPicOne, myPicTwo, width, height);
    printPic(myPicThree, width, height);

    /* TASK 3 - Implement the function deallocPic()
     *          call it as appropriate
     */
    deallocPic(myPicOne, width, height);
    deallocPic(myPicTwo, width, height);
    deallocPic(myPicThree, width, height);

    return 0;
}