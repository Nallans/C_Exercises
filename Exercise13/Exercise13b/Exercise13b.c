#include <stdio.h>

int main(void)
{
    int numbers[5] ={1,2,3,4,5};
    void display(int* numbers);
    void swap(int* numbers);

    display(numbers);

    swap(numbers);

    printf("\n");
    display(numbers);
    printf("\n");


    return(0);
}

void display(int* numbers)
{
    for(int i = 0; i < 5; i++)
    {
        printf("%d", numbers[i]);
    }
}

void swap(int* numbers)
{
    int buffer;

    buffer = numbers[0];
    numbers[0] = numbers[4];
    numbers[4] = buffer;
}
/*
Exercise 13.2 — Swap two elements in an array

Create an array of 5 integers.

Write a function that swaps:

element 0

element 4

Example:

Before:
1 2 3 4 5

After:
5 2 3 4 1

Focus: accessing array elements through indices.
*/