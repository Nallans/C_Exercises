#include <stdio.h>

struct Games
{
    char title[30];
    int release_year, rating;
};

void display_games(struct Games* pGame);
void get_name(char* name);

int main(void)
{
    struct Games game[10] = {{"Doom", 1993, 91}, {"Pac-Man", 1980, 78},
    {"Super Mario Bros", 1985, 89}, {"Jak & Daxter", 2001, 92},
    {"Driver San Francisco", 2011, 86}, {"Ratchet & Clank", 2002, 94},
    {"Half-Life", 1998, 97}, {"Pong", 1972, 74}};

    struct Games* pGame = &game[0];
    char name[30];

    display_games(pGame);
    printf("\n");

    get_name(name);
    printf("You're looking for %s\n", name);

    return(0);
}

void display_games(struct Games* pGame)
{
    for(int i = 0; i < 8; i++)
    {
        printf("%s, released in %d, rated %d / 100\n",
        (pGame + i)->title, (pGame + i)->release_year, (pGame + i)->rating);
    }
}

void get_name(char* name)
{
    printf("What is the game you're looking for ? ");
    scanf("%29[^\n]", name);
}

/*
CS3E5 — Reconstruction Challenge

This is the big one.

Put away your previous exercises.

Create a program from scratch for a small game collection containing 8 games.

Each game has:

title
release year
rating

The program should allow the user to:

1. Display all games
2. Search for a game
3. Change a game's rating
4. Display the highest-rated game
5. Display the oldest game
6. Display the lowest-rated game
7. Quit
*/