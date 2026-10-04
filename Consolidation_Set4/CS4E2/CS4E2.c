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
*/