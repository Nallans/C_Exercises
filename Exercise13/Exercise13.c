#include <stdio.h>

int main(void)
{
    int numbers[6];
    int buffer;

    printf("Give me 6 integers please : ");

    for(int i = 0; i < 6; i++)
    {
        scanf("%d", &numbers[i]);
        //printf("%d\n", numbers[i]);
    }

    for(int i = 0; i < 6; i++)
    {
        buffer = (numbers + i);
        *(numbers + i) = *(numbers + (5 - i));
        *(numbers + (5 - i)) = buffer;
    }

    return(0);
}

/*
Exercise 13 — Reverse an array

Ask the user for 6 integers.

Display:

the original array,

the reversed array.

Example:

Original:
1 2 3 4 5 6

Reversed:
6 5 4 3 2 1

Do not create a second array.

Reverse the array in place.

Use a function.
*/