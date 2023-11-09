#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "lab26.h"
#include "vector.h"

int main(void)
{
   // With the functions provided in the Vector ADT,
   //   create a correctly sized vector to read-in all
   //   data from the lab26Data.csv file
   
   // Utilize your readFile() function from Lab 25
   //   to populate the vector -- you will need to make changes
   //   for this function to perform correctly
   //   To view the contents of the array of elements while using the debugger in VSC, add a watch statement 
   //   using the vector pointer in readFile. In the example below, vectorPtr is the vector* passed during a call
   //   to readFile().
   //   (int[1000])*(vectorPtr->elements)

   char fileName[] = "lab26Data.csv";
   int lines = getNumLines(fileName);
   printf("Lines = %d\n.", lines);
   vector v;
   vector_create(&v, lines);
   printf("Vector Created.\n");
   readFile(fileName, &v, lines);
   printData(&v, lines);
  
   // With the functions provided in the Vector ADT,
   //   print the number of vector elements
   printf("%d\n", vector_size(&v));

   // With the functions provided in the Vector ADT,
   //   insert a 12 at index 139
   vector_insert(&v, 139, 12);

   // With the functions provided in the Vector ADT,
   //   print the number of vector elements
   printf("%d\n", vector_size(&v));
    
   // With the functions provided in the Vector ADT,
   //   print the element at index 999
   printf("%d\n", *(vector_at(&v, 999)));
    
   // With the functions provided in the Vector ADT,
   //   erase the element at index 999
   vector_erase(&v, 999);

   // With the functions provided in the Vector ADT,
   //   print the element at index 999
   printf("%d\n", *(vector_at(&v, 999)));

   // With the functions provided in the Vector ADT,
   //   print the number of vector elements
   printf("%d\n", vector_size(&v));

    // Using the Vector ADT provided function
    //   vector_push_back to insert the integer 222
   vector_push_back(&v, 222);

   // With the functions provided in the Vector ADT,
   //   print the number of vector elementss
   printf("%d\n", vector_size(&v));

   // With the functions provided in the Vector ADT,
   //   destroy the vector
   vector_destroy(&v);
}

void readFile(char filename[], vector* vectorPtr, int records)
{
   FILE* inFile = fopen(filename, "r");
   for(int i = 0; i<records; i++)
   {
      fscanf(inFile, "%d", vector_at(vectorPtr, i));
   }
   fclose(inFile);
}