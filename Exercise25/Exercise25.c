#include <stdio.h>

void get_word(char* word);
void frequency(char* word);

int main(void)
{
    char word[30];

    get_word(word);
    frequency(word);

    return(0);
}

void get_word(char* word)
{
    printf("Word : ");
    scanf("%29s", word);
    printf("\n");
}

void frequency(char* word)
{
    int count1 = 0, count2 = 0, count3 = 0, letter_count = 1;

    while(word[count1] != '\0')
    {
        letter_count = 1;
        count2 = count1 + 1;
        while(word[count2] != '\0')
        {
            while(word[count2] == word[count1])
            {
                letter_count++;
                count3 = count2;
                while(word[count3] != '\0')
                {
                    word[count3] = word[count3 + 1];
                    count3++;
                }
            }
            count2++;
        }
        printf("%c : %d\n", word[count1], letter_count);
        count1++;
    }
}

/*
Exercise 25 — Character frequency

Ask the user for a word.

Display how many times each letter appears.

For example:

Word: programming


p: 1
r: 2
o: 1
g: 2
a: 1
m: 2
i: 1
n: 1

You may assume lowercase letters for now.

This is the first exercise in this set that will require nested loops or another counting strategy.

Focus: combining traversal with comparison.
*/