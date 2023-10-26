#include <stdio.h>
#define inputArraySize 8
int inputArray[] = [1,4,3,6,5,2,7,8];

int FindMax(int inputArray) {
   int max = inputArray[0];

   for (int i = 1; i < inputArraySize; i++) {
      if (inputArray[i] > max) {
         max = inputArray[i];
      }
   }

   return max;
}

int main(){
    return FindMax(inputArray);
    printf("%d", FindMax(inputArray));
}