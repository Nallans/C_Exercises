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
void change_quantity(char* name, struct Items* pItem, struct Items** pIndex);
void change_price(char* name, struct Items* pItem, struct Items** pIndex);
void most_expensive(struct Items* pItem);
void lowest_quantity(struct Items* pItem);
void menu(char* name, struct Items* pItem, struct Items** pIndex);

int main(void)
{
    struct Items item[10] = {{"Ayn Thor", 2, 329.99}, {"Anbernic RG SP", 10, 69.99},
    {"PS2", 4, 39.99}, {"Xbox 360", 5, 49.99}, {"Wii", 3, 29.99},
    {"WiiU", 6, 69.99}, {"PS3", 7, 59.99}, {"NES", 3, 89.99},
    {"GameBoy", 2, 99.99}, {"GameBoy Advance SP", 1, 109.99}};

    struct Items* pItem = &item[0];
    struct Items** pIndex = &pItem;
    char name[30];

    menu(name, pItem, pIndex);

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
    scanf(" %29[^\n]", name);
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

void change_quantity(char* name, struct Items* pItem, struct Items** pIndex)
{
    if(find_item(name, pItem, pIndex))
    {
        printf("What is the new quantity ? ");
        scanf("%d", &(*pIndex)->quantity);

        while((*pIndex)->quantity < 0)
        {
            printf("That's not correct, give a positive or null integer : ");
            scanf("%d", &(*pIndex)->quantity);
        }
        printf("New quantity : %s, quantity : %d, price %.2f\n",
        (*pIndex)->name, (*pIndex)->quantity, (*pIndex)->price);
    }
    else
    {
        printf("Sorry, your item was not found :/\n");
    }
}

void change_price(char* name, struct Items* pItem, struct Items** pIndex)
{
    if(find_item(name, pItem, pIndex))
    {
        printf("What is the new price ? ");
        scanf("%f", &(*pIndex)->price);

        while((*pIndex)->price < 0)
        {
            printf("That's not correct, give a positive or null price : ");
            scanf("%f", &(*pIndex)->price);
        }
        printf("New price : %s, quantity %d, price %.2f\n",
        (*pIndex)->name, (*pIndex)->quantity, (*pIndex)->price);
    }
    else
    {
        printf("Sorry, your item was not found :/\n");
    }
}

void most_expensive(struct Items* pItem)
{
    float expensive = 0;
    int index = 0;

    for(int i = 0; i < 10; i++)
    {
        if((pItem + i)->price > expensive)
        {
            expensive = (pItem + i)->price;
            index = i;
        }
    }
    printf("Most expensive item : %s, quantity : %d, price %.2f\n",
    (pItem + index)->name, (pItem + index)->quantity, (pItem + index)->price);
}

void lowest_quantity(struct Items* pItem)
{
    int lowest = 1000, index = 0;
    for(int i = 0; i < 10; i++)
    {
        if((pItem + i)->quantity < lowest)
        {
            lowest = (pItem + i)->quantity;
            index = i;
        }
    }
    printf("Lowest quantity : %s, quantity : %d, price : %.2f\n",
    (pItem + index)->name, (pItem + index)->quantity, (pItem + index)->price);
}

void menu(char* name, struct Items* pItem, struct Items** pIndex)
{
    int choice = 0;

    printf( "MENU :\n"
            "1. Display inventory\n"
            "2. Search for an item\n"
            "3. Change quantity\n"
            "4. Change price\n"
            "5. Find most expensive item\n"
            "6. Find item with lowest quantity\n"
            "7. Quit\n");

    printf("\n");

    while(choice != 7)
    {
        printf("What is your choice ? ");
        scanf("%d", &choice);

    while(choice < 1 || choice > 7)
    {
        printf("Enter a number between 1 and 7 : ");
        scanf("%d", &choice);
    }

        switch(choice)
        {
            case 1 :
            display_items(pItem);
            printf("\n");
            break;

            case 2 :
            get_name(name);
            if(find_item(name, pItem, pIndex))
            {
                printf("Item found : %s, quantity : %d, price : %.2f\n",
                (*pIndex)->name, (*pIndex)->quantity, (*pIndex)->price);
            }
            else
            {
                printf("Sorry, your item was not found :/\n");
            }
            printf("\n");
            break;

            case 3 :
            get_name(name);
            change_quantity(name, pItem, pIndex);
            printf("\n");
            break;

            case 4 :
            get_name(name);
            change_price(name, pItem, pIndex);
            printf("\n");
            break;

            case 5 : 
            most_expensive(pItem);
            printf("\n");
            break;

            case 6 :
            lowest_quantity(pItem);
            printf("\n");
            break;
        }
    }
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