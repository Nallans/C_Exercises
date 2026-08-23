#include <stdio.h>

void get_word(char* word);
void get_letter(char* letter);
int count_letter(char* word, char letter);

int main(void)
{
    char word[30];
    char letter = 'a';
    int counter = 0;

    get_word(word);
    get_letter(&letter);
    counter = count_letter(word, letter);
    
    if(counter == 0)
    {
        printf("The letter %c is not in this word, sorry :'(\n", letter);
    }
    else
    {
        printf("The letter %c appears %d times !\n", letter, counter);
    }


    return(0);
}

void get_word(char* word)
{
    printf("Word : ");
    scanf("%29s", word);
}

void get_letter(char* letter)
{
    printf("Letter : ");
    scanf(" %c", letter);
}

int count_letter(char* word, char letter)
{
    int counter = 0, letter_counter = 0;

    while(word[counter] != '\0')
    {
        if(word[counter] == letter)
        {
            letter_counter ++;
        }
        counter++;
    }

    return letter_counter;
}

/*
CS1E1 — Character counter

Write a program that:

asks for a word,
asks for a character,
counts how many times that character appears,
prints the result.

Example:

Word: banana
Character: a
'a' appears 3 times.
*/