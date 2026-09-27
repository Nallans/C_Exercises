#include <stdio.h>

struct People
{
    char name[30];
    int age;
    float height;
};

void display_people(struct People* pPerson);

int main(void)
{
    struct People person[8] = {{"John", 32, 1.84}, {"Lea", 23, 1.68},
    {"Bryan", 43, 1.89}, {"Mary", 38, 1.59}, {"Louis", 19, 1.73},
    {"Amanda", 29, 1.82}, {"Lindsay", 21, 1.64}, {"Hugh", 18, 1.61}};

    struct People* pPerson = &person[0];

    display_people(pPerson);

    return(0);
}

void display_people(struct People* pPerson)
{
    for(int i = 0; i < 8; i++)
    {
        printf("%s, age %d, height %.2f\n",
        (pPerson + i)->name, (pPerson + i)->age, (pPerson + i)->height);
    }
}

/*
CS3E2 — People Database

Create an array of 8 people.

Each person has:

name
age
height

Write functions to:

Display everyone.
Find the oldest person.
Find the tallest person.
Search for a person by name.
Increase everyone's age by 1.

You decide the function organization.

Constraint

Don't copy entire struct Person objects unnecessarily.

Pass the array through a pointer.
*/