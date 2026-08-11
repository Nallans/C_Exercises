#include <stdio.h>

char* get_word(char* word);
int count_vowels(char* word, int vowels);

int main(void)
{
    char word[30];
    int vowels = 0;

    get_word(word);
    vowels = count_vowels(word, vowels);
    printf("Vowels : %d\n", vowels);

    return(0);
}

char* get_word(char* word)
{
    printf("Enter a word : ");
    scanf("%s", word);

    return(word);
}

int count_vowels(char* word, int vowels)
{
    int i = 0;

    while(word[i] != '\0')
    {
        if( word[i] == 97 || word[i] == 101 || word[i] == 105 ||
            word[i] == 111 || word[i] == 117)
        {
            vowels++;
        }
        i++;
    }
    
    return vowels;
}

/*
Exercise 17 — Count vowels

Ask the user for a word.

Count how many vowels it contains (a, e, i, o, u).

Example:

Enter a word: education

Vowels: 5

Create a function that returns the count.
*/