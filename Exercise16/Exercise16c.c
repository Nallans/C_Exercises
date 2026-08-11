#include <stdio.h>

int length(char* word);

int main(void)
{
    int count, size;
    char word[] = "A";
    char word2[10] = "";
    char word3[] = "Hello";

    
    count = length(word);
    size = sizeof(word);
    printf( "String = %s\n"
            "Length = %d\n"
            "Size = %d\n",
            word, count, size);
    count = length(word2);
    size = sizeof(word2);
    printf( "String = %s\n"
            "Length = %d\n"
            "Size = %d\n",
            word2, count, size);
    count = length(word3);
    size = sizeof(word3);
    printf( "String = %s\n"
            "Length = %d\n"
            "Size = %d\n",
            word3, count, size);
}

int length(char* word)
{
    int count = 0;

    while(word[count] != '\0')
    {
        count++;
    }
    
    return(count);
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

Before using scanf(), print countof(word).

Then compare it with Experiment A.

Experiment C

Create:

char word[] = "Hello";

Print:

countof(word)

the length returned by your function.

Compare those two numbers.
*/