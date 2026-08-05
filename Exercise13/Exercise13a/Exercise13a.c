#include <stdio.h>

int main(void)
{
    void swap(int* num1, int* num2);
    int num1 = 3, num2 = 5;

    printf("%d, %d\n", num1, num2);

    swap(&num1, &num2);

    printf("%d, %d\n", num1, num2);

    return(0);
}

void swap(int* num1, int* num2)
{
    int buffer;

    buffer = *num1;
    *num1 = *num2;
    *num2 = buffer;
}

/*
Exercise 13.1 — Swap two variables

Write a function that exchanges the values of two integers.

Example:

Before: a = 3, b = 7
After:  a = 7, b = 3

The function must actually modify the original variables.

Focus: values vs memory locations.
*/