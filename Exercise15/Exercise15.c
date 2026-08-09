#include <stdio.h>

void display(int* numbers);
void allocate(int * numbers);
void sum(int* numbers, int* total);
void average(int* total, int* medium);
void maximum(int* numbers, int* max);
void minimum(int* numbers, int* min);
void process(int* numbers, int total, int medium, int max, int min);

int main(void)
{
    int numbers[10];
    int max = 0, min = 0, total = 0, medium = 0;

    process(numbers, total, medium, max, min);

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

void sum(int* numbers, int* total)
{
    for(int i = 0; i < 10; i++)
    {
        *total += numbers[i];
    }
}

void average(int* total, int* medium)
{
    *medium = *total / 10;
}

void maximum(int* numbers, int* max)
{
    for(int i = 0; i < 10; i++)
    {
        if(numbers[i] > *max)
        {
            *max = numbers[i];
        }
    }
}

void minimum(int* numbers, int* min)
{
    for(int i = 0; i < 10; i++)
    {
        if(i == 0)
        {
            *min = numbers[0];
        }
        else if(numbers[i] < *min)
        {
            *min = numbers[i];
        }
    }
}

void process(int* numbers, int total, int medium, int max, int min)
{
    allocate(numbers);
    printf("Numbers = ");
    display(numbers);
    printf("\n");
    sum(numbers, &total);
    average(&total, &medium);
    maximum(numbers, &max);
    minimum(numbers, &min);
    printf( "Total = %d\n"
            "Average = %d\n"
            "Maximum = %d\n"
            "Minimum = %d\n",
        total, medium, max, min);
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