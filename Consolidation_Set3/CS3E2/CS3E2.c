#include <stdio.h>
#include <stdbool.h>

struct People
{
    char name[30];
    int age;
    float height;
};

void display_people(struct People* pPerson);
void find_oldest(struct People* pPerson);
void find_tallest(struct People* pPerson);
void birthday(struct People* pPerson);
void get_name(char* u_name);
bool string_compare(char* name1, char* name2);

int main(void)
{
    struct People person[8] = {{"John", 32, 1.84}, {"Lea", 23, 1.68},
    {"Bryan", 43, 1.89}, {"Mary", 38, 1.59}, {"Louis", 19, 1.73},
    {"Amanda", 29, 1.82}, {"Lindsay", 21, 1.64}, {"Hugh", 18, 1.61}};

    struct People* pPerson = &person[0];
    char u_name[30];

    display_people(pPerson);
    printf("\n");

    find_oldest(pPerson);
    printf("\n");

    find_tallest(pPerson);
    printf("\n");

    birthday(pPerson);
    display_people(pPerson);
    printf("\n");

    get_name(u_name);
    printf("%d\n", string_compare("John",u_name));

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

void find_oldest(struct People* pPerson)
{
    int oldest = 0, index = 0;

    for(int i = 0; i < 8; i++)
    {
        if((pPerson + i)->age > oldest)
        {
            oldest = (pPerson + i)->age;
            index = i;
        }
    }
    printf("Oldest person is %s, age %d\n",
    (pPerson + index)->name, (pPerson + index)->age);
}

void find_tallest(struct People* pPerson)
{
    float tallest = 0;
    int index = 0;

    for(int i = 0; i < 8; i++)
    {
        if((pPerson + i)->height > tallest)
        {
            tallest = (pPerson + i)->height;
            index = i;
        }
    }
    printf("Tallest person is %s, height %.2f\n",
    (pPerson + index)->name, (pPerson + index)->height);
}

void birthday(struct People* pPerson)
{
    for(int i = 0; i < 8; i++)
    {
        (pPerson + i)->age++;
    }
}

void get_name(char* u_name)
{
    printf("Who are you looking for ? ");
    scanf("%29s", u_name);
}

bool string_compare(char* name1, char* name2)
{
    int count = 0;

    while(name1[count] != '\0' || name2[count] != '\0')
    {
        if( name1[count] != name2[count] &&
            name1[count] + 32 != name2[count] &&
            name1[count] - 32 != name2[count])
        {
            return false;
        }
        count++;
    }
    return true;
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