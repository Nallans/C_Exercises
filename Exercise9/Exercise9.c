#include <stdio.h>

int main(void)
{
    int secret = 42;
    int num;
    
    while(num =! secret)
    {
        printf("Guess the number !\n");
        scanf("%d", &num);
    }

    return(0);
}