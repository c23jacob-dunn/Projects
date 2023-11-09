/** lab33.h
* ===========================================================
* Name: FIRST LAST, DATE
* Section: SECTION
* Project: Lab 33
* Documentation: DOC STATEMENT
* ===========================================================  */

#ifndef MYEXE_LAB33_H
#define MYEXE_LAB33_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

/** ----------------------------------------------------------
 * @fn void print_bits(void* ptr, int num_bytes)
 * @brief prints char representation of any variables individual bits
 * @param ptr is a pointer to the variable being printed
 * @param num_bytes is the number of bytes in the variable
 * @return void, prints each bit as a character, ends with a new line
 * ----------------------------------------------------------
 */
void print_bits(void* ptr, int num_bytes);

int check_bit(int n, int spot);
int count_bits(int x);
int bit_parity(int x);
int flip_bit(int x, int bit);
uint8_t simple_checksum(char message[]);

#endif //MYEXE_LAB33_H