#include <stdio.h>
#include <stdbool.h>

struct Games
{
    char title[30];
    int release_year, rating;
};

void display_games(struct Games* pGame);
void get_name(char* name);
bool string_compare(char* name1, char* name2);

int main(void)
{
    struct Games game[10] = {{"Doom", 1993, 89}, {"Doom 2", 1994, 92},
    {"Pong", 1972, 76}, {"Pokemon", 1996, 93},
    {"Super Mario Bros", 1985, 87}, {"Jak & Daxter", 2001, 88},
    {"Ratchet & Clank", 2002, 91}, {"Project Zomboid", 2013, 99},
    {"Diablo", 1997, 94}, {"Half-Life", 1998, 95}};

    struct Games*  pGame = &game[0];
    char name[30];

    display_games(pGame);

    get_name(name);
    printf("You are looking for %s\n",name);
    printf("%d\n", string_compare(name, "Doom"));

    return(0);
}

void display_games(struct Games* pGame)
{
    for(int i = 0; i < 10; i++)
    {
        printf("%s, released in %d, rated %d / 100\n",
        (pGame + i)->title, (pGame + i)->release_year, (pGame + i)->rating);
    }
}

void get_name(char* name)
{
    printf("What game are you looking for ? ");
    scanf("%29[^\n]", name);
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
CS3E3 — Find and Return a Person

This one is important.

Create an array of 10 games:

struct Games
{
    char title[30];
    int release_year;
    int rating;
};

Write a function that searches for a game by title.

But this time:

The search function should give the caller access to the actual struct Games that it found.

Do not use:

global variables
a copied struct Games
an index as the returned result
*/