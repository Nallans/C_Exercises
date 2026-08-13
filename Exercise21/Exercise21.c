#include <stdio.h>

void get_word(char* word);
int get_length(char* word);
void copy_word(char* word1, char* word2, int length);

int main(void)
{
    char word1[30], word2[30];
    int length = 0;

    get_word(word1);
    length = get_length(word1);
    copy_word(word1, word2, length);
    printf( "Copied word : %s\n", word2);

    return(0);
}

void get_word(char* word)
{
    printf("Source word : ");
    scanf("%29s", word);
}

int get_length(char* word)
{
    int counter = 0;

    while(word[counter] != '\0')
    {
        counter++;
    }

    return(counter);
}

void copy_word(char* word1, char* word2, int length)
{
    int counter = 0;

    while(counter < length)
    {
        word2[counter] = word1[counter];
        counter++;
    }
}

/*
Exercise 21 — Copy a string

Write a function that copies one string into another.

Example:

Source: programming

Copy: programming

Create a second character array and copy the contents manually.

Do not use strcpy().

Focus: traversing one string while writing into another.
*/