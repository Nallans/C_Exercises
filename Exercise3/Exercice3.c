/*
Exercise 3 – User Input
Goal

Read information from the user.

Task

Ask the user:

What is your name?

Then ask:

How old are you?

Finally print:

Hello Alice!
Next year you will be 26 years old.
*/

#include <stdio.h>

int main(void)
{
    char ask_name[] = "Hello, what is your name ?\n";
    char ask_age[] = "When were you born ? How old are you ?\n";
    char name[30];
    int age, year = 0;

    printf("%s", ask_name);
    scanf("%29s", name);
    printf("%s", ask_age);
    scanf("%d %d", &year, &age);

    printf("Hello %s,\n", name);
    printf( "You were born in %d\n"
            "Next year you will be %d years old\n", 
            year, age + 1);

    return (0);
}