/** pex2main.c
* ==============================================================
* Name: Jacob Dunn / 18 Oct 2020
* Section: M3
* Project: PEX2
* Purpose: Write Code
* Documentation Statement: Piper Gray and Greg Grey (Piper's dad) looked over my findBestGenome function 
  to figure out where the overflow error was. Piper and I were in my room and called her dad on teams when 
  I noticed the error was an undersized array in an earlier function that could not hold the contents of the 
  dna string located in sequenes[i].dna
* ==============================================================
*/

#include "pex3functs.h"

int main()
{
    DNA knownSequences[200];
    int numSequences = readFile("pex3Data1.txt", knownSequences); //gets the number of lines in the file
    printSequences(knownSequences, numSequences); //prints the species name and dna sequence
}