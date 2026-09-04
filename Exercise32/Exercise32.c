#include <stdio.h>

void string_copy(char* word, char* word2);
//void get_name_age(char* name, int* age);

int main(void)
{
    struct People
    {
       char name[20];
       int age; 
    };

    struct People person1, person2, person3, person4, person5;

    

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

/*
Exercise 32 — Multiple Structures

Create a program that stores information about 5 people.

For each person, store:

name
age

Ask the user for all 5 people and then display them.

Your program should use an array of structures.
*/