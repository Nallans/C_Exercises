#include <stdio.h>
#include <stdlib.h>

void get_string(char* sentence);
int count_string(char* sentence);
void allocate(int size, char** ppNewSentence);

int main(void)
{
    char sentence[50];
    char* pNewSentence;
    char** ppNewSentence = &pNewSentence;
    int size;

    get_string(sentence);
    size = count_string(sentence);
    printf( "%s\n"
            "Length = %d\n", 
            sentence, size);
    allocate(size, ppNewSentence);

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