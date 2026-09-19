#include <stdio.h>
#include <stdbool.h>

struct Games
{
    char title[30];
    int release_year, rating;
};

void display_games(struct Games* pGame);
bool string_compare(char* name1, char* name2);

int main(void)
{
    struct Games game[10] = {{"Doom", 1993, 90}, {"Doom 2", 1994, 93},
    {"Super Mario Bros", 1985, 87}, {"Ratchet and Clank", 2002, 92},
    {"Jak & Daxter", 2001, 91}, {"SSX", 2000, 84},
    {"Pong", 1972, 80}, {"Castlevania", 1986, 88},
    {"Devil May Cry 5", 2019, 94}, {"Project Zomboid", 2013, 98}};

    struct Games* pGame = &game[0];

    display_games(pGame);
    printf("\n");

    printf("%d\n", string_compare("Hello", "heLlO"));

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
*/