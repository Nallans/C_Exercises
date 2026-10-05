#include <stdio.h>

void get_size(int* size);
void operate_numbers(int size);

int main(void)
{
    int size;

    get_size(&size);
    printf("You want %d integers\n", size);
    operate_numbers(size);

    return(0);
}

void get_size(int* size)
{
    printf("How many integers do you want to store ? ");
    scanf("%d", size);
}

void operate_numbers(int size)
{
    int numbers[size];
    int sum = 0, highest = 0, lowest = 1000;
    float average;

    printf("What are the numbers you want to store ? ");

    for(int i = 0; i < size; i++)
    {
        scanf(" %d", &numbers[i]);
        printf("%d ", numbers[i]);
        sum += numbers[i];

        if(numbers[i] > highest)
        {
            highest = numbers[i];
        }
        if(numbers[i] < lowest)
        {
            lowest = numbers[i];
        }
    }
    average = (float) sum / size;

    printf( "\n"
            "Sum = %d\n"
            "Average = %.2f\n"
            "Highest = %d\n"
            "Lowest = %d\n",
            sum, average, highest, lowest);
}
/*
    Notes :

        Here, the problem is that we can't initialize an array in main that is not fixed, as the user didn't gave his input at the start of main. It will create an uninitialized error. So I thought about doing it inside a function
        to have the program compile properly, then operate on the array. Problem is, the way to access the array is restricted, and it exists only while the function is running, as it is local.
*/

/*
CS4E4 — The Unknown Size Problem

Write a program that asks the user:

How many numbers do you want to enter?

The user can enter any positive number.

Then your program must store exactly that many integers and calculate:

their sum
their average
their highest value
their lowest value

Constraint

You are not allowed to declare a fixed array such as:

int numbers[100];

The amount of storage must depend on the user's answer.

But...

I'm deliberately not giving you the memory-allocation function yet.

First, think about the problem.

You know how many integers you need only after the program starts.

Ask yourself:

Where can those integers live?

This exercise is partly a programming exercise and partly a problem-solving exercise.

If you get stuck here, that's exactly where I want you to stop and ask me.
*/