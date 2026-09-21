#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Games
{
    char title[30];
    int release_year, rating;
};

void display_games(struct Games* pGame);

int main(void)
{
    struct Games game[10] = {{"Doom", 1993, 94}, {"Driver San Francisco", 2011, 89},
    {"Jak & Daxter", 2001, 87}, {"Ratchet & Clank", 2002, 90}, 
    {"Burnout 3", 2004, 86}, {"Skate 3", 2010, 84},
    {"Half-Life", 1998, 96}, {"Project Zomboid", 2013, 98},
    {"Minecraft", 2011, 99}, {"Super Mario Bros", 1985, 95}};
    
    struct Games* pGame = &game[0];

    display_games(pGame);

    return(0);
}

void display_games(struct Games* pGame)
{
    for(int i = 0; i < 10; i++)
    {
        printf("%s, released in %d, rated %d / 100\n",
        (pGame + i)->title, (pGame + i)->release_year, (pGame+i)->rating);
    }
}

/*
Exercise 40 — The Collection Manager

This is the final exercise of the set.

Create a small program managing 10 games.

Each game contains:

title
release year
rating

The program should offer a simple menu:

1. Display games
2. Search for a game
3. Change a game's rating
4. Display highest-rated game
5. Display oldest game
6. Quit

You decide how to organize the functions.
*/