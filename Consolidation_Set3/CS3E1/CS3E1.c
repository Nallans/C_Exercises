#include <stdio.h>

struct Person
{
    char name[30];
    int age;
    float height;
};

int main(void)
{
    struct Person person1 = {"John", 34, 1.82};
    struct Person* pPerson1 = &person1;

    printf("%s, age %d, height %.2f\n",
    pPerson1->name, pPerson1->age, pPerson1->height);

    return(0);
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