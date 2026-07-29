#include <stdio.h>

int main(void)
{
    int num, product;

    printf( "Hello !\n"
            "Can you give me a positive integer please ? :)\n");
    scanf("%d", &num);

    for(int i = 1; i < 11; i++)
    {
        product = num * i;
        printf("%d x %d = %d\n", num, i, product);
    }

    return(0);
}