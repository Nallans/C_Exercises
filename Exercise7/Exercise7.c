#include <stdio.h>

int main(void)
{
    int num;
    int count = 1, sum = 0;

    printf( "Hello !\n"
            "Give me a positive integer please :) :\n");
    scanf("%d", &num);

    while(num < 1)
    {
        printf("That's not a positive integer... :/\n");
        scanf("%d", &num);
    }

    while(count < num)
    {
        printf("%d + ", count);
        sum += count;
        count++;
    }
    sum += num;
    printf("%d = %d\n", num, sum);

    return(0);
}

/*
Exercise 7 — Sum from 1 to N

Ask the user for a positive integer N, then calculate:

1 + 2 + 3 + ... + N

Example:

Enter a number: 5
The sum is: 15

Use a while loop.

Bonus: Also display the calculation:

1 + 2 + 3 + 4 + 5 = 15

Improvement challenge

Modify the program so that it correctly computes and prints the sum while keeping your nice output formatting.

Example:

Enter a positive integer:
5

1 + 2 + 3 + 4 + 5 = 15
*/