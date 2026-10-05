#include <stdio.h>

void get_size(int* size);

int main(void)
{
    int size;
    int numbers[size];

    printf("You want %d integers\n", size);

    return(0);
}

void get_size(int* size)
{
    printf("How many integers do you want to store ? ");
    scanf("%d", size);
}
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