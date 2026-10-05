#include <stdio.h>

void inspect_array(int* pNumbers, int size);

int main(void)
{
    int numbers[10] = {3, 1, 8, 4, 6, 2, 9, 0, 7, 5};
    int* pNumbers = numbers;

    inspect_array(pNumbers, 10);

    return(0);
}

void inspect_array(int* pNumbers, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf( "Value : %d\n"
                "Index : %d\n"
                "Address : %p\n",
                *(pNumbers + i), i, (pNumbers + i));
    }
}

/*
CS4E3 — Walking Through Memory

Now we're going to make pointer arithmetic more explicit.

Create an array of integers:

int numbers[10] = { ... };

Create:

int *pNumbers = numbers;

Write a function:

void inspect_array(int *pNumbers, int size);

For every element, display:

its value
its index
its address

Conceptually, you want output resembling:

Index 0 | Value: 42 | Address: 0x...
Index 1 | Value: 17 | Address: 0x...
Index 2 | Value: 91 | Address: 0x...

You may use %p for addresses.

Then investigate what happens when you compare:

pNumbers
pNumbers + 1
pNumbers + 2

Important

Don't worry about the actual hexadecimal addresses being "nice."

The interesting part is:

What changes between pNumbers and pNumbers + 1?
*/