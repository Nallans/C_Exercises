#include <stdio.h>

struct Games
{
    char title[30];
    int release_year, rating;
};

int main(void)
{
    struct Games game[8] = {{"Doom", 1993, 90}, {"Doom 2", 1994, 93},
    {"Ratchet & Clank", 2002, 95}, {"Jak & Daxter", 2001, 94},
    {"Skate 3", 2010, 92}, {"SSX", 2000, 91},
    {"Super Mario Bros", 1985, 96}, {"Pong", 1972, 85}};

    return(0);
}

/*
CS2E5 — Reconstruction Challenge

And finally, something I think you'll enjoy.

I'll give you a problem that combines strings + arrays + structures, but I won't tell you which previous techniques are relevant.

Create a collection of 8 games.
Each game has a title, release year, and rating.
Ask the user for a title and determine whether the game exists.
If it exists, display all its information.
Then display the highest-rated game and the oldest game.

That's it.

No function list.

No algorithm hints.

No prescribed implementation.

You've already built every individual component necessary for this.

The challenge is to recognize them and assemble them yourself.
*/