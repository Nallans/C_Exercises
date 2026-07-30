#include <stdio.h>

int main(void)
{
    int num, product, limit;

    printf( "Hello !\n"
            "Can you give me a positive integer please ? :)\n"
            "Give me also the limit of the table in this format : x x\n");
    scanf("%d %d", &num, &limit);

    for(int i = 1; i <= limit; i++)
    {
        product = num * i;
        printf("%d x %d = %d\n", num, i, product);
    }

    return(0);
}