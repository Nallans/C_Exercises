#include <stdio.h>
#include <stdbool.h>

struct People
{
    char name[20];
    int age;
};

void get_name(char* user_name);
void find_person(char* user_name, struct People* person);

int main(void)
{
    struct People person[5] = {{"Bryan", 30}, {"James", 23}, {"Mary", 34},
    {"John", 45}, {"Lea", 21}};
    char user_name[20];

    for(int i = 0; i < 5; i++)
    {
        printf( "Person %d name : %s\n"
                "Person %d age : %d\n",
                i + 1, person[i].name, i + 1, person[i].age);
    }

    get_name(user_name);
    printf("You are looking for %s.\n", user_name);
    find_person(user_name, person);

    return(0);
}

void get_name(char* user_name)
{
    printf("Who are you looking for ? ");
    scanf("%19s", user_name);
}

void find_person(char* user_name, struct People* person)
{
    int count = 0;
    

    for(int i = 0; i < 5; i++)
    {
        while(person[i].name[count] != '\0')
        {
            if(person[i].name[count] != user_name[count])
            {
                printf( "Informations :\n"
                        "Name : %s\n"
                        "Age : %d\n",
                person[i].name, person[i].age);
            }
            count++;
        }
    }
}

/*
Exercise 34 — Searching Structures

Using an array of people, ask the user for a name.

Search for that person.

If found, display their information.

If not found, say that the person doesn't exist.

You should decide how your search function communicates its result.
*/