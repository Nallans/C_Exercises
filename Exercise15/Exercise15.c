#include <stdio.h>

void display(int* numbers);
void allocate(int * numbers);

int main(void)
{
    int numbers[10];

    allocate(numbers);
    printf("Numbers :\n");
    display(numbers);
    printf("\n");

    return(0);
}

void display(int* numbers)
{
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", numbers[i]);
    }
}

void allocate(int* numbers)
{
    printf("Please give me 10 integers : ");
    
    for(int i = 0; i < 10; i++)
    {
        scanf("%d", &numbers[i]);
    }
}

/*
Exercise 15 — Array statistics library

This is your first “mini-library”.

Write four functions:

sum

average

maximum

minimum

Then main() should:

ask for 10 integers,

call the four functions,

print the results.

The goal is to make main() very short and readable.

Example structure:

main()
{
    read_array(...)
    print_results(...)
}

I’m not asking you to write read_array() yet, but I want you to start thinking in that direction.
*/