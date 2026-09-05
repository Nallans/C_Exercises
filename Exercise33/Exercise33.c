#include <stdio.h>

struct People
{
    char name[20];
    int age;
};

void get_informations(struct People* person);
void display_informations(struct People* person);

int main(void)
{
    struct People person[5];

    get_informations(person);
    display_informations(person);

    return(0);
}

void get_informations(struct People* person)
{
    for(int i = 0; i < 5; i++)
    {
        printf("Person %d name : ", i + 1);
        scanf("%19s", person[i].name);
        printf("Person %d age : ", i + 1);
        scanf("%d", &person[i].age);
    }
}

void display_informations(struct People* person)
{
    for(int i = 0; i < 5; i++)
    {
        printf( "Person %d name : %s\n"
                "Person %d age : %d\n",
                i + 1, person[i].name, i + 1, person[i].age);
    }
}

/*
Exercise 33 — Functions and Structures

Take Exercise 32 and modularize it.

Create functions responsible for:

filling the array
displaying the array

The functions should receive the appropriate data as parameters.
*/