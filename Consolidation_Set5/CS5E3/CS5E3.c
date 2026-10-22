#include <stdio.h>
#include <stdlib.h>

void allocate(int size, int** ppNumber);
void get_numbers(int size, int** ppNumber);
void display_numbers(int size, int* pNumber);

int main(void)
{
    int size = 5;
    int* pNumber;
    int** ppNumber = &pNumber;

    allocate(size, ppNumber);
    get_numbers(size, ppNumber);
    display_numbers(size, pNumber);
    printf("\n");

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
*/