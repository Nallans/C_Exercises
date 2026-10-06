#include <stdio.h>
#include <stdlib.h>

void get_size(int* size);
void get_numbers(int* pNumbers, int size);
void display_numbers(int* pNumbers, int size);
void operate_numbers(int* pNumbers, int size);

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

    get_numbers(pNumbers, size);
    display_numbers(pNumbers, size);
    printf("\n");
    operate_numbers(pNumbers, size);
    free(pNumbers);

    return(0);
}

void get_size(int* size)
{
    printf("What would be the size of your array ? ");
    scanf("%d", size);
}

void get_numbers(int* pNumbers, int size)
{
    printf("What are the numbers you want to store ? ");

    for(int i = 0; i < size; i++)
    {
        scanf("%d", (pNumbers + i));
    }
}

void display_numbers(int* pNumbers, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", *(pNumbers + i));
    }
}

void operate_numbers(int* pNumbers, int size)
{
    int sum = 0, highest = 0, lowest = 999;
    float average;

    for(int i = 0; i < size; i++)
    {
        sum += *(pNumbers + i);

        if(highest < *(pNumbers + i))
        {
            highest = *(pNumbers + i);
        }
        if(lowest > *(pNumbers + i))
        {
            lowest = *(pNumbers + i);
        }
    }
    average = (float) sum / size;

    printf( "Sum = %d\n"
            "Average = %.2f\n"
            "Highest = %d\n"
            "Lowest = %d\n",
            sum, average, highest, lowest);
}

/*
        Notes :

        - number of elements * size of the elements is necessary because that represents how many blocs of memory we need. If we only do size, it doesn't work : For example we need to store an array of 5 integers. 5 * 1 = 5, but this value is okay for 5 char types, so we could not all the numbers in our array : only one. Whereas 5 integers are 5 * 4 = 20, that would be the exact byte size of memory we need.
        - The pointer contains random values after using malloc. That's where calloc is useful : it initializes new space with 0. When using malloc, we must always assign values to the new space we just allocated to avoid unexpected behavior. Otherwise, we'll print "garbage" random values stored in the addresses.
*/

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