#include <stdio.h>

void get_word(char* word);
int get_length(char* word);
void consonants_vowels(char* word, char* vowels);
void string_copy(char* word, char* word2);
void truncate_word(char* word);

int main(void)
{
    char word[30], word2[30];
    char vowels[] = {'a','e','i','o','u','y','A','E','I','O','U','Y','\0'};
    int length = 0;

    get_word(word);
    printf("Original word : %s\n", word);

    length = get_length(word);
    printf("Length : %d\n", length);

    consonants_vowels(word, vowels);
    string_copy(word, word2);
    printf("Copied word : %s\n", word2);

    truncate_word(word);
    printf("Truncated word : %s\n", word);

    return(0);
}

void get_word(char* word)
{
    printf("Word : ");
    scanf("%29s", word);
}

int get_length(char* word)
{
    int count = 0;

    while(word[count] != '\0')
    {
        count++;
    }
    return count;
}

void consonants_vowels(char* word, char* vowels)
{
    int count = 0, count2 = 0, count_vowels = 0, count_consonants = 0, add_vowel;

    while(word[count] != '\0')
    {
        add_vowel = 0;
        count2 = 0;
        while(vowels[count2] != '\0')
        {
            if(word[count] == vowels[count2])
            {
                count_vowels++;
                add_vowel++;
                break;
            }
            count2++;
        }
        if( add_vowel == 0 && ((word[count] > 64 && word[count] < 91) ||
            (word[count] > 96 && word[count] < 123)))
        {
            count_consonants++;
        }
        count++;
    }
    printf( "Vowels : %d\n"
            "Consonants : %d\n", count_vowels, count_consonants);
}

void string_copy(char* word, char* word2)
{
    int count = 0;

    while(word[count] != '\0')
    {
        word2[count] = word[count];
        count++;
    }
    word2[count] = '\0';
}

void truncate_word(char* word)
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
Exercise 30 — A small text processor

This is the capstone of the set.

Ask the user for a word and produce:

Original word: programming
Length: 11
Vowels: 3
Consonants: 8
Most frequent character: r
Reversed: gnimmargorp
Palindrome: No

You already have individual pieces for almost everything here.

Your challenge is to decide:

Which functions you want.
Which functions should return a value.
Which functions should modify the string.
Which information can be calculated in one traversal.
Which information requires another traversal.
What should be passed by pointer.
What should simply be returned.

Don't try to make one gigantic function. This is specifically an exercise in putting your accumulated knowledge together into a small, organized program.
*/