#include <stdio.h>

int main(void)
{
    int secret = 42, tries = 0;
    int num;
    
    while(num != secret)
    {
        printf("Guess the number : ");
        scanf("%d", &num);
        tries++;

        if(num > secret)
        {
            printf("Too high !\n");
        }
        else
            printf("Too low !\n");
        printf("\n");
    }
    printf( "WOW YOU GUESSED IT !\n"
            "It took you %d tries !\n", tries);

    return(0);
}