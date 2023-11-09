/** pex2functs.c
* ==============================================================
* Name: Jacob Dunn / 18 Oct 2020
* Section: M3
* Project: PEX2
* Purpose: Write Code
* ==============================================================
*/

#include "pex3functs.h" 

/** @fn readFile
*   @brief reads in DNA sequences from a text file and stores them in an array of structs
*   @param fileName name of the species
*   @param sequences dna sequence for that species
*   @return the number of DNA sequences read from the file
*/
int readFile(char fileName[], DNA sequences[])
{
    int count = 0;
    int i = 0;
    FILE* inFile = fopen(fileName, "r"); //opens the file
    while (feof(inFile) == 0) //runs while file is not at the end
    {
        fscanf(inFile, "%s %s", sequences[i].species, sequences[i].dna);
        count++;
        i++;
    }
    fclose(inFile);
    return count - 1; //returns the number minus the blank line at the end
}

/** @fn printSequences
*   @brief prints out all DNA sequences stored in a DNA array
*   @param sequences dna sequence for a species
*   @param numSeq number of sequences in the array
*/
void printSequences(DNA sequences[], int numSeq)
{
    for (int i=0; i<numSeq; i++)
    {
        printf("DNA Type-> %s\nSequence-> %s\n", sequences[i].species, sequences[i].dna);
        if(i != numSeq -1) //adds a new line to every line except the last one
        {
            printf("\n");
        }
    }
}


/** @fn hammingDistance
*   @brief computes described distance
*   @param str1 one string of a partial dna sequence 
*   @param str2 one string of a partial dna sequence
*   @return returns described distance
*/
int hammingDistance(char str1[], char str2[])
{
    int count = 0;
    if(strlen(str1) == strlen(str2)) //runs when strings are the same
    {
        for (int i=0; i<strlen(str2); i++)
        {
            if(str1[i] != str2[i]) //counts when the characters are not the same
            {
                count++;
            }
        }
    }
    else
    {
        return -1; //returns -1 when strings are different lengths
    }
    return count;
}


/** @fn similarityScore
*   @brief computes the similarity score of two genomes
*   @param seq1 one string of a sequence
*   @param seq2 one string of a sequence
*   @return the result of this calculation when given two sequences
*/
float similarityScore(char seq1[], char seq2[])
{
    float length = strlen(seq2); //length is the length of the smaller string
    float hd = hammingDistance(seq1, seq2);
    float score = (length - hd) / length; //calculates score
    return score;
}


/** @fn countMatches
*   @brief count the number of matches a given sequence has in a given genome
*   @param genome one string of dna
*   @param seq a string of a partial dna sequence for comparrison
*   @param minScore minimum required score to be considered a match
*   @return the number of matches found
*/
int countMatches(char genome[], char seq[], float minScore)
{
    int count = 0;
    int len = ((strlen(genome)) - (strlen(seq))) + 1; //sets length so it doesn't run past the final characters of length
    for(int i = 0; i<len; i++)
    {
        char c[4] = ""; //sets array blank every iteration
        strncpy(c, genome+i, 3); //creates substring and starts one character over each time
        if(similarityScore(c, seq) >= minScore)
        {
            count++;
        }
    }
    return count;
}


/** @fn findBestMatch
*   @brief selects the best match by comparing similarity scores at every position in the genome for a given sequence 
*   @param genome one string of dna
*   @param seq a string of a partial dna sequence for comparrison
*   @return the highest simiilarity score found
*/
float findBestMatch(char genome[], char seq[])
{
    int len = ((strlen(genome)) - (strlen(seq))) + 1; //sets length so it doesn't run past the final characters of length
    float score[len];
    float MAX = 0;
    for(int i = 0; i<len; i++)
    {
        char c[500] = ""; //sets array blank every iteration
        strncpy(c, genome+i, strlen(seq)); //creates substring and starts one character over each time of size of sequence
        score[i] = similarityScore(c, seq);
        if(score[i] > MAX)
        {
            MAX = score[i];
        }
    }
    return MAX;
}


/** @fn findBestGenome
*   @brief finds the best match in the array of genome sequences when given a sequence to match
*   @param sequences array of dna sequences for a species
*   @param numSeq number of sequences in array
*   @param unknownSeq unknown sequence for comparison
*   @return the index of the genome array indicating where the best match was found
*/
int findBestGenome(DNA sequences[], int numSeq, char unknownSeq[])
{
    float MAX = 0.0;
    int index = 0;
    float score = 0.0;
    for (int i = 0; i<numSeq; i++)
    {
        score = findBestMatch(sequences[i].dna, unknownSeq); //runs findBestMatch for each line in file
        if (score > MAX)
        {
            MAX = score;
            index = i;
        }
    }
    return index;
}