#include <stdio.h>

int main(void)
{
    int num;

    printf("Hello ! I can count ! Give me a positive number, please :D\n");
    scanf("%d", &num);

    while(num < 0)
    {
        printf("Please enter a positive number\n");
        scanf("%d", &num);
    }

    
    while(num >= 0)
    {
        printf("%d\n", num);
        num--;

    }

    printf("Liftoff !!! :D\n");

    return(0);
}

/*
Exercise 6 — Countdown with while

Write a program that asks the user for a positive integer, then counts down to zero.

Example:

Enter a number: 5

5
4
3
2
1
0

Use a while loop.

Bonus: Print "Liftoff!" after reaching zero.

Improvement Challenge

Modify the program so that it keeps asking until the user enters a non-negative integer.

For example:

Give me a positive number:
-5
Please enter a non-negative number.

Give me a positive number:
-2
Please enter a non-negative number.

Give me a positive number:
4

4
3
2
1
0
Liftoff!!!
*/