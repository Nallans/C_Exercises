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

int main(void)
{
    int i_size;
    struct Games* pGame;
    struct Games** ppGame = &pGame;

    printf("What number of games do you want to store ? ");
    get_number(&i_size);
    printf("You want to store %d numbers\n", i_size);

    allocate(ppGame, i_size);

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