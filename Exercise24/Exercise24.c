#include <stdio.h>
#include <stdbool.h>

void get_word(char* word);
void get_char(char* letter);
bool is_present(char* word, char letter);
void rmchar(char* word, char letter);

int main(void)
{
    char word[30];
    char letter;

    get_word(word);
    get_char(&letter);

    if(is_present(word, letter))
    {
        rmchar(word, letter);
        printf("New word : %s\n", word);
    }
    else
    {
        printf("This letter is not present in this word.\n");
    }

    return(0);
}

void get_word(char* word)
{
    printf("Word : ");
    scanf("%29s", word);
}

void get_char(char* letter)
{
    printf("Remove letter : ");
    scanf(" %1c", letter); // Space before specifier for avoiding leading whitespace
}

bool is_present(char* word, char letter)
{
    bool presence = false;
    int count = 0; 
    while(word[count] != '\0')
    {
        if(word[count] == letter)
        {
            presence = true;
        }
        count++;
    }
    return(presence);
}

void rmchar(char* word, char letter)
{
    int count1 = 0, count2 = 0;

    while(word[count1] != '\0')
    {
        while(word[count1] == letter) // Using while instead of if to remove double or triple characters in a row
        {
            count2 = count1;

            while(word[count2] != '\0') // This loop shifts the whole array
            {
                word[count2] = word[count2 + 1];
                count2++;
            }
        }
        count1++;
    }
}

/*
Exercise 24 — Remove a character

Ask the user for:

a word,

a character to remove.

Remove all occurrences of that character from the string.

Example:

Word: banana
Remove: a


Result: bnn

Do it in place.

Focus: shifting characters inside the same array.
*/