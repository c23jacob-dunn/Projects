/** lab35.c
* ===========================================================
* Name: FIRST LAST, DATE
* Section: SECTION
* Documentation: YOUR DOC STATEMENT
* ===========================================================  */

#include "lab35.h"

int main()
{
    // Exercise 1
    printf("\nExercise 1: sum_squares()\n\n");
    
    printf("%d\n", sum_squares(4));
    
    // Exercise 2
    printf("\nExercise 2: is_even()\n\n");
    
    printf("%d\n", is_even(4));
    
    // Exercise 3
    printf("\nExercise 3: power_two()\n\n");
    
    printf("%d\n", power_two(4));
    
    // Exercise 4
    printf("\nExercise 4: reverse_bytes()\n\n");
    
    printf("%d\n", reverse_bytes(0xffffdece));
    
    // Exercise 5
    printf("\nExercise 5: is_palindrome()\n\n");
   
    printf("%d\n\n", is_palindrome("[bnlnb[",  7));
   
    return 0;
}

int sum_squares(int N)
{
    if(N == 1)
    {
        return 1;
    }
    return N*N + sum_squares(N-1);
}

int is_even(int x)
{
    if((x&1) == 1)
    {
        return 0;
    }
    return 1;
}

int power_two(int N)
{
    return (1<<N);
}

int reverse_bytes(unsigned int val)
{
    //AND = 0-Sets Low 1-Preserves
    //OR = 0-Preserves 1-Sets High
    //XOR = 0-Preserves 1-Inverts

    return 0;
}

int is_palindrome(char message[], int len)
{
    int index = 1 + ((strlen(message)) - (len));
    if(len == 0)
    {
        return 1;
    }
    if(message[len - 1] == message[index - 1])
    {
        return is_palindrome(message, len-1);
    }
    else
    {
        return 0;
    }
    
}
