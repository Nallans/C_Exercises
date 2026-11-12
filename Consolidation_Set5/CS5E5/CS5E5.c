#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool allocate_array(int size, int** ppNumber);
void fill_array(int size, int** ppNumber);

int main(void)
{
    int size = 4;
    int* pNumber;
    int** ppNumber = &pNumber;
    
    allocate_array(size, ppNumber);
    fill_array(size, ppNumber);
    return(0);
}

bool allocate_array(int size, int** ppNumber)
{
    *ppNumber = malloc(size * sizeof(int));

    if(*ppNumber == NULL)
    {
        printf("Initial memory allocation failed :/\n");
        return false;
    }
    else
    {
        printf("Initial memory allocation successful :D\n");
        return true;
    }
}

void fill_array(int size, int** ppNumber)
{
    for(int i = 0; i < size; i++)
    {
        printf("What is number %d ? ", i + 1);
        scanf(" %d", (*ppNumber + i));
    }
}

/*
Exercise 5 — Memory Ownership
Objective: Understand how pointers and functions interact with the lifetime of allocated memory.

Write three functions:
- allocate_array() — allocates an integer array and returns its pointer.
- fill_array() — receives the pointer and fills the array.
- free_array() — releases the allocation.
In main(), coordinate the calls and ensure the allocation is freed exactly once.

Then consider these questions and explain your reasoning in comments or notes:
1. What happens if allocate_array() returns NULL?
2. What happens if you call free() on the pointer and then try to access the array?
3. What happens if you copy the pointer into another pointer variable before freeing the allocation?
4. After freeing the allocation, what should you do with the pointer variables that referred to it?
Improvement challenge: Modify your design so that the cleanup function receives a pointer to the pointer and sets the caller's pointer to NULL after freeing it.
*/