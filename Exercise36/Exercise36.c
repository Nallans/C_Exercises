#include <stdio.h>

struct People
{
    char name[30];
    int age;
    float height;
};

int main(void)
{
    struct People person = {"John", 28, 1.84};
    struct People* pPerson = &person;

    printf("%s, age %d, height %.2f\n",
    pPerson->name, pPerson->age, pPerson->height); 

    printf("What would be %s's new age ? ", pPerson->name);
    scanf("%d", &pPerson->age);
    printf("%s's new age : %d\n", pPerson->name, pPerson->age);

    return(0);
}

/*
Exercise 36 — A Person Through a Pointer

Create a struct People containing:

name
age
height

Create one person.

Then create a pointer to that person.

Use the pointer to:

Display the person's information.
Modify their age.
Modify their height.
Display the updated information.
*/