#include <stdio.h>

int main(void)
{
    int numbers[4] = {};

    printf("Please give me five positive integers (x x x x x): ");

    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &numbers[i]);
        printf("%d\n", numbers[i]);
    }




    return(0);
}

/*
Exercise 10 — Number Statistics

Ask the user to enter 5 integers.

Then display:

the sum
the average
the largest number
the smallest number

Example:

Enter number 1: 12
Enter number 2: 4
Enter number 3: 8
Enter number 4: 20
Enter number 5: 6

Sum: 50
AverExercise 10 — Number Statistics

Ask the user to enter 5 integers.

Then display:

    the sum

    the average

    the largest number

    the smallest number

Example:

Enter number 1: 12
Enter number 2: 4
Enter number 3: 8
Enter number 4: 20
Enter number 5: 6

Sum: 50
Average: 10.00
Largest: 20
Smallest: 4

Try to avoid writing five separate variables such as:

int num1, num2, num3, num4, num5;

Instead, use a loop and reuse a variable.
*/