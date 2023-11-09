/** lab34.c
* ===========================================================
* Name: FIRST LAST, DATE
* Section: SECTION
* Project: Lab 34
* Documentation: DOC STATEMENT
* ===========================================================  */

#include "lab34.h"

int main() {

    // Exercise 1
    printf("\nExercise 1: reverse_bits()\n\n");
    // Bit operations are commonly used in cryptographic or
    // data integrity checks to manipulate bits in the data in
    // interesting ways.
    // Write a function reverse_bits(), that accepts an integer
    // parameter and returns the input value with its bits in reverse
    // order. Note that to avoid the special case of right shifting
    // signed values your prototype should accept an unsigned int,
    // initialize an unsigned int to hold the reversed bits, but
    // return an int. You should use the left shift, right shift, &,
    // and | operators to accomplish this.
    //
    // Extra: It is possible to write this function using only bit operations.

    uint8_t input = 5;
    printf("%d\n", reverse_bits(input));

    // Exercise 2
    printf("\nExercise 2: bit_rotate_left()\n\n");
    // Write a function bit_rotate_left(), which shifts bits to the left,
    // any bits that would be discarded when using a standard left
    // shift are added back to the right bits. Your function will
    // accept an unsigned int (the value to be rotated), and an int
    // which is the number of bits to rotate the value. This is known
    // as bit rotate or a circular bit shift. You should use the left
    // shift, right shift, and | operators to accomplish this. Be sure
    // to use an unsigned type for values you will right shift to ensure
    // a logical bit shift. Return the rotated bit values as an int.

    printf("%d\n", bit_rotate_left(input, 3));

    // Exercise 3
    printf("\nExercise 3: bit_rotate_right()\n\n");
    // Write a function bit_rotate_right(), which shifts bits to the right,
    // any bits that would be discarded when using a standard right
    // shift are added back to the left bits. Your function will
    // accept an unsigned int (the value to be rotated), and an int
    // which is the number of bits to rotate the value. You should use the left
    // shift, right shift, and | operators to accomplish this. Be sure
    // to use an unsigned type for values you will right shift to ensure
    // a logical bit shift. Return the rotated bit values as an int.

    printf("%d\n", bit_rotate_right(input, 3));

    // Exercise 4
    printf("\nExercise 4: make_crc()\n\n");
    // A cyclic redundancy check (CRC) 
    // 3) calculate the table index by performing the following:
    //    xor the current message byte and the crc32 value, then save only
    //    the right most byte (this will be some value between 0 and 255)
    // 4) update the crc32 value by performing the following:
    //    settin crc32 equal to the crc32 value right shifted 8 bits and
    //    xor'd with the CRCTAB value at the previously calculated index

    printf("%d", make_crc(CRCTAB));

    return 0;
}

/** ----------------------------------------------------------
 * @fn void print_bits(void* ptr, int num_bytes)
 * @brief prints char representation of any variables individual bits
 * @param ptr is a pointer to the variable being printed
 * @param num_bytes is the number of bytes in the variable
 * @return void, prints each bit as a character, ends with a new line
 * ----------------------------------------------------------
 */
void print_bits(void* ptr, int num_bytes) {
    // Cast the pointer as an unsigned byte
    uint8_t* byte = ptr;

    // For each byte, (bytes are little endian ordered)
    for (int i = num_bytes - 1; i >= 0; --i) {

        // For each bit, (inside the byte, bits are big endian ordered)
        for (int j = 7; j >= 0; --j) {

            // Print a character 1 or 0, given the bit value
            printf("%c", (byte[i] >> j) & 1 ? '1' : '0');
        }

        // Separate bytes
        printf(" ");
    }

    // End with a new line
    printf("\n");
}

int reverse_bits(uint8_t param)
{
    uint8_t reverse_num = 0;
    for (int i = 0; i < 8; i++) 
    { 
        if((param & (1 << i)))
        {
           reverse_num |= 1 << (7 - i);  
        } 
    } 
    return reverse_num; 
}

int bit_rotate_left(uint8_t param, int num)
{
    return (num << param)|(num >> (8 - param));
}

int bit_rotate_right(uint8_t param, int num)
{
    return (num >> param)|(num << (8 - param));
}

uint32_t make_crc(char array[])
{
    uint32_t crc32 = 2147483647;
    char holdArray1[8];
    char holdArray2[8];
    char holdArray3[8];
    char holdArray4[8];
    for(int i=0;i<8;i++)
    {
        holdArray1[i] = array[i];
    }
    (holdArray1 ^ crc32);
    for(int i=8;i<16;i++)
    {
        holdArray2[i-8] = array[i];
    }
    
    for(int i=16;i<24;i++)
    {
        holdArray3[i-16] = array[i];
    }
    
    for(int i=24;i<32;i++)
    {
        holdArray4[i-24] = array[i];
    }
    
    return ~crc32;
}