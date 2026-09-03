#include <stdio.h>

void string_copy(char* word, char* word2);
void get_info(char* name, int* age, float* height);

int main(void)
{
    struct person
    {
        char name[20];
        int age;
        float height;
    };

    struct person p1;

    string_copy("Bob", p1.name);
    p1.age = 24;
    p1.height = 1.72; 

    printf( "Test person :\n"
            "Name : %s\n"
            "Age : %d\n"
            "Height : %.2f\n",
            p1.name, p1.age, p1.height);

    get_info(p1.name, &p1.age, &p1.height);

    printf( "Name : %s\n"
        "Age : %d\n"
        "Height : %.2f\n",
        p1.name, p1.age, p1.height);


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

void get_info(char* name, int* age, float* height)
{
    printf("Tell me your name : ");
    scanf("%19s", name);
    printf("Your age : ");
    scanf("%d", age);
    printf("And your height : ");
    scanf("%f", height);
}

/*
Exercise 31 — Your First Structure

Create a structure representing a person.

It should contain:

a name
an age
a height

Create one person, ask the user for their information, then display it.

Goal: Become comfortable declaring, creating, accessing, and modifying a structure.
*/