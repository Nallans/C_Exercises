#include <stdio.h>

void display(int* numbers, int length);
void get_length(int* length);
void get_numbers(int* numbers, int length);
void reverse(int* numbers, int length);

int main(void)
{
    int length;
    get_length(&length);

    int numbers[length];
    get_numbers(numbers, length);

    printf("Original array : ");
    display(numbers, length);
    reverse(numbers, length);
    printf("\n");
    printf("Reversed array : ");
    display(numbers, length);
    printf("\n");

    return(0);
}

void display(int* numbers, int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%d ", numbers[i]);
    }
}

void get_numbers(int* numbers, int length)
{
    printf("Please give me %d numbers : ", length);

    for(int i = 0; i < length; i++)
    {
        scanf("%d", &numbers[i]);
    }
}

void get_length(int* length)
{
    printf("Please give me an even length between 2 and 20 : ");
    scanf("%d", length);

    while((*length < 2 || *length > 20) || *length % 2 != 0)
    {
        printf( "That's not what I asked :'( "
                "Please give me a correct number : ");
        scanf("%d", length);
    }
}

void reverse(int* numbers, int length)
{
    int buffer;
    int end = length - 1;   // Setting the end for more readability and not getting
                            // a random value outside the array.
                            
    for(int i = 0; i < (length / 2); i++)
    {
        buffer = numbers[i];
        numbers[i] = numbers[end - i];
        numbers[end - i] = buffer;
    }
}

/*
Exercise 13 — Reverse an array

Ask the user for 6 integers.

Display:

the original array,

the reversed array.

Example:

Original:
1 2 3 4 5 6

Reversed:
6 5 4 3 2 1

Do not create a second array.

Reverse the array in place.

Use a function.
*/