#include <stdio.h>

void get_word(char* word);
void remove_vowels(char* word);

int main(void)
{
    char word[30];

    get_word(word);
    remove_vowels(word);
    printf("New word : %s\n", word);

    return(0);
}

void get_word(char* word)
{
    printf("Original word : ");
    scanf("%29s", word);
}

void remove_vowels(char* word)
{
    int count = 0, count2 = 0;

    while(word[count] != '\0')
    {
        while(word[count] == 'a' || word[count] == 'e' || word[count] == 'i' ||
        word[count] == 'o' || word[count] == 'u' || word[count] == 'y' ||
        word[count] == 'A' || word[count] == 'E' || word[count] == 'I' ||
        word[count] == 'O' || word[count] == 'U' || word[count] == 'Y')
        {
            count2 = count;
            while(word[count2] != '\0')
            {
                word[count2] = word[count2 + 1];
                count2++;
            }
        }
        count++;
    }
}

/*
CS1E2 — Remove all vowels

Ask the user for a word and remove every vowel from it.

Example:

Original: programming
Result: prgrmmng

Do it in-place.
*/