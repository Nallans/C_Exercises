#include <stdio.h>
#include <stdbool.h>

struct Games
{
    char title[30];
    int release_year, rating;
};

int main(void)
{
    struct Games game[10] = {{"Doom", 1993, 90}, {"Doom 2", 1994, 93},
    {"Super Mario Bros", 1985, 87}, {"Ratchet and Clank", 2002, 92},
    {"Jak & Daxter", 2001, 91}, {"SSX", 2000, 84},
    {"Pong", 1972, 80}, {"Castlevania", 1986, 88},
    {"Devil May Cry 5", 2019, 94}, {"Project Zomboid", 2013, 98}};

    return(0);
}

/*
Exercise 39 — Find and Modify

Create an array of 10 games.

Each game contains:

title
release year
rating

Ask the user for a game title.

If the game exists, allow the user to modify its rating.

Otherwise, display an appropriate message.
*/