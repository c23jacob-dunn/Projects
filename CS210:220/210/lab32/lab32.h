/** lab32.h
* ===========================================================
* Name: FIRST LAST, DATE
* Section: SECTION
* Project: Lab 33
* Documentation: DOC STATEMENT
* ===========================================================  */

#ifndef MYEXE_LAB32_H
#define MYEXE_LAB32_H

#include <stdio.h>
#include <string.h>
#define DIRNAME "./password/"

/** ----------------------------------------------------------
 * @fn int factorial(int N)
 * @brief Recursively calculates the factorial of N
 * @param N, the input parameter
 * @return N!, the value of the factorial of N
 * ----------------------------------------------------------
 */
int factorial(int N);
int tail_factorial(int N, int accum);
int collatz(int N, int accum);
void decode_password(char fname[]);

#endif //MYEXE_LAB32_H
