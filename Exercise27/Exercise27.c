#include <stdio.h>

void get_word(char* word);
void display_indexes(char* word);
void count_occurences(char* word);

int main(void)
{
    char word[30];

    get_word(word);
    display_indexes(word);
    printf("\n");
    count_occurences(word);

    return(0);
}

void get_word(char* word)
{
    printf("Word : ");
    scanf("%29s", word);
}

void display_indexes(char* word)
{
    int count = 0;

    while(word[count] != '\0')
    {
        printf("Index %d : %c\n", count, word[count]);
        count++;
    }
}

void count_occurences(char* word)
{
    int count1 = 0, count2 = 0, count3 = 0;

    while(word[count1] != '\0')
    {
        printf("Character %c appears at indexes %d", word[count1], count1);
        count2 = count1 + 1;
        while(word[count2] != '\0')
        {
            while(word[count2] == word[count1])
            {
                count3 = count2;
                while(word[count3] != '\0')
                {
                    if(word[count3] == word[count1])
                    {
                        printf(" %d", count3);
                    }
                    word[count3] = word[count3 + 1];
                    count3++;
                }
            }
            count2++;
        }
        printf("\n");
        count1++;
    }

}

/*
Exercise 27 — Count words' characters individually

Ask the user for a word and display each character along with its index.

Example:

Word: Hello

Index 0 : H
Index 1 : e
Index 2 : l
Index 3 : l
Index 4 : o

Then add one extra piece of information:

Character 'l' appears at indexes: 2 3

The second part is the important one.

Try to think about whether you need to traverse the string once or whether a different structure makes sense.
*/