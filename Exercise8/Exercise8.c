#include <stdio.h>

int main(void)
{
    int num, product, limit;

    printf( "Hello !\n"
            "Can you give me a positive integer please ? :)\n"
            "Give me also the limit of the table in this format : x x\n");
    scanf("%d %d", &num, &limit);

    for(int i = 1; i <= limit; i++)
    {
        product = num * i;
        printf("%d x %d = %d\n", num, i, product);
    }

    return(0);
}

/*
Exercise 8 — Multiplication Table

Ask the user for an integer and display its multiplication table from 1 to 10.

Example:

Enter a number: 7

7 x 1 = 7
7 x 2 = 14
7 x 3 = 21
...
7 x 10 = 70

Use a for loop.

One improvement challenge

Allow the user to choose how far the table goes.

Example:

Enter a number: 7
Up to: 15

Then print the table from 1 to 15.
*/