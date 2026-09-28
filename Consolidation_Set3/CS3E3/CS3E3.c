#include <stdio.h>

struct Games
{
    char title[30];
    int release_year, rating;
};

void display_games(struct Games* pGame);

int main(void)
{
    struct Games game[10] = {{"Doom", 1993, 89}, {"Doom 2", 1994, 92},
    {"Pong", 1972, 76}, {"Pokemon", 1996, 93},
    {"Super Mario Bros", 1985, 87}, {"Jak & Daxter", 2001, 88},
    {"Ratchet & Clank", 2002, 91}, {"Project Zomboid", 2013, 99},
    {"Diablo", 1997, 94}, {"Half-Life", 1998, 95}};

    struct Games*  pGame = &game[0];

    display_games(pGame);

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