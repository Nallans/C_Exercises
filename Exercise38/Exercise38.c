#include <stdio.h>

struct People
{
    char name[30];
    int age;
    float height;
};

void display_people(struct People* pPerson);
void getting_old(struct People* pPerson);
void getting_taller(struct People* pPerson);

int main(void)
{
    struct People person[5] = {{"John", 34, 1.86}, {"Lea", 21, 1.67},
    {"Francis", 45, 1.98}, {"Sarah", 37, 1.79}, {"Austin", 27, 1.71}};

    struct People* pPerson = &person[0];

    display_people(pPerson);
    printf("\n");

    getting_old(pPerson);
    display_people(pPerson);
    printf("\n");

    getting_taller(pPerson);
    display_people(pPerson);

    return(0);
}

void display_people(struct People* pPerson)
{
    for(int i = 0; i < 5; i++)
    {
        printf("Person : %s, age : %d, height %.2f\n",
        (pPerson + i)->name, (pPerson + i)->age, (pPerson + i)->height);
    }
}

void getting_old(struct People* pPerson)
{
    for(int i = 0; i < 5; i++)
    {
        (pPerson + i)->age++;
    }
}

void getting_taller(struct People* pPerson)
{
    for(int i = 0; i < 5; i++)
    {
        (pPerson + i)->height += 0.01;
    }
}

/*
Exercise 38 — Array of Structures, Modified Through a Function

Create an array of 5 people.

Then create separate functions to:

display all people
increase everyone's age by 1
display everyone again

The modification function should operate on the original array.

Don't create another array just to perform the modification.

Improvement challenge

You already increment every person's age.

Now add a second operation: create a function that receives the same pointer and increases every person's height by 0.01.
*/