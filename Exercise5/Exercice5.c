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
*/

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