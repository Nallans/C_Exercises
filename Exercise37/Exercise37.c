#include <stdio.h>

struct People
{
    char name[30];
    int age;
    float height;
};

void display_person(struct People* person);
void modify_person(struct People* person);
void getting_old(struct People* person);

int main(void)
{
    struct People person = {"John", 34, 1.84};
    struct People* pPerson = &person;

    display_person(pPerson);
    printf("\n");

    modify_person(pPerson);
    printf("\n");

    display_person(pPerson);
    printf("\n");

    getting_old(pPerson);
    printf("\n");

    display_person(pPerson);

    return(0);
}

void display_person(struct People* pPerson)
{
    printf("Person : %s, age : %d, height %.2f\n",
    pPerson->name, pPerson->age, pPerson->height);
}

void modify_person(struct People* pPerson)
{
    printf("What age do you want to give %s ? ", pPerson->name);
    scanf("%d", &pPerson->age);
    printf("What height do you want to give %s ? ", pPerson->name);
    scanf("%f", &pPerson->height);
}

void getting_old(struct People* pPerson)
{
    pPerson->age++;
}

/*
Exercise 37 — Modify Through a Function

Create a struct People again.

Create a function that receives a pointer to a person and modifies their information.

For example, the function could update the person's age and height.

Your main() should create the person and call the function.

Improvement challenge

Make modify_person() modify only the age, while leaving height untouched.

Then have it increase the person's age by 1 automatically rather than asking the user for a new age.

It's deliberately tiny: I want you to practice modifying a member through the pointer without adding another concept.
*/