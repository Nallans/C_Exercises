#include <stdio.h>

void get_word(char* word);
void remove_duplicates(char* word);

int main(void)
{
    char word[30];

    get_word(word);
    remove_duplicates(word);
    printf("Output : %s\n", word);


    return(0);
}

void get_word(char* word)
{
    printf("Input : ");
    scanf("%29s", word);
}

void remove_duplicates(char* word)
{
    int count1 = 0, count2 = 0, count3 = 0;

    while(word[count1] != '\0')
    {
        count2 = count1 + 1;
        while(word[count2] != '\0')
        {
            while(word[count2] == word[count1])
            {
                count3 = count2;
                while(word[count3] != '\0')
                {
                    word[count3] = word[count3 + 1];
                    count3++;
                }
            }
            count2++;
        }
        count1++;
    }
}

/*
Exercise 26 — Remove duplicate characters

Write a program that receives a word and removes all duplicate occurrences, keeping only the first occurrence of each character.

Example:

Input:  programming
Output: progamin

Another example:

Input:  banana
Output: ban

You already have essentially all the tools necessary for this one.

Constraint: Modify the original string directly. Don't create a second string.
*/