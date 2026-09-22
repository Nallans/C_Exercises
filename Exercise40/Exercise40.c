#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Games
{
    char title[30];
    int release_year, rating;
};

void display_games(struct Games* pGame);
void get_name(char* name);
bool string_compare(char* name1, char* name2);
bool find_game(char* name1, struct Games* pGame, struct Games** pIndex);
void modify_rating(struct Games** pIndex);

int main(void)
{
    struct Games game[10] = {{"Doom", 1993, 94}, {"Driver San Francisco", 2011, 89},
    {"Jak & Daxter", 2001, 87}, {"Ratchet & Clank", 2002, 90}, 
    {"Burnout 3", 2004, 86}, {"Skate 3", 2010, 84},
    {"Half-Life", 1998, 96}, {"Project Zomboid", 2013, 98},
    {"Minecraft", 2011, 99}, {"Super Mario Bros", 1985, 95}};
    
    struct Games* pGame = &game[0];
    struct Games** pIndex = &pGame;
    char name[30];

    display_games(pGame);
    printf("\n");

    get_name(name);
    find_game(name, pGame, pIndex);
    printf("\n");

    modify_rating(pIndex);

    return(0);
}

void display_games(struct Games* pGame)
{
    for(int i = 0; i < 10; i++)
    {
        printf("%s, released in %d, rated %d / 100\n",
        (pGame + i)->title, (pGame + i)->release_year, (pGame+i)->rating);
    }
}

void get_name(char* name)
{
    printf("What is the game you're looking for ? ");
    scanf("%[^\n]", name);
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

bool find_game(char* name, struct Games* pGame, struct Games** pIndex)
{
    for(int i = 0; i < 10; i++)
    {
        if(string_compare(name, (pGame + i)->title))
        {
            *pIndex = &(*pGame) + i;
            printf("%s, released in %d, rated %d / 100\n",
            (*pIndex)->title, (*pIndex)->release_year, (*pIndex)->rating);
            return true;
        }
    }
    printf("Sorry, the game you're looking for is not present\n");
    return false;
}

void modify_rating(struct Games** pIndex)
{
    printf("What is your rating of %s ? ", (*pIndex)->title);
    scanf("%d", &(*pIndex)->rating);
    
    while((*pIndex)->rating < 0 || (*pIndex)->rating > 100)
    {
        printf("You need to choose between 0 and 100 : ");
        scanf("%d", &(*pIndex)->rating);
    }
    printf("New rating : %s, released in %d, rated %d / 100\n",
    (*pIndex)->title, (*pIndex)->release_year, (*pIndex)->rating);
}

/*
Exercise 40 — The Collection Manager

This is the final exercise of the set.

Create a small program managing 10 games.

Each game contains:

title
release year
rating

The program should offer a simple menu:

1. Display games
2. Search for a game
3. Change a game's rating
4. Display highest-rated game
5. Display oldest game
6. Quit

You decide how to organize the functions.
*/