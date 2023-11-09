/** lab09functs.c
* ===========================================================
* Name: Jacob Dunn / 03 SEP 2020
* Section: M3
* Project: Lab 09
* Purpose: Use VSC
* ===========================================================
*/

#define _USE_MATH_DEFINES
#include <math.h>
#include "lab09functs.h"

double volumeCylinder(double radius, double heightC) {
    double volumeC = M_PI * radius * radius * heightC;
    return volumeC;
}

double volumeBox(double length, double width, double heightB) {
    double volumeB = length * width * heightB;
    return volumeB;
}

double degToRad(int degrees) {
    double radians = degrees * ((2 * M_PI) / 360);
    return radians;
}