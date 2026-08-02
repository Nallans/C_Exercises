#include <stdio.h>

int main(void)
{
    void find(int *numbers, int target);
    int numbers[10] = {};
    int target;

    printf( "Give me 10 integers please.\n"
            "Numbers : ");
    
    for(int i = 0; i < 10; i++)
    {
        scanf("%d", &numbers[i]);
    }

    printf("Now please give me the number you want to search for : ");
    scanf("%d", &target);

    find(numbers, target);

    return(0);
}

void find(int *numbers, int target)
{
    int count = 0;

    for(int i = 0; i < 10; i++)
    {
        if(numbers[i] == target)
        {
            count += 1;
        }
    }

    printf("The number %d appears %d times.\n", target, count);
}

/*
Exercise 12 — Count occurrences

Ask the user for 10 integers.

Then ask for a target number.

Count how many times the target appears.

Example:

Numbers:
1 2 3 2 5 2 7 8 2 9

Target: 2

The number 2 appears 4 times.

Use a function that returns the count.
*/