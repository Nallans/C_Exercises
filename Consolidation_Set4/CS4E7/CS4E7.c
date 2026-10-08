#include <stdio.h>
#include <stdlib.h>

struct People
{
    char name[30];
    int age;
    float height;
};

void get_number(int* number);

int main(void)
{
    int number;

    printf("How many people do you want to create ? ");
    get_number(&number);
    printf("You want to create %d people\n", number);

    return(0);
}

void get_number(int* number)
{
    scanf("%d", number);
}

/*
CS4E7 — Dynamic People

Now we're bringing back the structures.

Define:

struct Person
{
    char name[30];
    int age;
    float height;
};

Ask the user how many people they want to create.

Then dynamically allocate enough memory for that many struct Person.

The program must allow the user to enter every person's:

name
age
height

Then display everyone.

Finally, calculate and display:

oldest person
tallest person
average age
Constraints

You must:

dynamically allocate the people
use a pointer to the allocated structures
access members through ->
use functions
release the memory before exiting

No fixed-size Person person[100].
*/