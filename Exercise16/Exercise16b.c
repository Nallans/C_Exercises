#include <stdio.h>

char* get_word(char* word);

int main(void)
{
    char word[] = "Hello";
    int size = 0;
    
    get_word(word);
    while(word[size] != '\0')
    {
        size++;
    }
    printf("Size = %d\n", size);

    return(0);
}

char* get_word(char* word)
{
    printf("Enter a word : ");
    scanf("%s", word);
    return(word);
}