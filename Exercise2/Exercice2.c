/*
Exercise 2 – Variables
Goal

Create variables and print them.

Task

Create three variables:

your age
your height (float)
the first letter of your name

Print them like this:

Age: 25
Height: 1.82
Initial: A

Concepts:

int
float
char
format specifiers (%d, %f, %c)
*/

#include <stdio.h>

int main(void)
{
    int age = 32;
    float height = 1.78;
    float weight = 60.0;
    char initial = 'A';

    printf( "Hello ! Here is my information :\n");
    printf( "Age : %d years old,\n", age);
    printf( "Height : %.2f meters,\n", height);
    printf( "First name initial : %c\n", initial);
    printf( "Weight : %.2f\n"
            "BMI : %.2f\n", 
            weight, weight / (height * height) );

    return (0);
}