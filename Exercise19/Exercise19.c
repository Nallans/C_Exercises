#include <stdio.h>
#include <stdbool.h>

void get_word(char* word);
bool is_identical(char* word1, char* word2);

int main(void)
{
    char word1[30], word2[30];

    printf("First word : ");
    get_word(word1);
    printf("Second word : ");
    get_word(word2);
    
    if(is_identical(word1, word2))
    {
        printf("The strings are identical.\n");
    }
    else
    {
        printf("The strings are different.\n");
    }

    return(0);
}

void get_word(char* word)
{
    scanf("%29s", word);
}

bool is_identical(char* word1, char* word2)
{
    bool identical = true;
    int count = 0;

    while(word1[count] != '\0' || word2[count] != '\0')
    {
        if(word1[count] != word2[count])
        {
            identical = false;
        }
        count++;
    }   

    return identical;
}

/*
Exercise 19 — Compare two strings

Ask the user for two words.

Write a function that determines whether they are identical.

Example:

First: apple
Second: apple

The strings are identical.

and:

First: apple
Second: orange

The strings are different.

Do not use strcmp().
*/