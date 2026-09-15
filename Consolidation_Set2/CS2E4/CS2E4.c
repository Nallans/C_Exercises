#include <stdio.h>
#include <stdbool.h>

struct Games
{
    char title[30];
    int release_year, rating;
};

void display_games(struct Games* game);
bool string_compare(char* name1, char* name2);
void get_name(char* name);
void find_game(char* name, struct Games* game);

int main(void)
{
    struct Games game[10] = {{"Doom", 1993, 95}, {"Doom 2", 1994, 96},
    {"Jak & Daxter", 2001, 93}, {"Ratchet & Clank", 2002, 94},
    {"Super Mario Bros", 1985, 98}, {"Half-Life", 1998, 97},
    {"Half-Life 2", 2004, 99}, {"SSX", 2000, 90},
    {"Devil May Cry 5", 2019, 91}, {"Castlevania", 1986, 92}};

    char name[30];

    display_games(game);
    printf("\n");

    get_name(name);
    find_game(name, game);

    return(0);
}

void display_games(struct Games* game)
{
    printf("LIBRARY : \n");
    for(int i = 0; i < 10; i++)
    {
        printf("%s, released in %d, rated %d / 100\n",
        game[i].title, game[i].release_year, game[i].rating);
    }
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

void get_name(char* name)
{
    printf("What is the game you're looking for ? ");
    scanf("%29[^\n]", name);
}

void find_game(char* name, struct Games* game)
{
    bool is_found = false;

    for(int i = 0; i < 10; i++)
    {
        if(string_compare(name, game[i].title))
        {
            printf( "%s, released in %d, rated %d / 100\n",
            game[i].title, game[i].release_year, game[i].rating);
            is_found = true;
        }
    }
    if(is_found == false)
    {
        printf("Sorry, you game was not found :/\n");
    }
}

/*
CS2E4 — The Small Database

This is the big one.

Create a small program that stores 10 records of your own design.

Your program must allow the user to:

1. Display all records
2. Search for a record
3. Modify a record
4. Display a maximum/minimum result
5. Quit

You decide:

what the structure contains
how the search works
how modification works
how the functions are organized
what the menu looks like

No prescribed architecture.
*/