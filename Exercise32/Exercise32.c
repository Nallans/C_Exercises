#include <stdio.h>

struct People
{
    char name[20];
    int age;
};

void string_copy(char* word, char* word2);
void get_name_age(struct People* person);
void display(struct People* person);

int main(void)
{
    struct People person[5];

    get_name_age(person);
    display(person);

    return(0);
}

void string_copy(char* word, char* word2)
{
    int count = 0;

    while(word[count] != '\0')
    {
        word2[count] = word[count];
        count++;
    }
    word2[count] = '\0';
}

void get_name_age(struct People* person)
{
    int count = 0;

    while(count < 5)
    {
        printf("Name of person n° %d : ", count + 1);
        scanf("%19s", person[count].name);
        printf("Age of person n° %d : ", count + 1);
        scanf("%d", &person[count].age);
        count++;
    }
}

void display(struct People* person)
{
    for(int i = 0; i < 5; i++)
    {
        printf("Name : %s, Age : %d\n", person[i].name, person[i].age);
    }
}

/*
Exercise 32 — Multiple Structures

Create a program that stores information about 5 people.

For each person, store:

name
age

Ask the user for all 5 people and then display them.

Your program should use an array of structures.
*/