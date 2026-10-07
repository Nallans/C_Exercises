#include <stdio.h>
#include <stdlib.h>

void get_size(int* size);
int* allocate(int* pNumbers, int size);
void get_numbers(int* pNumbers, int size);
void display_numbers(int* pNumbers, int size);
void operate_numbers(int* pNumbers, int size);

int main(void)
{
    int size;
    int* pNumbers = NULL;

    get_size(&size);
    printf("You want to store %d numbers\n", size);
    pNumbers = allocate(pNumbers, size);
    get_numbers(pNumbers, size);
    display_numbers(pNumbers, size);
    printf("\n");
    operate_numbers(pNumbers, size);

    free(pNumbers);

    return(0);
}

void get_size(int* size)
{
    printf("How many integers do you want to store ? ");
    scanf("%d", size);
}

int* allocate(int* pNumbers, int size)
{
    pNumbers = malloc(size * sizeof(int));
    if(pNumbers == NULL)
    {
        printf("Memory allocation failed.\n");
    }
    else
    {
        printf("Memory successfully allocated !\n");
    }
    return pNumbers;
}

void get_numbers(int* pNumbers, int size)
{
    printf("What numbers do you want to store ? ");

    for(int i = 0; i < size; i++)
    {
        scanf("%d", pNumbers + i);
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
    int sum = 0, highest = *(pNumbers + 0), lowest = *(pNumbers + 0);
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
CS4E6 — Dynamic Array Through Functions

Take the previous exercise and split the program into functions.

For example, you'll need functions that handle things like:

allocating the array
filling it
displaying it
calculating information about it

But here's the important part:

At least one function must create/allocate memory and communicate that newly allocated memory back to main().
*/