#include <stdio.h>

struct Person
{
    char name[30];
    int age;
    float height;
};

void birthday(struct Person* pPerson);
void grow(struct Person* pPerson);

int main(void)
{
    struct Person person1 = {"John", 34, 1.82};
    struct Person* pPerson = &person1;

    printf("%s, age %d, height %.2f\n",
    pPerson->name, pPerson->age, pPerson->height);
    printf("\n");

    birthday(pPerson);
    grow(pPerson);
    printf("%s, age %d, height %.2f\n",
    pPerson->name, pPerson->age, pPerson->height);

    return(0);
}

void birthday(struct Person* pPerson)
{
    pPerson->age++;
}

void grow(struct Person* pPerson)
{
    pPerson->height += 0.01;
}

/*
CS3E1 — Modify a Person

Create:

struct Person
{
    char name[30];
    int age;
    float height;
};

Create one person in main().

Write:

void birthday(struct Person *pPerson);

The function should increase the person's age by 1.

Then write:

void grow(struct Person *pPerson);

which increases the person's height by 0.01.

Goal

Call both functions from main() and display the person's information before and after.
*/