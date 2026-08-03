#include <stdio.h>

int main(void)
{
    int* reverse_array(int* numbers);
    int numbers[6] = {};

    printf("Give me 6 integers please : ");

    for(int i = 0; i < 6; i++)
    {
        scanf("%d", &numbers[i]);
    }

    int* numbers = reverse_array(numbers);

    printf("%d\n", numbers[0]);
    printf("%d\n", numbers[5]);

    return(0);
}

int* reverse_array(int* numbers)
{
    //int buffer;

    /*for(int i = 0; i < 6; i++)
    {
        buffer = numbers[i];
        numbers[i] = numbers[(5-i)];
        numbers[-(i+1)] = buffer;
    }*/

    return numbers;
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