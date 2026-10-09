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