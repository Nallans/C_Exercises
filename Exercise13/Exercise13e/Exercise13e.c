#include <stdio.h>

void allocate(int* numbers);
void display(int* numbers);
void opposite(int* numbers);

int main(void)
{
    int numbers[8];

    allocate(numbers);
    display(numbers);
    printf("\n");
    opposite(numbers);

    return(0);
}

void allocate(int* numbers)
{
    printf("Please give me 8 numbers : ");
    for(int i = 0; i < 8; i++)
    {
        scanf("%d", &numbers[i]);
    }
}

void display(int* numbers)
{
    for(int i = 0; i < 8; i++)
    {
        printf("%d ", numbers[i]);
    }
}

void opposite(int* numbers)
{
    for(int i = 0; i < 4; i++)
    {
        printf("i = %d, Opposite = %d\n", numbers[i], numbers[7 - i]);
    }
}

/*
Exercise 13.5 — Half traversal

Create an array of 8 integers.

Write a loop that only visits the first half of the array.

For each visited index i, print:

i

the index at the opposite end.

Example:

i = 0, opposite = 7
i = 1, opposite = 6
i = 2, opposite = 5
i = 3, opposite = 4

Do not modify the array.

Focus: understanding how many swaps are actually needed.
*/