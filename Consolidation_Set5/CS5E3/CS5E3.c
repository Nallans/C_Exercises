#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void allocate(int size, int** ppNumber);
void get_numbers(int size, int** ppNumber);
void display_numbers(int size, int* pNumber);
void get_size(int* size);
bool reallocate(int size, int** ppNumber);

int main(void)
{
    int size = 5;
    int* pNumber;
    int** ppNumber = &pNumber;

    allocate(size, ppNumber);
    get_numbers(size, ppNumber);
    display_numbers(size, pNumber);
    printf("\n");
    get_size(&size);
    if(reallocate(size, ppNumber))
    {
        display_numbers(size, pNumber);
        printf("\n");
    }
    else
    {
        display_numbers(5, pNumber);
        printf("\n");
    }

    free(*ppNumber);
    *ppNumber = NULL;

    return(0);
}

void allocate(int size, int** ppNumber)
{
    *ppNumber = (int*)malloc(size * sizeof(int));

    if(*ppNumber == NULL)
    {
        printf("Memory allocation failed :/\n");
    }
    else
    {
        printf("Memory allocation successful :D\n");
    }
}

void get_numbers(int size, int** ppNumber)
{
    printf("What are the %d numbers you want to store ?\n", size);

    for(int i = 0; i < size; i++)
    {
        scanf(" %d", (*ppNumber + i));
    }
}

void display_numbers(int size, int* pNumber)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", *(pNumber + i));
    }
}

void get_size(int* size)
{
    printf("What is the new size of the array ? ");
    scanf(" %d", size);

    while(*size < 1)
    {
        printf("Choose a size greater than 0 : ");
        scanf(" %d", size);
    }
}

bool reallocate(int size, int** ppNumber)
{
    int* temp = realloc(*ppNumber, size * sizeof(int));
    
    if(temp == NULL)
    {
        printf("Reallocation failed :/\n");
        return false;
    }
    else
    {
        printf("Reallocation successful ! :D\n");
        *ppNumber = temp;
        temp = NULL;
        return true;
    }
}

/*
Exercise 3 — Safe Reallocation
Objective: Handle allocation failure without losing access to the original allocation.

Write a program that allocates an array of 5 integers and then attempts to resize it.

Your program must:
- Preserve access to the original allocation if resizing fails.
- Update the main pointer only after a successful resize.
- Free the memory correctly when finished.
You don't need to force an allocation failure. The purpose is to write the code so that it handles one correctly if it occurs.

Improvement challenge: Put the resizing logic into a function and decide what that function should return to communicate success or failure.

Improvement challenge 2 : 

Imagine the allocation fails when you request a larger array. What happens if main() then calls display_numbers(size, pNumber) using the newly requested size?

Modify main() so that it handles the return value correctly and never accesses elements beyond the allocation if reallocation fails. No need to rewrite the rest of your program.
*/