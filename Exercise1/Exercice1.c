/*
Write a program that prints:

Hello, World!

Bonus:
Print your name on the next line.

Example:

Hello, World!
My name is Alice.
*/

#include <stdio.h>

int main(void)
{
    char greetings[] = "Hello, World !\n";
    char my_name[] = "Nallans";
    char your_name[30];
    char introducing[] = "My name is";
    int  your_age = 0;

    printf("%s", greetings);
    printf("%s %s.\n", introducing, my_name);
    printf("What is your name ? And your age ?\n");
    scanf("%29s %d", your_name, &your_age);
    printf("Your name is %s and you are %d years old.\n", your_name, your_age);

    return (0);
}