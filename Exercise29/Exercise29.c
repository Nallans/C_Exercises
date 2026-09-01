#include <stdio.h>

void get_word(char* word);
int compare_words(char* word1, char* word2);
void results(char* word1, char* word2, int compare);

int main(void)
{
    char word1[30], word2[30];
    int compare = 0;

    printf("Word 1 : ");
    get_word(word1);
    printf("Word 2 : ");
    get_word(word2);

    compare = compare_words(word1, word2);
    results(word1, word2, compare);

    return(0);
}

void get_word(char* word)
{
    scanf("%29s", word);
}

int compare_words(char* word1, char* word2)
{
    int count = 0, compare = 0;

    while(word1[count] != '\0' || word2[count] != '\0')
    {
        if( word1[count] < word2[count])
        {
            compare = -1;
            return compare;
        }
        else if(word1[count] > word2[count])
        {
            compare = 1;
            return compare;
        }
        count++;
    }
    return compare;
}

void results(char* word1, char* word2, int compare)
{
    if(compare == -1)
    {
        printf("%s / %s => %d\n", word1, word2, compare);
    }
    else if(compare == 1)
    {
        printf("%s / %s => %d\n", word2, word1, compare);
    }
    else
    {
        printf("%s / %s => %d\n", word1, word2, compare);
    }
}

/*
Exercise 29 — Manual string comparison

You already did a version of this in CS1E5, so this time we're making it more interesting.

Write:

int compare_words(char* word1, char* word2);

Return:

-1 if word1 comes before word2
0 if they are identical
1 if word1 comes after word2

And this time, do not use strcmp().

Examples:

apple / banana → -1
banana / apple → 1
hello / hello → 0

Remember our previous discussion: "before" and "after" here mean lexicographical order, character by character—not length.
*/