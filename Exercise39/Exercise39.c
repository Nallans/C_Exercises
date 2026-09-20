#include <stdio.h>
#include <stdbool.h>

struct Games
{
    char title[30];
    int release_year, rating;
};

void display_games(struct Games* pGame);
bool string_compare(char* name1, char* name2);
void get_name(char* name);
bool find_game(char* name, struct Games* pGame, struct Games** pIndex);
void modify_rating(struct Games** pIndex);

int main(void)
{
    struct Games game[10] = {{"Doom", 1993, 90}, {"Doom 2", 1994, 93},
    {"Super Mario Bros", 1985, 87}, {"Ratchet and Clank", 2002, 92},
    {"Jak & Daxter", 2001, 91}, {"SSX", 2000, 84},
    {"Pong", 1972, 80}, {"Castlevania", 1986, 88},
    {"Devil May Cry 5", 2019, 94}, {"Project Zomboid", 2013, 98}};

    char name[30];
    struct Games* pGame = &game[0];
    struct Games** pIndex = &pGame;

    display_games(pGame);
    printf("\n");

    get_name(name);

    if(find_game(name, pGame, pIndex))
    {
        modify_rating(pIndex);
    }
    else
    {
        printf("Sorry, you game was not found :/\n");
    }

    return(0);
}

void display_games(struct Games* pGame)
{
    for(int i = 0; i < 10; i++)
    {
        printf("%s, released in %d, rated %d / 100\n",
        (pGame + i)->title, (pGame + i)->release_year, (pGame + i)->rating);
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
    printf("What game are you looking for ? ");
    scanf("%29[^\n]", name);
}

bool find_game(char* name, struct Games* pGame, struct Games** pIndex)
{
    for(int i = 0; i < 10; i++)
    {
        if(string_compare(name, (pGame + i)->title))
        {
            (*pIndex) = pGame + i;
            return true;
        }
    }
    return false;
}

void modify_rating(struct Games** pIndex)
{
    printf("What is your rating ? ");
    scanf("%d", &(*pIndex)->rating);
    while((*pIndex)->rating < 0 || (*pIndex)->rating > 100)
    {
        printf("Choose between 0 and 100 please : ");
        scanf("%d", &(*pIndex)->rating);
    }
    printf("New rating : %s, released in %d, rated %d / 100\n",
    (*pIndex)->title, (*pIndex)->release_year, (*pIndex)->rating);
}

/*
Exercise 39 — Find and Modify

Create an array of 10 games.

Each game contains:

title
release year
rating

Ask the user for a game title.

If the game exists, allow the user to modify its rating.

Otherwise, display an appropriate message.

Improvement challenge

Refactor your program so that find_game() and modify_rating() are separate functions.

The important constraint:

find_game() must return enough information for modify_rating() to operate on the actual struct Games that was found.

Don't use a global variable.

Don't copy the structure.

And don't have find_game() perform the modification itself.

Improvement challenge — Exercise 39

Since this exercise was specifically about separating responsibilities, I'd like one final tiny refinement:

Change find_game() so that it returns a pointer to the game it found instead of returning the index through pIndex.
*/