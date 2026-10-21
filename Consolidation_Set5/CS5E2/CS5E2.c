#include <stdio.h>
#include <stdlib.h>

void allocate(int size, int** ppNumber);
void get_numbers(int size, int** ppNumber);
void get_size(int* size);
void reallocate(int size, int** ppNumber);

int main(void)
{
    int size = 5;
    int* pNumber;
    int** ppNumber = &pNumber;

    allocate(size, ppNumber);
    get_numbers(size, ppNumber);
    printf("\n");
    get_size(&size);
    printf("So you want to store %d numbers\n", size);
    printf("\n");
    reallocate(size, ppNumber);

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
        printf("Memory allocation successful !\n");
    }
}

void get_numbers(int size, int** ppNumber)
{
    printf("What are the %d numbers you want to store ?\n", size);

    for(int i = 0; i < size; i++)
    {
        scanf(" %d", (*ppNumber + i));
        printf("%d ", *(*ppNumber + i));
    }
}

void get_size(int* size)
{
    printf("What is the new size of array you want ? ");
    scanf(" %d", size);
    while(*size < 6)
    {
        printf("You must enter a size greater than 5 : ");
        scanf(" %d", size);
    }
}

void reallocate(int size, int** ppNumber)
{
    *ppNumber = (int*)realloc(*ppNumber, size * sizeof(int));
    if(ppNumber == NULL)
    {
        printf("Reallocation failed :/\n");
    }
    else
    {
        printf("Reallocation successful\n");
    }
}

/*
Exercise 2 — Resizing an Allocation
Objective: Understand what realloc() actually changes.

Start with an array of 5 integers.
1. Allocate space for 5 integers.
2. Fill the array with five values.
3. Ask the user for a new size greater than 5.
4. Resize the allocation using realloc().
5. Fill only the newly added elements.
6. Display the entire array.
7. Free the allocation.
Pay attention to which values must be preserved after resizing.

Improvement challenge: Make the new size user-defined, allowing either growth or shrinkage, while preserving all elements that still fit in the resized array.
*/