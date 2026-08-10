#include <stdio.h>

int main(void)
{
    char word[] = "A";
    char word[10];

    printf("String = %s", word);
}

/*
Experiment A

Create:

char word[] = "A";

Print:

the string,

its length.

Then think about how many bytes the array contains.

Experiment B

Create:

char word[10];

Before using scanf(), print sizeof(word).

Then compare it with Experiment A.

Experiment C

Create:

char word[] = "Hello";

Print:

sizeof(word)

the length returned by your function.

Compare those two numbers.
*/