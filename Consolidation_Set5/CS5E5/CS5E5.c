#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool allocate_array(int size, int** ppNumber);
void fill_array(int size, int** ppNumber);
void display_array(int size, int* pNumber);
void free_array(int** ppNumber);

int main(void)
{
    int size = 4;
    int* pNumber;
    int** ppNumber = &pNumber;
    
    if(allocate_array(size, ppNumber))
    {
        fill_array(size, ppNumber);
        display_array(size, pNumber);
        free_array(ppNumber);
        
        return(0);
    }
    else
    {
        return(1);
    }
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

void display_array(int size, int* pNumber)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", *(pNumber + i));
    }
}

void free_array(int** ppNumber)
{
    free(*ppNumber);
    *ppNumber = NULL;
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
Answer : The function returns false, then main() branches to the "else" statement and closes the program, returning 1 (as an error value).

2. What happens if you call free() on the pointer and then try to access the array?
Answer : The program doesn't let this happen because of its structure. But if it were to happen, it would create either random values or a segmentation fault.

3. What happens if you copy the pointer into another pointer variable before freeing the allocation?
Answer : Then we would have a copy of the same address stored in another pointer. We could access the values through it, however when freeing the allocation it would free the address, so the two pointers would become dangling pointers to a memory that is not allocated anymore, and be a safety risk (create segmentation faults).

4. After freeing the allocation, what should you do with the pointer variables that referred to it?
Answer : To properly free an allocation, we must then set the variables that referred to the address to NULL to remove any risk of segmentation fault. Because if we access the same variable after freeing but it was not replaced by the processor and still contains the old address, then you're calling something that possibly doesn't exist anymore and risk a segmentation fault.

Improvement challenge: Modify your design so that the cleanup function receives a pointer to the pointer and sets the caller's pointer to NULL after freeing it.
*/