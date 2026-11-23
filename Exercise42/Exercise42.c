#include <stdio.h>
#include <stdlib.h>

void get_string(char* string);
int count_string(char* string);

int main(void)
{
    char string[50];
    int size;
    // char* pString = string;
    // char** ppString = &pString;

    get_string(string);
    size = count_string(string);
    printf("Size of string : %d\n", size);

    return(0);
}

void get_string(char* string)
{
    printf("Give me a string of letters :\n");
    scanf("%49[^\n]", string);
    printf("%s\n", string);
}

int count_string(char* string)
{
    int count = 0;

    while(string[count] != '\0')
    {
        count++;
    }

    return count + 1; // Adding last space for terminating character
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