#include <stdio.h>
#include <stdlib.h>

void get_string(char* sentence);
int count_string(char* sentence);
void allocate(int size, char** ppNewSentence);
void string_copy(char* word1, char* word2);

int main(void)
{
    char sentence[50];
    char* pNewSentence;
    char** ppNewSentence = &pNewSentence;
    int size;

    get_string(sentence);
    size = count_string(sentence);
    printf( "Length = %d characters\n", 
            size);
    allocate(size, ppNewSentence);
    string_copy(sentence, pNewSentence);

    return(0);
}

void get_string(char* sentence)
{
    printf("Give a word or sentence please\n");
    scanf(" %49[^\n]", sentence);
}

int count_string(char* sentence)
{
    int count = 0;

    while(sentence[count] != '\0')
    {
        count++;
    }
    return count + 1; // Adding space for terminating string
}

void allocate(int size, char** ppNewSentence)
{
    *ppNewSentence = malloc(size * sizeof(char));

    if(*ppNewSentence == NULL)
    {
        printf("Memory allocation failed :/\n");
    }
    else
    {
        printf("Memory allocation successful :D\n");
    }
}

void string_copy(char* word1, char* word2)
{
    int i = 0;

    while(word1[i] != '\0')
    {
        word2[i] = word1[i];
        i++;
    }    
    word2[i] = '\0';

    printf( "Original string : %s\n"
            "Copied string to allocated memory : %s\n",
            word1, word2);
}

/*
Exercise 41 — Dynamically Allocated Strings
Objective: Learn to allocate memory for strings based on their actual length.

Write a program that:
1. Asks the user to enter a string.
2. Determines the length of the string.
3. Allocates exactly enough memory to store the string, including its terminating '\0'.
4. Copies the original string into the allocated memory.
5. Displays the dynamically allocated string.
6. Frees the allocation.
Constraints:
- Don't allocate a fixed-size array for the final string.
- Use malloc().
- Handle allocation failure.
The input mechanism can use a temporary buffer.
*/