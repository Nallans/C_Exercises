#include <stdio.h>

int main(void)
{
    void game(int tries, int num, int secret);
    int secret = 42, tries = 0, num = 0;
    char replay = 'y';

    while(replay != 'n')
    {
        tries = 0, num = 0;
        game(tries, num, secret);
        printf("Play again ? (y/n) : ");
        scanf(" %c", &replay);
    }

    return(0);
}

void game(int tries, int num, int secret)
{
    while(num != secret)
    {
        printf("Guess the number : ");
        scanf("%d", &num);
        tries++;

        if(num > secret)
        {
            printf("Too high !\n");
        }
        else if(num < secret)
            printf("Too low !\n");
    }
    printf("\n");
    printf( "WOW YOU GUESSED IT !\n"
            "It took you %d tries !\n", tries);
}

/*
Exercise 9 — Guess the Number

Create a program with a secret number:

int secret = 42;

Ask the user to guess the number.

The program should continue asking until the user guesses correctly.

Example:

Guess the number: 20
Too low!

Guess the number: 60
Too high!

Guess the number: 42
Correct!

Use a loop.

Bonus: Count how many attempts the user needed.

Improvement challenge

After the user guesses correctly, ask whether they want to play again.

Example:

WOW YOU GUESSED IT!
It took you 6 tries!

Play again? (y/n):

If they enter y, the game starts over (with the same secret number for now). If they enter n, the program exits.
*/