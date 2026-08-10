#include <stdio.h>

void get_word(char* word);
int length(char* word);

int main(void)
{
    char word[] = "";
    int size = 0;


    get_word(word);
    printf("%s\n", word);
    size = length(word);
    printf("Size = %d\n", size);

    return(0);
}

int length(char* word)
{
    int size = 0;

    while(word[size] != '\0')
    {
        size++;
    }
    return size;
}

void get_word(char* word)
{
    printf("Enter a word : ");
    scanf("%s", word);
}