#include <stdio.h>
#include <stdlib.h>

void get_size(int* size);

int main(void)
{
    int size;

    get_size(&size);
    printf("So you want to store %d integers\n", size);

    return(0);
}

void get_size(int* size)
{
    printf("How many integers do you want to store ? ");
    scanf(" %d", size);
    
    while(*size <= 0)
    {
        printf("You must enter a positive integer\n");
        scanf(" %d", size);
    }
}

/*
Exercise 1 — Allocation Lifecycle
Objective: Understand the full lifetime of a dynamically allocated array.

Write a program that:
1. Asks the user for the number of integers to store.
2. Allocates an array of that size using malloc().
3. Checks whether the allocation succeeded.
4. Fills the array with user-provided integers.
5. Displays the values.
6. Releases the allocated memory with free().
Rules:
- No variable-length arrays.
- Use a pointer to access the allocated memory.
- Keep allocation, input, display, and cleanup in separate functions where appropriate.
- Validate that the requested size is positive.
Improvement challenge: After displaying the values, set every element to zero using pointer arithmetic, then display the array again before freeing it.
*/