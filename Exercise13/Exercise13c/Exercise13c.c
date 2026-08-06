#include <stdio.h>

void display(int* numbers);
void get_targets(int* target1, int* target2);
void swap(int* numbers, int target1, int target2);

int main(void)
{
    int numbers[5] = {10, 20, 30, 40, 50};
    int target1, target2;

    display(numbers);
    printf("\n");
    get_targets(&target1, &target2);
    printf("\n");
    swap(numbers, target1, target2);
    display(numbers);
    printf("\n");


    return(0);
}

void display(int* numbers)
{
    for(int i = 0; i < 5; i++)
    {
        printf("%d ", numbers[i]);
    }
}

void get_targets(int* target1, int* target2)
{
    printf( "Please give me two numbers you want to swap, "
            "choose between 1 and 5 : ");
    scanf("%d %d", target1, target2);
    while((*target1 < 1 || *target1 > 5) || (*target2 < 1 || *target2 > 5))
    {
        printf("That's not what I asked ! Please, enter correct numbers : ");
        scanf("%d %d", target1, target2);
    }
}

void swap(int* numbers, int target1, int target2)
{
    int buffer;

    buffer = numbers[target1 - 1];
    numbers[target1 - 1] = numbers[target2 - 1];
    numbers[target2 - 1] = buffer;
}

/*
Exercise 13.3 — Swap arbitrary positions

Extend the previous exercise.

Ask the user for two indices.

Swap those two positions.

Example:

Array:
10 20 30 40 50

Indices:
1 3

Result:
10 40 30 20 50

Focus: writing a reusable swap function.
*/