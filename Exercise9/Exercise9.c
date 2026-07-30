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