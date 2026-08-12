#include <stdio.h>
#include <stdbool.h>

void get_word(char* word);
int get_length(char* word);
bool is_palindrome(char* word, int length);

int main(void)
{
    char word[30];
    int length = 0;

    get_word(word);
    length = get_length(word);

    if(is_palindrome(word, length))
    {
        printf("Palindrome : Yes\n");
    }
    else
    {
        printf("Palindrome : No\n");
    }

    return(0);
}

void get_word(char* word)
{
    printf("Enter a word : ");
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

bool is_palindrome(char* word, int length)
{
    bool palindrome = true;
    int count = 0, end = length - 1; // Creating end to access last index of array

    while(count < (length / 2))
    {
        if(word[count] != word[end - count])
        {
            palindrome = false;
        }
        count++;
    }
    return palindrome;
}

/*
Exercise 20 — Palindrome checker

A palindrome reads the same forward and backward.

Examples:

radar

level

madam

Write a function that checks whether a word is a palindrome.

Example:

Enter a word: radar

Palindrome: yes

Example:

Enter a word: hello

Palindrome: no

Do not reverse the string into a second array.

Try to solve it by comparing characters from both ends.
*/