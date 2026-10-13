#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Games
{
    char title[30];
    int release_year, rating;
};

void get_number(int* size);
void allocate(struct Games** ppGame, int size);
void get_information(struct Games** ppGame, int size, int counter);
void display_games(struct Games** ppGame, int size);
bool string_compare(char* name1, char* name2);
bool find_game(char* name, struct Games** ppGame, int size, int* index);
void change_rating(struct Games** ppGame, int index);
void add_game(struct Games** ppGame, int size, int counter);

int main(void)
{
    int size, index, counter = 0;
    char name[30];
    struct Games* pGame;
    struct Games** ppGame = &pGame;

    printf("What number of games do you want to store ? ");
    get_number(&size);
    printf("You want to store %d numbers\n", size);

    allocate(ppGame, size);
    get_information(ppGame, size, counter);
    printf("\n");
    display_games(ppGame, size);
    find_game(name, ppGame, size, &index);
    change_rating(ppGame, index);
    add_game(ppGame, size, counter);

    free(*ppGame);
    *ppGame = NULL;

    return(0);
}

void get_number(int* size)
{
    scanf(" %d", size);
}

void allocate(struct Games** ppGame, int size)
{
    *ppGame = malloc(size * (sizeof(struct Games)));
    
    if(*ppGame == NULL)
    {
        printf("Memory allocation failed\n");
    }
    else
    {
        printf("Successful memory allocation !\n");
    }
}

void get_information(struct Games** ppGame, int size, int counter)
{
    for(int i = counter; i < size; i++)
    {
        printf("What is game n°%d's title ? ", i + 1);
        scanf(" %29[^\n]", (*ppGame + i)->title);

        printf("What is game n°%d's release year ? ", i + 1);
        scanf(" %d", &(*ppGame + i)->release_year);

        while(  (*ppGame + i)->release_year < 1958 || 
                (*ppGame + i)->release_year > 2030)
        {
            printf("You must enter a year between 1958 (Tennis For Two) and 2030 : ");
            scanf(" %d", &(*ppGame + i)->release_year);
        }

        printf("What is game n°%d's rating ? ", i + 1);
        scanf(" %d", &(*ppGame + i)->rating);

        while((*ppGame + i)->rating < 0 || (*ppGame + i)->rating > 100)
        {
            printf("You must enter a number between 0 and 100 : ");
            scanf(" %d", &(*ppGame + i)->rating);
        }
    }
}

void display_games(struct Games** ppGame, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d. %s, released in %d, rated %d / 100\n", i + 1,
        (*ppGame + i)->title, (*ppGame + i)->release_year, (*ppGame + i)->rating);
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

bool find_game(char* name, struct Games** ppGame, int size, int* index)
{
    printf("What game are you looking for ? ");
    scanf(" %29[^\n]", name);

    for(int i = 0; i < size; i++)
    {
        if(string_compare(name, (*ppGame + i)->title))
        {
            *index = i;
            printf("Game found ! %s (%d), %d / 100\n", (*ppGame + i)->title,
            (*ppGame + i)->release_year, (*ppGame + i)->rating);
            return true;
        }
    }
    printf("Sorry, didn't find your game :/\n");
    return false;
}

void change_rating(struct Games** ppGame, int index)
{
    printf("What is your rating of %s ? ", (*ppGame + index)->title);
    scanf(" %d", &(*ppGame + index)->rating);

    while((*ppGame + index)->rating < 0 || (*ppGame + index)->rating > 100)
    {
        printf("You must enter a number between 0 and 100 : ");
        scanf(" %d", &(*ppGame + index)->rating);
    }
    printf("%s (%d)'s new rating : %d / 100\n", (*ppGame + index)->title,
    (*ppGame + index)->release_year, (*ppGame + index)->rating);
}

void add_game(struct Games** ppGame, int size, int counter)
{
    struct Games** temp = realloc(*ppGame, (sizeof(struct Games)) + 1);
    *temp = *ppGame;
    *temp = NULL;

    counter = size;
    size += 1;
    get_information(ppGame, size, counter);
    printf("Game added : %s (%d), %d / 100\n", (*ppGame + counter)->title,
    (*ppGame + counter)->release_year, (*ppGame + counter)->rating);
}

/*
CS4E9 — The Expansion
And this one is not for immediately tomorrow.
This is where realloc() enters.
Start with a dynamically allocated array of games.
Initially:
How many games?

Then, after entering them, offer:
1. Display games
2. Add a game
3. Search
4. Change rating
5. Remove a game
6. Quit

The user must be able to add games after the initial allocation.
*/