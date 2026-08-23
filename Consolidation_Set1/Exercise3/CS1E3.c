#include <stdio.h>

void get_word(char* word);
void get_letter(char* letter);
int first_occurence(char* word, char letter);

int main(void)
{
    char word[30];
    char letter = 'a';
    int count = 0;

    get_word(word);
    get_letter(&letter);

    count = first_occurence(word, letter);
    
    if(count == 0)
    {
        printf("Sorry, the letter %c is not in this word :'(\n", letter);
    }
    else
    {
        printf("First occurence : index %d\n", count);
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

int first_occurence(char* word, char letter)
{
    int count = 0;

    while(word[count] != '\0')
    {
        if(word[count] == letter)
        {
            return count;
            break;
        }
        count++;
    }
    return(0);
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