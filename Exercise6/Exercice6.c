#include <stdio.h>

int main(void)
{
    int num;

    printf("Hello ! I can count ! Give me a positive number, please :D\n");
    scanf("%d", &num);

    while(num < 0)
    {
        printf("Please enter a positive number\n");
        scanf("%d", &num);
    }

    
    while(num >= 0)
    {
        printf("%d\n", num);
        num--;

    }

    printf("Liftoff !!! :D\n");

    return(0);
}