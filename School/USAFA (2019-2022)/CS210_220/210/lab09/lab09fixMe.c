/** lab09.c
* ===========================================================
* Name: Jacob, Dunn
* Section: M3
* Project: Lab 9
* Purpose: Debugging
* ===========================================================
* Instructions:
 * Complete the tasks outlined in the lab writeup.
*/


#include <stdio.h>

double convertTemperature(double fahrenheit);    
int findLargest(int n1, int n2, int n3);

int main() { 
    // findLargest()
    int n1, n2, n3;

    printf("Enter three integer numbers: ");
    scanf("%d %d %d", &n1, &n2, &n3);            
    int largest = findLargest(n1,n2,n3);
    printf("%d\n", largest);

    // convertTemperature()
    double fahrenheit;
    printf("Please enter a temperature in fahrenheit: \n");
    scanf("%lf\n", &fahrenheit);
    double celsius1 = convertTemperature(fahrenheit);
    printf("%lf\n", celsius1);
}

int findLargest(int n1, int n2, int n3) {
        if ( n1>=n2 && n1>=n3) {  
            return n1;
        }

        else if (n2>=n1 && n2>n3){
            return n2;
        }

        else {                  
            return n3;
        }
}

double convertTemperature(double fahrenheit) {
        double celsius2 = (5.0/9.0) * (fahrenheit - 32.0);
        return celsius2;
}