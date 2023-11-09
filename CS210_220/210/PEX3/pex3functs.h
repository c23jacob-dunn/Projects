/** pex2functs.h
* ==============================================================
* Name: Jacob Dunn / 18 Oct 2020
* Section: M3
* Project: PEX2
* Purpose: Write Code
* ==============================================================
*/

#ifndef pex2functs_h
#define pex2functs_h

#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct DNAStruct {
    char species[20];
    char dna[500];
} DNA;

int readFile(char fileName[], DNA sequences[]); //gets number of lines in data file
void printSequences(DNA sequences[], int numSeq); //prints names and dna sequences in file
int hammingDistance(char str1[], char str2[]); //computes differences between strings
float similarityScore(char seq1[], char seq2[]); //computes score 0-1 between strings
int countMatches(char genome[], char seq[], float minScore); //counts the number of matches in the string
float findBestMatch(char genome[], char seq[]); //finds the string that most matches the given string
int findBestGenome(DNA sequences[], int numSeq, char unknownSeq[]); //finds which species most matches the given string

#endif