#include <stdio.h>

void get_word(char* word);
int get_length(char* word);
void compare_lengths(int length1, int length2, char* word1, char* word2);

int main(void)
{
    char word1[30], word2[30];
    int length1 = 0, length2 = 0;
    
    printf("First word : ");
    get_word(word1);
    printf("Second word : ");
    get_word(word2);
    
    printf( "The first word is : %s\n"
            "The second word is : %s\n",
            word1, word2);

    length1 = get_length(word1);
    length2 = get_length(word2);

    compare_lengths(length1, length2, word1, word2);

    return(0);
}

void get_word(char* word)
{
    scanf("%29s", word);
}

int get_length(char* word)
{
    int counter = 0;

    while(word[counter] != '\0')
    {
        counter++;
    }

    return counter;
}

void compare_lengths(int length1, int length2, char* word1, char* word2)
{
    if(length1 > length2)
    {
        printf("\"%s\" is longer.\n", word1);
    }
    else if(length2 > length1)
    {
        printf("\"%s\" is longer.\n", word2);
    }
    else
    {
        printf("The two words are the same size.\n");
    }
}

/*
Exercise 28 — Count words' lengths

Ask the user for two words.

Determine which one is longer.

Example:

First word: computer
Second word: cat

"computer" is longer.

Then handle the case where they're the same length.
*/