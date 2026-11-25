#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char* create_string(void);

int main(void)
{
    create_string();

    return(0); 
}

char* create_string(void)
{
    char string[50];
    char* pString = string;

    printf("Give a string : ");
    scanf(" %49[^\n]", string);
    printf("Your string is \"%s\"\n", string);

    return pString;
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