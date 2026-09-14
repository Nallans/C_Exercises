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
void modify_game(char* name1, struct Games* game);

int main(void)
{   
    char name[30];

    struct Games game[5] = {{"Doom", 1993, 95},{"Pong", 1972, 80},
    {"Pacman", 1980, 85}, {"Super Mario Brothers", 1985, 98},
    {"Half-Life", 1998, 97}};

    display_games(game);
    printf("\n");

    get_name(name);
    printf("\n");

    modify_game(name, game);

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

void modify_game(char* name, struct Games* game)
{
    bool is_found = false;

    for(int i = 0; i < 5; i++)
    {
        if(string_compare(name, game[i].title))
        {
            is_found = true;
            printf("What is your rating of %s ? ", game[i].title);
            scanf("%d", &game[i].rating);

            while(game[i].rating < 0 || game[i].rating > 100)
            {
                printf("Please give a rating between 0 and 100 : ");
                scanf("%d", &game[i].rating);
            }
            printf("%s : New rating : %d / 100\n", 
            game[i].title, game[i].rating);
        }
    }
    if(is_found == false)
    {
        printf("Sorry, didn't find your game :/\n");
    }
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