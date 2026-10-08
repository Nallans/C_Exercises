#include <stdio.h>
#include <stdlib.h>

struct People
{
    char name[30];
    int age;
    float height;
};

void get_number(int* number);
void allocate(struct People** ppPerson, int size);
void get_information(struct People** ppPerson, int size);

int main(void)
{
    int size;
    struct People person;
    struct People* pPerson = &person;
    struct People** ppPerson = &pPerson;

    printf("How many people do you want to create ? ");
    get_number(&size);
    printf("You want to create %d people\n", size);

    allocate(ppPerson, size);
    get_information(ppPerson, size);
    
    free(*ppPerson);

    return(0);
}

void get_number(int* number)
{
    scanf("%d", number);
}

void allocate(struct People** ppPerson, int size)
{
    *ppPerson = malloc(size * sizeof(struct People));

    if(*ppPerson == NULL)
    {
        printf("Memory allocation failed\n");
    }
    else
    {
        printf("Memory allocation successfull !\n");
    }
}

void get_information(struct People** ppPerson, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("What is person %d's name ? ", i + 1);
        scanf(" %29[^\n]", (*ppPerson + i)->name);
        printf("What is person %d's age ? ", i + 1);
        scanf(" %d", &((*ppPerson) + i)->age);
        printf("What is person %d's height ? ", i + 1);
        scanf(" %f", &(*ppPerson + i)->height);
    }
    for(int i = 0; i < size; i++)
    {
        printf( "%s, age %d, height %.2f\n",
                (*ppPerson + i)->name, (*ppPerson + i)->age, (*ppPerson + i)->height);
    }
}

/*
CS4E7 — Dynamic People

Now we're bringing back the structures.

Define:

struct Person
{
    char name[30];
    int age;
    float height;
};

Ask the user how many people they want to create.

Then dynamically allocate enough memory for that many struct Person.

The program must allow the user to enter every person's:

name
age
height

Then display everyone.

Finally, calculate and display:

oldest person
tallest person
average age
Constraints

You must:

dynamically allocate the people
use a pointer to the allocated structures
access members through ->
use functions
release the memory before exiting

No fixed-size Person person[100].
*/