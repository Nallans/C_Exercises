#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool find_number(int *numbers, int target);
    int numbers[8] = {};
    int target;

    printf("Please give me 8 integers : ");
    for(int i = 0; i < 8; i++)
    {
        scanf("%d", &numbers[i]);
    }

    printf("Now give me a number you want to search : ");
    scanf("%d", &target);

    if(find_number(numbers, target))
    {
        printf("Found !\n");
    }
    else 
    {
        printf("Not found.\n");
    }

    return(0);
}

bool find_number(int *numbers, int target)
{
    bool isFound = false;
    for(int i = 0; i < 8; i++)
    {
        if(numbers[i] == target)
        {
            isFound = true; 
        }
    }

    return isFound;
}

/*
Exercise 11 — Search in an array

Write a program that:

asks the user for 8 integers,

stores them in an array,

asks for a number to search,

prints whether the number is found.

Example:

Enter 8 numbers:
3 7 1 9 4 8 2 6

Search for: 4

Found!

If it is not found:

Not found.

Create a function that performs the search.

One improvement challenge :

Make the function **return a `bool`** instead of printing inside the function. Then let `main()` decide what to print.
*/