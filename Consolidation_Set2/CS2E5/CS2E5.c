#include <stdio.h>
#include <stdbool.h> 

struct Games
{
    char title[30];
    int release_year, rating;
};

void display_games(struct Games* game);
void get_name(char* name);
bool string_compare(char* name1, char* name2);
void find_game(char* name, struct Games* game);
void highest_rated(struct Games* game);
void oldest_game(struct Games* game);

int main(void)
{
    struct Games game[8] = {{"Doom", 1993, 90}, {"Doom 2", 1994, 93},
    {"Ratchet & Clank", 2002, 95}, {"Jak & Daxter", 2001, 94},
    {"Skate 3", 2010, 92}, {"SSX", 2000, 91},
    {"Super Mario Bros", 1985, 96}, {"Pong", 1972, 85}};

    char name[30];

    display_games(game);
    printf("\n");

    get_name(name);
    find_game(name, game);
    printf("\n");

    highest_rated(game);
    printf("\n");
    oldest_game(game);
    printf("\n");

    return(0);
}

void display_games(struct Games* game)
{
    for(int i = 0; i < 8; i++)
    {
        printf("%s, released in %d, rated %d / 100\n",
        game[i].title, game[i].release_year, game[i].rating);
    }
}

void get_name(char* name)
{
    printf("What is the game you're looking for ? ");
    scanf("%29[^\n]", name);
}

bool string_compare(char* name1, char* name2)
{
    int count = 0;

    while(name1[count] != '\0' || name2[count] != '\0')
    {
        if( name1[count] != name2[count] &&
            name1[count] + 32 != name2[count] &&
            name1[count] - 32 != name2[count])
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

    for(int i = 0; i < 8; i++)
    {
        if(string_compare(name, game[i].title))
        {
            is_found = true;
            printf("Game : %s, released in %d, rated %d / 100\n",
            game[i].title, game[i].release_year, game[i].rating);
            break;
        }
    }
    if(is_found == false)
    {
        printf("Sorry, your game was not found :/\n");
    }
}

void highest_rated(struct Games* game)
{
    int highest = 0, index = 0;

    for(int i = 0; i < 8; i++)
    {
        if(game[i].rating > highest)
        {
            highest = game[i].rating;
            index = i;
        }
    }
    printf("Highest rated game is %s, released in %d, rated %d / 100\n",
    game[index].title, game[index].release_year, game[index].rating);
}

void oldest_game(struct Games* game)
{
    int oldest = 2100, index = 0;
    
    for(int i = 0; i < 8; i++)
    {
        if(game[i].release_year < oldest)
        {
            oldest = game[i].release_year;
            index = i;
        }
    }
    printf("Oldest game is %s, released in %d, rated %d / 100\n",
    game[index].title, game[index].release_year, game[index].rating);
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