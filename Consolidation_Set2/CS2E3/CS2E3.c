#include <stdio.h>

struct Games
{
    char title[30];
    int release_year, rating;
};

void display_games(struct Games* game);
void lowest_rating(struct Games* game);
void latest_game(struct Games* game);

int main(void)
{
    struct Games game[10] = {{"Doom", 1993, 95}, {"Doom 2", 1994, 97},
    {"Pong", 1972, 80}, {"Super Mario Bros", 1985, 98},
    {"Pacman", 1980, 87}, {"Half-Life", 1998, 94},
    {"Half-Life 2", 2004, 96}, {"Ratchet & Clank", 2002, 92},
    {"Jak & Daxter", 2001, 93}, {"SSX", 2000, 90}};

    display_games(game);
    printf("\n");

    lowest_rating(game);
    printf("\n");

    latest_game(game);

    return(0);
}

void display_games(struct Games* game)
{
    for(int i = 0; i < 10; i++)
    {
        printf("%s, released in %d, rated %d / 100\n",
        game[i].title, game[i].release_year, game[i].rating);
    }
}

void lowest_rating(struct Games* game)
{
    int lowest = 120, index = 0;

    for(int i = 0; i < 10; i++)
    {
        if(game[i].rating < lowest)
        {
            lowest = game[i].rating;
            index = i;
        }
    }
    printf( "Booooooooooh ! The lowest rated game is %s, released in %d with %d / 100 !\n", game[index].title, game[index].release_year, game[index].rating);
}

void latest_game(struct Games* game)
{
    int latest = 0, index = 0;

    for(int i = 0; i < 10; i++)
    {
        if(game[i].release_year > latest)
        {
            latest = game[i].release_year;
            index = i;
        }
    }
    printf( "Last released game is %s in %d, rated %d / 100 !\n",
            game[index].title, game[index].release_year, game[index].rating);
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