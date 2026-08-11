#include <stdio.h>

char* get_word(char* word);
int get_size(char* word, int size);
void reverse(char* word, int size);

int main(void)
{
    char word[30];
    int size = 0;

    get_word(word);
    size = get_size(word, size);
    reverse(word, size);

    printf("Reversed word : %s\n", word);

    return(0);
}

char* get_word(char* word)
{
    printf("Original word : ");
    scanf("%s", word);
    
    return(word);
}

int get_size(char* word, int size)
{
    while(word[size] != '\0')
    {
        size++;
    }
    return(size);
}

void reverse(char* word, int size)
{
    char buffer;
    int end = size - 1; // Getting the size without '\0' for accessing last index

    for(int i = 0; i < (size / 2); i++)
    {
        buffer = word[i];
        word[i] = word[end - i];
        word[end - i] = buffer;
    }
}

/*
Exercise 18 — Reverse a string

Ask the user for a word.

Reverse it in place.

Example:

Original: hello

Reversed: olleh

Do not create a second string.
*/