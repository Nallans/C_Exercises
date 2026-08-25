#include <stdio.h>

void get_word(char* word);
int compare_words(char* word1, char* word2);

int main(void)
{
    char word1[30], word2[30];
    int result = 0;

    printf("Word 1 : ");
    get_word(word1);
    printf("Word2 : ");
    get_word(word2);

    printf("Word 1 is %s, word 2 is %s\n", word1, word2);

    result = compare_words(word1, word2);
    printf("Result : %d\n", result);

    return(0);
}

void get_word(char* word)
{
    scanf("%29s", word);
}

int compare_words(char* word1, char* word2)
{
    int count = 0;

    while(word1[count] == word2[count])
    {
        printf(" %c %c |",word1[count], word2[count]);
        count++;
    }
    if(word1[count] < word2[count])
    {
        return(-1);
    }
    else if(word1[count] > word2[count])
    {
        return(1);
    }
    else return(0);
}

/*
Exercise 29 — Manual string comparison

You've already made is_identical().

Now make a function that returns:

-1 if word 1 comes before word 2,
0 if they're identical,
1 if word 1 comes after word 2.

For example:

apple
banana

Result: -1

Don't worry about making it identical to strcmp() yet. Just establish your own comparison logic.
Comes before / after => In a dictionnary (lexographical order)
*/