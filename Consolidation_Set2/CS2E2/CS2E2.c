#include <stdio.h>

struct Games
{
    char title[30];
    int release_year, rating;
};

int main(void)
{   
    struct Games game[5] = {{"Doom", 1993, 95},{"Pong", 1972, 80},
    {"Pacman", 1980, 85}, {"Super Mario Brothers", 1985, 98},
    {"Half-Life", 1998, 97}};

    return(0);
}

/*
CS2E2 — Game Rating Update

Create an array containing 5 games.

Each game has:

title
release year
rating

Display the games.

Ask the user for a title.

If the game exists, ask for a new rating and modify it.

Finally, display the modified game.
*/