#include <stdio.h>
#include <stdbool.h>

struct Games
{
    char title[50];
    int release_year, rating;
};

void display_games(struct Games* game);
void highest_rating(struct Games* game);
void oldest_game(struct Games* game);
void get_name(char* name);
bool string_compare(char* name1, char* name2);
void find_game(char* name, struct Games* game);

int main(void)
{
    struct Games game[10] = {{"Doom", 1993, 96},{"Doom 2", 1994, 100}, 
    {"Half-Life", 1998, 97}, {"Half-Life 2", 2004, 98},
    {"Duke Nukem 3D", 1996, 93}, {"Super Mario Bros", 1985, 99},
    {"Castlevania", 1986, 92}, {"Ratchet & Clank", 2002, 91},
    {"Halo", 2001, 95}, {"Pokemon", 1998, 94}};

    char name[50];

    display_games(game);
    printf("\n");

    highest_rating(game);
    printf("\n");

    oldest_game(game);
    printf("\n");

    get_name(name);
    find_game(name, game);

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

void oldest_game(struct Games* game)
{
    int oldest = 2100, index = 0;

    for(int i = 0; i < 10; i++)
    {
        if(game[i].release_year < oldest)
        {
            oldest = game[i].release_year;
            index = i;
        }
    }
    printf("Oldest game : %s, released in %d\n",
        game[index].title, game[index].release_year);
}

void get_name(char* name)
{
    printf("What is the game you're looking for ? ");
    scanf("%49[^\n]", name); // Takes all input (even spaces) until \n
}

bool string_compare(char* name1, char* name2)
{
    int count = 0;

    while(name1[count] != '\0' || name2[count] != '\0')
    {
        if(name1[count] != name2[count])
        {
            return false;
        }
        count++;
    }
    return true;
}

void find_game(char* name, struct Games* game)
{
    bool is_found = false;

    for(int i = 0; i < 10; i++)
    {
        if(string_compare(name, game[i].title))
        {
            printf( "Game found !\n"
                    "Title : %s, release year : %d, rating : %d / 100\n",
                game[i].title, game[i].release_year, game[i].rating);
                is_found = true;
        }
    }
    if(is_found == false)
    {
        printf("Sorry, didn't find your game :/\n");
    }
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