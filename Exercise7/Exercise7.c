#include <stdio.h>

int main(void)
{
    int num;
    int count = 1, sum = 0;

    printf( "Hello !\n"
            "Give me a positive integer please :) :\n");
    scanf("%d", &num);

    while(num < 1)
    {
        printf("That's not a positive integer... :/\n");
        scanf("%d", &num);
    }

    while(count < num)
    {
        printf("%d + ", count);
        sum += count;
        count++;
    }
    sum += num;
    printf("%d = %d\n", num, sum);

    return(0);
}