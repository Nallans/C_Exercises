#include <stdio.h>

int main(void)
{
    int secret = 42, tries = 0, num = 0;
    
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
        printf("\n");
    }
    printf( "WOW YOU GUESSED IT !\n"
            "It took you %d tries !\n", tries);

    return(0);
}