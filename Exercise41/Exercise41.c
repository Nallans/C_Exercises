#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool get_string(char* sentence);
int count_string(char* sentence);
bool allocate(int size, char** ppNewSentence);
void string_copy(char* word1, char* word2);
void display_string(char* pNewSentence);

int main(void)
{
    char sentence[50];
    char* pNewSentence;
    char** ppNewSentence = &pNewSentence;
    int size;

    if(get_string(sentence))
    {

        size = count_string(sentence);
        printf( "Length = %d characters\n", 
                size);

        if(allocate(size, ppNewSentence))
        {
            string_copy(sentence, pNewSentence);
            display_string(pNewSentence);

            free(pNewSentence);
            pNewSentence = NULL;

            return(0);
        }

        else
        {
            free(pNewSentence);
            pNewSentence = NULL;

            return(1);
        }
    }
    else
    {
        printf("Sorry, letters only ! Try again !\n");
        return(1);
    }
}

bool get_string(char* sentence)
{
    int i = 0;
    bool is_correct = true;

    printf("Give a word or sentence please\n");
    scanf(" %49[^\n]", sentence);

    while(sentence[i] != '\0')
    {
        if( (sentence[i] > 64 && sentence[i] < 91) ||
            (sentence[i] > 96 && sentence[i] < 123) ||
            (sentence[i] == 32))
        {
            i++;
        }
        else
        {
            is_correct = false;
            return is_correct;
        }
    }
    
        return is_correct;
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

bool allocate(int size, char** ppNewSentence)
{
    *ppNewSentence = malloc(size * sizeof(char));

    if(*ppNewSentence == NULL)
    {
        printf("Memory allocation failed :/\n");
        return false;
    }

    else
    {
        printf("Memory allocation successful :D\n");
        return true;
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

    word2[i] = '\0'; // Adding terminating character to end properly
}

void display_string(char* pNewSentence)
{
    printf( "Sentence in newly allocated memory : %s\n",
            pNewSentence);
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

Improvement challenge — Exercise 41
Your current program works with strings up to the capacity of your temporary buffer.

Now, make get_string() report whether it successfully received input, and have main() handle that result before attempting to count or allocate the string.

The goal is to practise handling input failure separately from memory-allocation failure.
*/