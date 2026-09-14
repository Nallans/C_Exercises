#include <stdio.h>

struct Games
{
    char title[30];
    int release_year, rating;
};

int main(void)
{
    struct Games game[10] = {{"Doom", 1993, 95}, {"Doom 2", 1994, 97},
    {"Pong", 1972, 80}, {"Super Mario Bros", 1985, 98},
    {"Pacman", 1980, 87}, {"Half-Life", 1998, 94},
    {"Half-Life 2", 2004, 96}, {"Ratchet & Clank", 2002, 92},
    {"Jak & Daxter", 2001, 93}, {"SSX", 2000, 90}};

    return(0);
}

/*
CS2E3 — Find the Extremes

Create an array of 10 structures representing something of your choice.

It could be:

games
books
movies
people
hardware
whatever you feel like.

Each structure must contain at least three different pieces of information.

Then find:

the highest value of one property
the lowest value of another property

Display the complete structures corresponding to those results.
*/