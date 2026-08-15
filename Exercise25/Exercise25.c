#include <stdio.h>

void get_word(char* word);

int main(void)
{
    char word[30];

    get_word(word);
    printf("Given word : %s\n", word);

    return(0);
}

void get_word(char* word)
{
    printf("Word : ");
    scanf("%s", word);
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