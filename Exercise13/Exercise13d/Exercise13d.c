#include <stdio.h>

void display(int* numbers);
void pairs(int* numbers);

int main(void)
{
    int numbers[6] = {1, 2, 3, 4, 5, 6};

    display(numbers);

    printf("\n");

    pairs(numbers);

    return(0);
}

void display(int* numbers)
{
    for(int i = 0; i < 6; i++)
    {
        printf("%d ", numbers[i]);
    }
}

void pairs(int* numbers)
{
    for(int i = 0; i < 3; i++)
    {
        printf("%d and %d\n", numbers[i], numbers[5 - i]);
    }
}

/*
Exercise 13.4 — Mirror pairs

Create an array of 6 integers.

Print the following pairs:

0 and 5
1 and 4
2 and 3

For example:

Array:
1 2 3 4 5 6

Pairs:
1 and 6
2 and 5
3 and 4

Do not modify the array.

Focus: discovering the relationship between the left side and the right side of an array.
*/