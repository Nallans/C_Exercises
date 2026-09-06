#include <stdio.h>

struct People
{
    char name[20];
    int age;
};

int main(void)
{
    struct People person[5] = {{"Bryan", 30}, {"James", 23}, {"Mary", 34},
    {"John", 45}, {"Lea", 21}};

    for(int i = 0; i < 5; i++)
    {
        printf( "Person %d name : %s\n"
                "Person %d age : %d\n",
                i + 1, person[i].name, i + 1, person[i].age);
    }

    return(0);
}

/*
Exercise 34 — Searching Structures

Using an array of people, ask the user for a name.

Search for that person.

If found, display their information.

If not found, say that the person doesn't exist.

You should decide how your search function communicates its result.
*/