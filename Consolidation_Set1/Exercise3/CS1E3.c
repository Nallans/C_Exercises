#include <stdio.h>
#include <stdbool.h> 

void get_word(char* word);
void get_letter(char* letter);
bool first_occurrence(char* word, char letter, int* index);

int main(void)
{
    char word[30];
    char letter = 'a';
    int index = 0;

    get_word(word);
    get_letter(&letter);

    if(first_occurrence(word, letter, &index))
    {
        printf("First occurence : index %d\n", index);
    }
    else
    {
        printf("Sorry, the letter %c is not in this word :'(\n", letter);
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

bool first_occurrence(char* word, char letter, int* index)
{
    bool is_present = false;

    while(word[*index] != '\0')
    {
        if(word[*index] == letter)
        {
            return is_present = true;
        }
        (*index)++;
    }
    return(is_present);
}

/*
CS1E3 — Find the first occurrence

Ask for a word and a character.

Find the index of the first occurrence of that character.

Example:

Word: pineapple
Character: p

First occurrence: index 0

If it isn't present, report that.

Don't use a separate is_present() function unless you want to. Think about what your function could return instead.
*/