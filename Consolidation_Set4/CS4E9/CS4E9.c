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
void get_information(struct Games** ppGame, int size);
void display_games(struct Games** ppGame, int size);

int main(void)
{
    int i_size;
    struct Games* pGame;
    struct Games** ppGame = &pGame;

    printf("What number of games do you want to store ? ");
    get_number(&i_size);
    printf("You want to store %d numbers\n", i_size);

    allocate(ppGame, i_size);
    get_information(ppGame, i_size);
    printf("\n");
    display_games(ppGame, i_size);

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

void get_information(struct Games** ppGame, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("What is game n°%d's title ? ", i + 1);
        scanf(" %29[^\n]", (*ppGame + i)->title);
        printf("What is game n°%d's release year ? ", i + 1);
        scanf(" %d", &(*ppGame + i)->release_year);
        printf("What is game n°%d's rating ? ", i + 1);
        scanf(" %d", &(*ppGame + i)->rating);
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