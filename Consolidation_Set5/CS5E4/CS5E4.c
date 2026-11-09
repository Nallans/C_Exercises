#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void allocate(int size, int** ppNumber);
int get_numbers(int* size, int** ppNumber);
void display_stats(int numbers, int size, int* pNumber);
void reallocate(int size, int** ppNumber);
void remove_number(int* numbers, int** ppNumber);

int main(void)
{
    int size = 4;
    int numbers;
    int* pNumber;
    int** ppNumber = &pNumber;

    allocate(size, ppNumber);
    numbers = get_numbers(&size, ppNumber);
    display_stats(numbers, size, pNumber);
    remove_number(&numbers, ppNumber);
    display_stats(numbers, size, pNumber);
    // size = 8;
    // reallocate(size, ppNumber);
    // display_stats(numbers, size, pNumber);

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

int get_numbers(int* size, int** ppNumber)
{
    bool end = false;
    int i = 0;

    while(end == false)
    {
        printf("What is number %d ? ", i + 1);
        scanf(" %d", (*ppNumber + i));
        if(i == 4 || i == 8 || i == 16 || i == 32)
        {
            *size *= 2;
            reallocate(*size, ppNumber);
        }

        if(*(*ppNumber + i) == -1)
        {
            *(*ppNumber + i) = 0;
            printf("Exiting loop...\n");
            end = true;
            break;
        }
        i++;
    }
    return i;
}

void display_stats(int numbers, int size, int* pNumber)
{
    for(int i = 0; i < numbers; i++)
    {
        printf("%d ", *(pNumber + i));
    }
    printf("\n");
    printf("Size of the array : %d integers\n", size);
}

void reallocate(int size, int** ppNumber)
{
    int* temp = realloc(*ppNumber, size * sizeof(int));

    if(temp == NULL)
    {
        printf("Memory reallocation failed :/\n");
    }
    else
    {
        printf("Memory reallocation successful :D\n");
        *ppNumber = temp;
        temp = NULL;
    }
}

void remove_number(int* numbers, int** ppNumber)
{
    int temp, index;

    printf("Which number do you want to remove ? ");
    scanf(" %d", &index);
    index--;

    for(int i = index; i < *numbers; i++) 
    {
        if((i + 1) >= *numbers)
        {
            break;
        }
        else
        {
            temp = *(*ppNumber + (i + 1));
            *(*ppNumber + i) = temp;
        }
    }
    *(*ppNumber + (*numbers - 1)) = 0;
    *numbers -= 1;
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

Improvement challenge 2 : 
Your removal implementation is on the right track. I have just one additional requirement:

After removing an element, make sure the last previously occupied slot is no longer treated as part of the array.

You already decrease numbers. Think about whether you need to do anything else to the memory contents, or whether changing the logical count is sufficient.
*/