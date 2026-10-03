#include <stdio.h>

void analyze_numbers(int* numbers, int size, int* sum, float* average, int* highest);

int main(void)
{
    int numbers[5] = {5, 2, 1, 6, 7};
    int sum = 0, highest = 0;
    float average;

    analyze_numbers(numbers, 5, &sum, &average, &highest);

    printf( "Sum = %d\n"
            "Average = %.2f\n"
            "Highest = %d\n", sum, average, highest);

    return(0);
}

void analyze_numbers(int* numbers, int size, int* sum, float* average, int* highest)
{
    for(int i = 0; i < size; i++)
    {
        *sum += *(numbers + i);
        if(*(numbers + i) > *highest)
        {
            *highest = *(numbers + i);
        }
    }
    *average = (float) *sum / size;
}

/*
CS4E1 — Multiple Results

Write a program containing a function:

void analyze_numbers(int *numbers, int size, int *sum, float *average, int *highest);

The function receives an array of integers and must calculate:

the sum
the average
the highest value

The function must not return anything.

main() should create an array, call the function, and display all three results.

Requirements
The calculations must happen inside analyze_numbers().
main() must receive the three results through the pointer parameters.
Do not use global variables.
Do not create separate functions for each calculation.
*/