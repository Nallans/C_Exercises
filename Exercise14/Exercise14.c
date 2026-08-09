#include <stdio.h>

void display(int* numbers);
void allocate(int* numbers);
void largests(int* numbers, int* num1, int* num2);

int main(void)
{
    int numbers[8];
    int num1 = 0, num2 = 0;

    allocate(numbers);

    printf("Numbers :\n");
    display(numbers);
    printf("\n");

    largests(numbers, &num1, &num2);
    printf( "Largest : %d\n"
            "Second largest : %d\n", num1, num2);

    return(0);
}

void display(int* numbers)
{
    for(int i = 0; i < 8; i++)
    {
        printf("%d ", numbers[i]);
    }
}

void allocate(int* numbers)
{
    printf("Please give me 8 integers : ");

    for(int i = 0; i < 8; i++)
    {
        scanf("%d", &numbers[i]);
    }
}

void largests(int* numbers, int* num1, int* num2)
{
    for(int i = 0; i < 8; i++)
    {
        if(numbers[i] > *num1)
        {
            *num2 = *num1;
            *num1 = numbers[i];
        }
        else if((numbers[i] < *num1) && (numbers[i] > *num2))
        {
            *num2 = numbers[i];
        }
    }
}

/*
Exercise 14 — Find the second largest number

Ask the user for 8 integers.

Display:

the largest number,

the second largest number.

Example:

Numbers:
12 5 8 20 7 19 4 15

Largest: 20
Second largest: 19

Try to solve it in one traversal of the array.
*/