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
void modify_rating(char* name, struct Games* pGame);

int main(void)
{
    struct Games game[10] = {{"Doom", 1993, 90}, {"Doom 2", 1994, 93},
    {"Super Mario Bros", 1985, 87}, {"Ratchet and Clank", 2002, 92},
    {"Jak & Daxter", 2001, 91}, {"SSX", 2000, 84},
    {"Pong", 1972, 80}, {"Castlevania", 1986, 88},
    {"Devil May Cry 5", 2019, 94}, {"Project Zomboid", 2013, 98}};

    char name[30];

    struct Games* pGame = &game[0];

    display_games(pGame);
    printf("\n");

    get_name(name);
    modify_rating(name, pGame);

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

void modify_rating(char* name, struct Games* pGame)
{
    bool is_found = false;

    for(int i = 0; i < 10; i++)
    {
        if(string_compare(name, (pGame + i)->title))
        {
            is_found = true;
            printf("What is your rating ? ");
            scanf("%d", &(pGame + i)->rating);

            while((pGame + i)->rating < 0 || (pGame + i)->rating > 100)
            {
                printf("You must choose between 0 and 100 : ");
                scanf("%d", &(pGame + i)->rating);
            }
            printf("New rating : %s, released in %d, rated %d / 100\n",
            (pGame + i)-> title, (pGame + i)->release_year, (pGame + i)->rating);
            break;
        }
    }
    if(is_found == false)
    {
        printf("Sorry, your game was not found :/\n");
    }
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