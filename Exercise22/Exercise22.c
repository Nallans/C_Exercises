#include <stdio.h>

void get_word(char* word);
int get_length(char* word);
void concatenate(char* word1, char* word2, int length1, int length2);

int main(void)
{
    char word1[60], word2[30];
    int length1 = 0, length2 = 0;

    printf("First word : ");
    get_word(word1);
    length1 = get_length(word1);
    printf("Second word : ");
    get_word(word2);
    length2 = get_length(word2);
    concatenate(word1, word2, length1, length2);
    printf("Result : %s\n", word1);
    


    return(0);
}

void get_word(char* word)
{
    scanf("%29s", word);
}

int get_length(char* word)
{
    int count = 0;

    while(word[count] != '\0')
    {
        count++;
    }

    return(count);
}

void concatenate(char* word1, char* word2, int length1, int length2)
{
    int count1 = length1, count2 = 0;

    while(word1[count1] <= word1[length1 + length2])
    {
        word1[count1] = word2[count2];
        count1++;
        count2++;
    }
}

/*
Exercise 22 — Concatenate two strings

Ask the user for two words.

Create a function that appends the second word to the first.

Example:

First: hello
Second: world

Result: helloworld

Assume the first array is large enough to hold the result.

Do not use strcat().

Focus: finding the end of the first string and continuing from there.
*/