#include <stdio.h>

int main(void)
{
    int numbers[6] = {1,2,3,4,5,6};
    int length = sizeof(numbers)/sizeof(numbers[0]);


    printf("%d\n", numbers[0]);
    printf("%d\n", numbers[length - 1]);

    printf("%d\n", *(numbers + (length-1)));

    return(0);
}

/*
A test file to try using pointers, see how they work, try to access array indexes.
*/