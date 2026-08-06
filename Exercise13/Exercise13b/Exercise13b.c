#include <stdio.h>

void display(int* numbers);
void swap(int* numbers, int target1, int target2);

int main(void)
{
    int numbers[5] ={1,2,3,4,5};
    int target1, target2;

    display(numbers);
    printf( "\n"
            "Please give me two numbers you want to swap "
            "(between 1 and 5) : ");
    scanf("%d %d", &target1, &target2);

    swap(numbers, target1, target2);

    printf("\n");
    display(numbers);
    printf("\n");


    return(0);
}

void display(int* numbers)
{
    for(int i = 0; i < 5; i++)
    {
        printf("%d ", numbers[i]);
    }
}

void swap(int* numbers, int target1, int target2)
{
    int buffer;

    buffer = numbers[target1 - 1];
    numbers[target1 - 1] = numbers[target2 - 1];
    numbers[target2 - 1] = buffer;
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

One tiny improvement challenge (the only one): modify swap() so that it receives the two indices to swap. That will naturally prepare you for 13c.
*/