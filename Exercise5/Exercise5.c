#include <stdio.h>

int main(void)
{
    void even_or_odd(int number);
    int number;

    printf( "EVEN OR ODD\n"
            "Hello !\n"
            "Give me an integer and I'll tell you if it is even or odd :\n");
    
    scanf("%d", &number);

    even_or_odd(number);

    return(0);
}

void even_or_odd(int number)
{
    if(number == 0)
    {
        printf("Well, that's a 0 right there !\n");
    }
    else if (number % 2 == 0)
    {
        printf("The number %d is even.\n", number);
        
        if(number > 0)
        {
            printf("Also, the number is positive.\n");
        }
        else
            printf("Also, the number is negative.\n");
    }
    else
    {
        printf("The number %d is odd.\n", number);
        
        if(number > 0)
        {
            printf("Also, the number is positive.\n");
        }
        else
            printf("Also, the number is negative.\n");
    }
    return;
}

/*
Exercise 5 – Even or Odd?
Goal

Use conditions.

Task

Ask the user for an integer.

Print:

The number is even.

or

The number is odd.

Bonus

Also determine whether it is:

positive
negative
zero

Small challenge 5

Modify the function so that it also tells whether the number is:

positive
negative
zero

For example:

The number is even.
The number is positive.

Try to keep the logic inside your even_or_odd() function, or create a second function if you want to experiment.
*/