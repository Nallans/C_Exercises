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

int main(void)
{   
    char name[30];

    struct Games game[5] = {{"Doom", 1993, 95},{"Pong", 1972, 80},
    {"Pacman", 1980, 85}, {"Super Mario Brothers", 1985, 98},
    {"Half-Life", 1998, 97}};

    display_games(game);
    printf("\n");

    get_name(name);
    printf("You are looking for %s\n", name);
    printf("\n");
    printf("%d\n", string_compare(name, "Hello"));

    return(0);
}

void display_games(struct Games* game)
{
    for(int i = 0; i < 5; i++)
    {
        printf("%s, Year %d, Rated %d / 100\n",
        game[i].title, game[i].release_year, game[i].rating);
    }
}

void get_name(char* name)
{
    printf("What game are you looking for ? ");
    scanf("%29[^\n]", name);
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