#include <stdio.h>
#include <stdlib.h>

void get_size(int* size);
void get_numbers(int* pNumbers, int size);

int main(void)
{
    int size;

    get_size(&size);

    int *pNumbers = malloc(size * sizeof(int));

    if(pNumbers == NULL)
    {
        printf("Memory allocation FAILED.\n");
        return (1);
    }

    else printf("Memory allocated successfully.\n");

    return(0);
}

void get_size(int* size)
{
    printf("What would be the size of your array ? ");
    scanf("%d", size);
}

void get_numbers(int* pNumbers, int size)
{
    for(int i = 0; i < size; i++)
    {
        scanf("%d", (pNumbers + i));
    }
}
/*
CS4E5 — Welcome to malloc()

Now we'll solve CS4E4 properly.

Write the same basic program, but this time use dynamic memory allocation.

The program should:

Ask how many integers the user wants.
Allocate enough memory for them.
Let the user enter the values.
Display them.
Calculate the sum and average.
Display the highest and lowest values.
Release the memory before the program ends.

You will need to investigate and understand:

malloc()
sizeof
free()
Rules

Don't blindly copy a malloc() pattern.

I want you to understand why something conceptually like:

number of elements × size of one element

is necessary.

And I especially want you to understand what the pointer contains after the allocation.

This is your first proper encounter with:

memory that your program requested while it was running.
*/