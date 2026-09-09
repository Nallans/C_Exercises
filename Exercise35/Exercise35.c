#include <stdio.h>

struct Games
{
    char title[50];
    int release_year, rating;
};

int main(void)
{
    struct Games game[10] = {{"Doom", 1993, 95},{"Doom 2", 1994, 98}, 
    {"Half-Life", 1998, 98}, {"Half-Life 2", 2004, 98},
    {"Duke Nukem 3D", 1996, 90}, {"Super Mario Bros", 1995, 98},
    {"Castlevania", 1986, 90}, {"Ratchet & Clank", 2002, 90},
    {"Halo", 2001, 95}, {"Pokemon", 1998, 95}};

    for(int i = 0; i < 10; i++)
    {
        printf( "Game : %s, Year : %d, Rating : %d / 100\n",
                game[i].title, game[i].release_year, game[i].rating);
    }

    return(0);
}

/*
Exercise 35 — The Old Familiar Problem

Create a structure representing a game:

title
release year
rating

Store 10 games.

Then:

Display all games.
Find the game with the highest rating.
Find the oldest game.
Search for a game by title.
*/