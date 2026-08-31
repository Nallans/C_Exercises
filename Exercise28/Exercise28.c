#include <stdio.h>

void get_word(char* word);
void count_occurrences(char* word, int* occurrences);
void most_frequent(char* word, int* occurrences);

int main(void)
{
    char word[30];
    int occurrences[30];

    get_word(word);
    count_occurrences(word, occurrences);
    most_frequent(word, occurrences);

    return(0);
}

void get_word(char* word)
{
    printf("Input : ");
    scanf("%29s", word);
}

void count_occurrences(char* word, int* occurrences)
{
    int count1 = 0, count2 = 0, count3 = 0, letter_count;

    while(word[count1] != '\0')
    {
        count2 = count1 + 1;
        letter_count = 1;
        while(word[count2] != '\0')
        {
            while(  word[count2] == word[count1] ||
                    word[count2] == word[count1] - 32 ||
                    word[count2] == word[count1] + 32)
            {
                count3 = count2;
                letter_count++;
                while(word[count3] != '\0')
                {
                    word[count3] = word[count3 + 1];
                    count3++;
                }
            }
            count2++;
        }
        occurrences[count1] = letter_count;
        count1++;
    }
}

void most_frequent(char* word, int* occurrences)
{
    int count1 = 0, index = 0, letter_count = 0;

    while(word[count1] != '\0')
    {
        if(occurrences[count1] > letter_count)
        {
            index = count1;
            letter_count = occurrences[count1];
        }
        count1++;
    }

    printf( "Most frequent character : %c\n"
            "Occurrences : %d\n",
            word[index], occurrences[index]);
}

/*
Exercise 28 — Find the most frequent character

Given a word, determine which character appears the most often.

Example:

Input:  banana

Most frequent character: a
Occurrences: 3

If there is a tie, you may decide what your program does. Document your choice in a comment.

For example, you could keep the first character that reaches the highest frequency.
*/