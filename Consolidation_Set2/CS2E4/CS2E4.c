#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Games
{
    char title[30];
    int release_year, rating;
};

void menu(char* name, struct Games* game, int choice);
void display_games(struct Games* game);
bool string_compare(char* name1, char* name2);
void get_name(char* name);
void find_game(char* name, struct Games* game);
void modify_rating(char* name, struct Games* game);
void max_min_rating(struct Games* game);

int main(void)
{
    struct Games game[10] = {{"Doom", 1993, 95}, {"Doom 2", 1994, 96},
    {"Jak & Daxter", 2001, 93}, {"Ratchet & Clank", 2002, 94},
    {"Super Mario Bros", 1985, 98}, {"Half-Life", 1998, 97},
    {"Half-Life 2", 2004, 99}, {"SSX", 2000, 90},
    {"Devil May Cry 5", 2019, 91}, {"Castlevania", 1986, 92}};

    char name[30];
    int choice = 1;

    while(choice > 0 || choice < 6)
    {
        menu(name, game, choice);
    }

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
    scanf(" %29[^\n]", name);
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

void modify_rating(char* name, struct Games* game)
{
    bool is_found = false;

    for(int i = 0; i < 10; i++)
    {
        if(string_compare(name, game[i].title))
        {
            printf("What rating do you give %s ? ", game[i].title);
            scanf("%d", &game[i].rating);
    
            while(game[i].rating < 0 || game[i].rating > 100)
            {
                printf("It must be rated between 0 and 100. Try again : ");
                scanf("%d", &game[i].rating);
            }

            printf("Okay. Now it's %s, released in %d, rated %d / 100.\n",
            game[i].title, game[i].release_year, game[i].rating);

            is_found = true;
            break;
        }
    }
    if(is_found == false)
    {
        printf("Sorry, your game was not found :/\n");
    }
}

void max_min_rating(struct Games* game)
{
    int highest = -1, lowest = 101, index_max = 0, index_min = 0;

    for(int i = 0; i < 10; i++)
    {
        if(game[i].rating > highest)
        {
            highest = game[i].rating;
            index_max = i;
        }
        if(game[i].rating < lowest)
        {
            lowest = game[i].rating;
            index_min = i;
        }
    }
    printf("Highest rated game is %s, released in %d, rated %d / 100\n",
    game[index_max].title, game[index_max].release_year, game[index_max].rating);
    printf("Lowest rated game is %s, released in %d, rated %d / 100\n",
    game[index_min].title, game[index_min].release_year, game[index_min].rating);
}

void menu(char* name, struct Games* game, int choice)
{
    printf( "1. Display all games.\n"
            "2. Search for a game.\n"
            "3. Modify a game rating.\n"
            "4. Display highest and lowest rated games.\n"
            "5. Quit.\n"
            "\n"
            "What is your choice ? ");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1 : 
            printf("\n");
            display_games(game);
            printf("\n");
            break;
        
        case 2 :
            printf("\n");
            printf("What is the game you're looking for ? ");
            get_name(name);
            find_game(name, game);
            printf("\n");
            break;

        case 3 : 
            printf("\n");
            printf("What is the game you want to modify ? ");
            get_name(name);
            modify_rating(name, game);
            printf("\n");
            break;
        
        case 4 :
            printf("\n");
            max_min_rating(game);
            printf("\n");
            break;
        
        case 5 :
            exit(0);   // Exit command used with stdlib to quit program      

        default :
            while(choice < 1 || choice > 5)
            {
                printf("Duh, that's not a good choice. "
                "Using a correct number will take you back to menu : ");
                scanf("%d", &choice);
            }
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