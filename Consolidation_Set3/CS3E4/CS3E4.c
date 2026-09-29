#include <stdio.h>
#include <stdbool.h>

struct Items
{
    char name[30];
    int quantity;
    float price;
};

void display_items(struct Items* pItem);
void get_name(char* name);
bool string_compare(char* name1, char* name2);
bool find_item(char* name, struct Items* pItem, struct Items** pIndex);

int main(void)
{
    struct Items item[10] = {{"Ayn Thor", 1, 329.99}, {"Anbernic RG SP", 10, 69.99},
    {"PS2", 4, 39.99}, {"Xbox 360", 5, 49.99}, {"Wii", 3, 29.99},
    {"WiiU", 1, 69.99}, {"PS3", 6, 59.99}, {"NES", 1, 89.99},
    {"GameBoy", 2, 99.99}, {"GameBoy Advance SP", 1, 109.99}};

    struct Items* pItem = &item[0];
    struct Items** pIndex = &pItem;
    char name[30];

    display_items(pItem);

    get_name(name);
    if(find_item(name, pItem, pIndex))
    {
        printf("Item : %s, quantity : %d, price : %.2f\n",
        (*pIndex)->name, (*pIndex)->quantity, (*pIndex)->price);
    }
    else
    {
        printf("Sorry, this item is not in store :/\n");
    }

    return(0);
}

void display_items(struct Items* pItem)
{
    for(int i = 0; i < 10; i++)
    {
        printf("Item : %s, quantity : %d, price : %.2f €\n",
        (pItem + i)->name, (pItem + i)->quantity, (pItem + i)->price);
    }
}

void get_name(char* name)
{
    printf("What item are you looking for ? ");
    scanf("%29[^\n]", name);
}

bool string_compare(char* name1, char* name2)
{
    int count = 0;

    while(name1[count] != '\0' || name2[count] != '\0')
    {
        if( name1[count] != name2[count] &&
            name1[count] +32 != name2[count] &&
            name1[count] -32 != name2[count])
        {
            return false;
        }
        count++;
    }
    return true;
}

bool find_item(char* name, struct Items* pItem, struct Items** pIndex)
{
    for(int i = 0; i < 10; i++)
    {
        if(string_compare(name, (pItem + i)->name))
        {
            (*pIndex) = pItem + i;
            return true;
        }
    }
    return false;
}

/*
CS3E4 — Mini Inventory

Now we're going to change the domain slightly.

Create:

struct Item
{
    char name[30];
    int quantity;
    float price;
};

Create an inventory containing 10 items.

Your program should have a menu:

1. Display inventory
2. Search for an item
3. Change quantity
4. Change price
5. Find most expensive item
6. Find item with lowest quantity
7. Quit

You decide:

how many functions you need
what each function receives
what each function returns
whether pointers are needed
how the menu is structured
Important

Don't try to make this unnecessarily sophisticated.
*/