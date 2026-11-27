#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char* create_string(void);
int count_string(char* word);
void allocate(int size, char** ppString);
void string_copy(char* word1, char* word2);

int main(void)
{
    create_string();

    return(0); 
}

char* create_string(void)
{
    char string[50];
    char* pString = string;
    char** ppString = &pString;
    int size;

    printf("Give a string : ");
    scanf(" %49[^\n]", string);
    printf("Your string is \"%s\"\n", string);
    size = count_string(string);    
    printf("The size of your string is %d\n", size);
    allocate(size, ppString);

    return pString;
}

int count_string(char* word)
{
    int count = 0;

    while(word[count] != '\0')
    {
        count++;
    }
    
    return count + 1;
}

void allocate(int size, char** ppString)
{
    *ppString = (char*)malloc(size * sizeof(char));

    if(*ppString == NULL)
    {
        printf("Memory allocation failed :/\n");
    }
    else
    {
        printf("Memory allocation successful ! :D\n");
    }
}

void string_copy(char* word1, char* word2)
{
    int count = 0;

    while(word1[count] != '\0')
    {
        word2[count] = word1[count];
        count++;
    }

    word2[count] = '\0';
}

/*
Exercise 42 — Returning Dynamically Allocated Memory
Objective: Understand how functions can create and transfer ownership of dynamically allocated memory.

Write a function:
char* create_string(void);


The function should:
1. Ask the user for a string.
2. Allocate enough memory for it.
3. Store the string in the allocation.
4. Return the pointer.
In main():
1. Call create_string().
2. Receive the returned pointer.
3. Display the string.
4. Free the allocation.
Important: The allocated memory must remain valid after create_string() finishes executing.

Think carefully about the difference between a local pointer variable and the memory it points to.
*/