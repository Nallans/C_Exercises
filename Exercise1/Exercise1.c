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

/*
Exercise 1 – Hello, World!
Goal

Learn how to compile and run a C program.

Task

Write a program that prints:

Hello, World!

Bonus:
Print your name on the next line.

Example:

Hello, World!
My name is Alice.

Small challenge 1

Modify the program so the user enters their name:

What is your name? John

Hello, World!
My name is John.

Tiny follow-up challenge

Without changing the scanf() line, add a second question:

What is your age?

Then display:

Your name is John.
You are 32 years old.
*/