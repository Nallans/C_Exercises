#include <stdio.h>

struct Items
{
    char name[30];
    int quantity;
    float price;
};

int main(void)
{
    struct Items item[10] = {{"Ayn Thor", 1, 329.99}, {"Anbernic RG SP", 10, 69.99},
    {"PS2", 4, 39.99}, {"Xbox 360", 5, 49.99}, {"Wii", 3, 29.99},
    {"WiiU", 1, 69.99}, {"PS3", 6, 59.99}, {"NES", 1, 89.99},
    {"GameBoy", 2, 99.99}, {"GameBoy Advance SP", 1, 109.99}};

    return(0);
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