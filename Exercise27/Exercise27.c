#include <stdio.h>

void get_word(char* word);
void display_indexes(char* word);
void truncate_word(char* word);
void string_copy(char* word, char* word2);
void count_occurences(char* word, char* word2);

int main(void)
{
    char word[30], word2[30];

    get_word(word);
    string_copy(word, word2);
    printf("Word 1 : %s, word 2 %s\n", word, word2);

    display_indexes(word);
    printf("\n");

    truncate_word(word);
    printf("Word 1 : %s, word 2 %s\n", word, word2);
    count_occurences(word, word2);

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

void truncate_word(char* word)
{
    int count1 = 0, count2 = 0, count3 = 0;

    while(word[count1] != '\0')
    {
        count2 = count1 + 1;
        while(word[count2] != '\0')
        {
            while(  word[count2] == word[count1] || 
                    word[count2] == word[count1] + 32 ||
                    word[count2] == word[count1] - 32)
            {
                count3 = count2;
                while(word[count3] != '\0')
                {
                    word[count3] = word[count3 + 1];
                    count3++;
                }
            }
            count2++;
        }
        count1++;
    }

}

void string_copy(char* word, char* word2)
{
    int count = 0;

    while(word[count] != '\0')
    {
        word2[count] = word[count];
        count++;
    }
    word2[count] = '\0';
}

void count_occurences(char* word, char* word2)
{
    int count = 0, count2 = 0;

    while(word[count] != '\0')
    {
        printf("Character \'%c\' appears at indexes :", word[count]);
        while(word2[count2] != '\0')
        {
            if(word2[count2] == word[count])
            {
                printf(" %d", count2);
            }
            count2++;
        }
        printf("\n");
        count++;
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