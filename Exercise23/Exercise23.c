#include <stdio.h>

void get_word(char* word);
void convert(char* word);

int main(void)
{
    char word[30];

    get_word(word);

    convert(word);
    printf("Uppercase word : %s\n", word);

    return(0);
}

void get_word(char* word)
{
    printf("Original word : ");
    scanf("%29s", word);
}

void convert(char* word)
{
    int count = 0;

    while(word[count] != '\0')
    {
        if(word[count] > 96 && word[count] < 123)
        {
            word[count] -= 32;
        }
        
        count++;
    }
}

/*
Exercise 23 — Convert to uppercase

Ask the user for a word.

Convert all lowercase letters to uppercase.

Example:

Original: HeLlo


Uppercase: HELLO

Do it in place.

Do not use any library conversion function.

Focus: character manipulation.
*/