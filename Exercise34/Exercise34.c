#include <stdio.h>
#include <stdbool.h>

struct People
{
    char name[20];
    int age;
};

void get_name(char* user_name);
void find_person(char* user_name, struct People* person);
bool string_compare(char* name1, char* name2);

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
    bool is_found = false;

    for(int i = 0; i < 5; i++)
    {
        if(string_compare(user_name, person[i].name))
        {
            printf( "The person is :\n"
                    "Name : %s\n"
                    "Age : %d\n",
                    person[i].name, person[i].age);
                    is_found = true;           
        }
    }
    if(is_found == false)
    {
        printf("This person doesn't exist.\n");
    }
}

bool string_compare(char* name1, char* name2)
{
    int count = 0;
    bool is_same = true;

    while(name1[count] != '\0' || name2[count] != '\0')
    {
        if(name1[count] != name2[count])
        {
            is_same = false;
            return is_same;
        }
        count++;
    }
    return is_same;
}

/*
Exercise 34 — Searching Structures

Using an array of people, ask the user for a name.

Search for that person.

If found, display their information.

If not found, say that the person doesn't exist.

You should decide how your search function communicates its result.
*/