#include <stdio.h>

void display_numbers(int* pNumber, int size);
void double_numbers(int* pNumber, int size);

int main(void)
{
    int numbers[8] = {12, 4, 27, 8, 15, 3, 19, 6};
    int *pNumber = &numbers[0];

    display_numbers(pNumber, 8);
    double_numbers(pNumber, 8);
    printf("\n");
    display_numbers(pNumber, 8);
    printf("\n");

    printf("%d\n", numbers[2]);     // Accessing via array index
    printf("%d\n", *(numbers + 2)); // Accessing via dereferencing the array and adding index
    printf("%d\n", *(pNumber + 2)); // Accessing via dereferencing pointer to the first element of the array

    // These are the same because an array's name decays to a pointer to its first element, so they're accessing the same variable at the same place in memory, just not by the same technique.
    // Example : Here "numbers" becomes "&numbers[0]"

    return(0);
}

void display_numbers(int* pNumber, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", *(pNumber + i));
    }
}

void double_numbers(int* pNumber, int size)
{
    for(int i = 0; i < size; i++)
    {
        *(pNumber + i) += *(pNumber + i);
    }
}

/*
CS4E2 — Pointer or Array?

Create an array:

int numbers[8] = {12, 4, 27, 8, 15, 3, 19, 6};

Create a pointer pointing to its first element.

Write a function:

void display_numbers(int *numbers, int size);

Inside the function, display every element without using numbers[i].

You must use pointer arithmetic.

Then create a second function:

void double_numbers(int *numbers, int size);

which doubles every element, again without using array indexing.

Finally, display the array from main() and verify that the original array was modified.

Extra challenge

Inside main(), experiment with these three expressions:

numbers[i]
*(numbers + i)
*(pNumbers + i)

Convince yourself that they reach the same element.

Don't just accept that they're equivalent. Figure out why.

Improvement challenge :

You actually already have a good foundation for the next step.

Notice that your double_numbers() currently has:

*(pNumber + i) += *(pNumber + i);

I want you to think about why this works rather than changing it immediately.

For the next improvement challenge, modify the function so that it can perform either multiplication or division on every element, depending on what the caller asks for.

For example, conceptually:

numbers = {12, 4, 27, 8}

operation = multiply
factor = 3

→ {36, 12, 81, 24}

or:

numbers = {12, 4, 27, 8}

operation = divide
factor = 2

→ {6, 2, 13, 4}

You decide the function's parameters and how you represent the operation.

Don't add a solution yet. The interesting part is figuring out what information the function needs and how to use the pointer to modify the original array.
*/