/** labfuncts.h
 * ===========================================================
 * Name: First Last
 * Section: xxx
 * Project: Lab 10 - 2D Arrays
 * ===========================================================
 */
#ifndef LAB10_H
#define LAB10_H

#include <stdint.h>

typedef struct PixelStruct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} PixelType;

/** ----------------------------------------------------------
 * @brief allocates 2D array of type PixelType using pointer to pointer technique
 * @param width the width of the picture in pixels
 * @param height the height of the picture in pixels
 * @return pointer to allocated memory
 * @pre width and height are positive ints
 * @post memory is allocated
 * ----------------------------------------------------------
 */
PixelType** allocate2DPixelType(int width, int height);

/** ----------------------------------------------------------
 * @brief Fills a matrix with random pixel values for
 *        red, green, and blue pixels.  Values range from
 *        0 to 255.
 * @param picture the picuture to be filled
 * @param width the width of the picture in pixels
 * @param height the height of the picture in pixels
 * @return Nothing
 * @pre picture is a valid pointer to image of size width x height
 * @post the image will be populated with values [0 - 255]
 * ----------------------------------------------------------
 */
void fillPic(PixelType** picture, int width, int height);

/** ----------------------------------------------------------
 * @brief Prints the rgb color values for each pixel
 * @param picture the picture to be printed
 * @param width the width of the picture in pixels
 * @param height the height of the picture in pixels
 * @return Nothing
 * @pre picture is a valid pointer to image of size width x height
 * @post the image will be displayed
 * * ----------------------------------------------------------
 */
void printPic(PixelType** picture, int width, int height);

/** ----------------------------------------------------------
 * @brief Adds two pictures pixel values and stores the result
 *        in a third picture
 * @param picture1 the first picture
 * @param picutre2 the second picture
 * @param width the width of the picture in pixels
 * @param height the height of the picture in pixels
 * @return a pointer to the newly alllcated resulting picture
 * @pre picture1 and picture2 are valid pointers to images of size width x height
 * @post the returned pointer will point to an image of the same size
 * ----------------------------------------------------------
 */
PixelType** addPic(PixelType** picture1, PixelType** picture2, int width, int height);

/** ----------------------------------------------------------
 * @brief deallocates the memory for a picture
 * @param picture the picture to be deallocated
 * @param width the width of the picture in pixels
 * @param height the height of the picture in pixels
 * @return Nothing
 * @pre picture is a valid pointer to allocated memory of sixe width x height
 * @post memory is deallocated
 * ----------------------------------------------------------
 */
void deallocPic(PixelType** picture, int width, int height);

#endif  // LAB10_H