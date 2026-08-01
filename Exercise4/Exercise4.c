#include <stdio.h>

int main(void)
{
    void maxmin(int num1, int num2, int num3);

    int num1 = 0,
        num2 = 0,
        num3 = 0;

    char greetings[] = "Hello !\n"
                       "Can you give me three integers please ?\n"
                       "I'll do some magic with'em ;D\n";

    printf("%s", greetings);
    scanf("%d %d %d", &num1, &num2, &num3);

    printf("Operations with the first two numbers %d and %d :\n", num1, num2);
    printf("Sum : %d\n", num1 + num2);
    printf("Difference : %d\n", num1 - num2);
    printf("Product : %d\n", num1 * num2);

    if (num2 != 0)
    {
        printf("Quotient : %.3f\n", (float)num1 / (float)num2);
    }
    else 
        printf("Woops, can't do that !\n");

    maxmin(num1, num2, num3);

    return (0);
}

void maxmin(int num1, int num2, int num3)
{
    if(num1 > num2)
    {
        if(num1 > num3)
        {
            printf("Largest number : %d\n", num1);

            if(num2 > num3)
            {
                printf("Smallest number : %d\n", num3);
            }
            else
                printf("Smallest number : %d\n", num2);
        }
        else
            printf( "Largest number : %d\n"
                    "Smallest number : %d\n",
                num3, num2);
    }
    else if(num2 > num3)
    {
        printf("Largest number : %d\n", num2);

        if(num1 > num3)
        {
            printf("Smallest number : %d\n", num3);
        }
        else
            printf("Smallest number : %d\n", num1);
    }
    else
        printf( "Largest number : %d\n"
                "Smallest number : %d\n",
                num3, num1);
}

/*
Exercise 4 – Basic Arithmetic
Goal

Perform calculations.

Task

Ask the user for two integers.

Print:

their sum
their difference
their product
their quotient

Example:

First number: 12
Second number: 4

Sum: 16
Difference: 8
Product: 48
Quotient: 3

Bonus

What happens if the second number is 0? Prevent your program from crashing by checking before dividing.

Small challenge 4

Ask the user for three integers and display:

the largest number
the smallest number

Example:

Numbers: 12 4 9

Largest: 12
Smallest: 4

Try to solve it with if statements only.
*/