#include <stdio.h>
#include <stdlib.h>

void get_string(char** pString);

int main(void)
{
    char* string[50];
    char** pString = &string;

    get_string(pString);

    return(0);
}

void get_string(char** pString)
{
    printf("Give me a string of letters :\n");
    scanf("%49[^\n]", *pString);
    printf("%s\n", *pString);
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