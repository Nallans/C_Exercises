#include <stdio.h>
#include <stdlib.h>

struct Games
{
    char title[30];
    int release_year, rating;
};

void get_size(int* size);
void allocate(struct Games** ppGame, int size);
void get_information(struct Games** ppGame, int size);

int main(void)
{
    int size;
    struct Games game;
    struct Games* pGame = &game;
    struct Games** ppGame = &pGame;

    get_size(&size);
    printf("You want to store %d games\n", size);
    allocate(ppGame, size);
    get_information(ppGame, size);

    return(0);
}

void get_size(int* size)
{
    printf("How many games do you want to store ? ");
    scanf("%d", size);
}

void allocate(struct Games** ppGame, int size)
{
    *ppGame = malloc(size * (sizeof(struct Games)));
    
    if(*ppGame == NULL)
    {
        printf("Memory allocation failed.\n");
    }
    else
    {
        printf("Memory allocation successful !\n");
    }
}

void get_information(struct Games** ppGame, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("What is game n° %d's title ? ", i + 1);
        scanf(" %29[^\n]", (*ppGame + i)->title);
        printf("What is game n° %d's release year ? ", i + 1);
        scanf(" %d", &(*ppGame + i)->release_year);
        printf("What is game n° %d's rating ? ", i + 1);
        scanf(" %d", &(*ppGame + i)->rating);

        printf("%d. %s, released in %d, rated %d / 100\n",
        i + 1,
        (*ppGame + i)->title, (*ppGame + i)->release_year, (*ppGame + i)->rating);
    }
}

/*
CS4E8 — The First Real Memory Challenge

Okay.

This one is where I stop holding your hand.

Create a program that maintains a dynamically allocated list of games.

Each game contains:

struct Game
{
    char title[30];
    int release_year;
    int rating;
};

The program initially asks:

How many games do you want to enter?

Allocate exactly enough memory.

Then allow the user to:

1. Display games
2. Search for a game
3. Change a rating
4. Display highest-rated game
5. Display oldest game
6. Quit
*/