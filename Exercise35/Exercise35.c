#include <stdio.h>

struct Games
{
    char title[50];
    int release_year, rating;
};

void display_games(struct Games* game);
void highest_rating(struct Games* game);

int main(void)
{
    struct Games game[10] = {{"Doom", 1993, 96},{"Doom 2", 1994, 100}, 
    {"Half-Life", 1998, 97}, {"Half-Life 2", 2004, 98},
    {"Duke Nukem 3D", 1996, 93}, {"Super Mario Bros", 1995, 99},
    {"Castlevania", 1986, 92}, {"Ratchet & Clank", 2002, 91},
    {"Halo", 2001, 95}, {"Pokemon", 1998, 94}};

    display_games(game);
    printf("\n");

    highest_rating(game);
    printf("\n");

    return(0);
}

void display_games(struct Games* game)
{
    for(int i = 0; i < 10; i++)
    {
        printf( "Game : %s, Year : %d, Rating : %d / 100\n",
                game[i].title, game[i].release_year, game[i].rating);
    }
}

void highest_rating(struct Games* game)
{
    int highest = 0, index = 0;

    for(int i = 0; i < 10; i++)
    {
        if(game[i].rating > highest)
        {
            highest = game[i].rating;
            index = i;
        }
    }
    printf("Highest rated game is : %s with %d / 100 (%d)\n",
        game[index].title, game[index].rating, game[index].release_year);
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