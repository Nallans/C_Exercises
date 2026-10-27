#include <stdio.h>
#include <stdlib.h>

void allocate(int size, int** ppNumber);
void get_numbers(int size, int** ppNumber);

int main(void)
{
    int size = 4;
    int* pNumber;
    int** ppNumber = &pNumber;

    allocate(size, ppNumber);
    get_numbers(size, ppNumber);

    free(*ppNumber);
    *ppNumber = NULL;

    return(0);
}

void allocate(int size, int** ppNumber)
{
    *ppNumber = malloc(size * sizeof(int));

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
    printf("What are the numbers you want to store ?\n");

    for(int i = 0; i < size; i++)
    {
        scanf(" %d", (*ppNumber + i));

        if(*(*ppNumber + i) == -1)
        {
            printf("Exiting loop...\n");
            break;
        }
        
        printf("%d ", *(*ppNumber + i));
    }
}

/*
Exercise 4 — A Dynamic Array That Grows
Objective: Combine malloc() and realloc() into a small, practical data structure.

Build an integer collection that starts with capacity for 4 integers.

The program should:
1. Allocate the initial capacity.
2. Let the user enter integers one at a time.
3. When the collection becomes full, double its capacity using realloc().
4. Keep track of both the number of stored integers and the allocated capacity.
5. Display the collection when the user finishes.
6. Free the allocation.
The user should be able to stop entering numbers using a sentinel value, such as -1.

Important distinction: the number of elements stored is not the same as the allocated capacity.

Improvement challenge: Add a function that removes an element at a chosen index, shifts the remaining elements, and updates the number of stored elements without shrinking the allocation.
*/