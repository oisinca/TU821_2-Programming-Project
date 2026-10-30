#include <iostream>
#include <string>

#include "loot.h"
#include "inventory.h"
using namespace std;

void Loot::check_inventory(const GunsNArmour& item)
{
    int slot;
    string* equippedItem;

    switch (item.tier)
    {
        case ItemTier::Primary:
            slot = 0;
            equippedItem = &inventory.primary_weapon;
            break;
        case ItemTier::Secondary:
            slot = 1;
            equippedItem = &inventory.secondary_weapon;
            break;
        case ItemTier::Armour:
            slot = 2;
            equippedItem = &inventory.armour;
            break;
        default:
            return;
    }

    if (items[slot] != 0)
    {
        cout << "You have -" << *equippedItem << "- in your inventory\n";
        cout << "Would you like to swap it for -" << new_item << "-?\n";
        cout << "Yes (y)\nNo (n)\n";

        char choice;
        cin >> choice;
        choice = tolower(choice);

        if (choice != 'y')
        {
            cout << "You have kept your -" << *equippedItem << "-\n";
            return;
        }

        cout << "You have swapped your -" << *equippedItem
             << "- for -" << new_item << "-\n";
    }
    else
    {
        cout << "You have taken -" << new_item << "-\n";
    }

    items[slot] = new_item_num;
    *equippedItem = new_item;
}

Loot::Loot()
{

}

Loot::~Loot()
{

}

Loot::Loot(string x)
{  
    if (x == "Ch1") // chest 1
    {
        loot_menu(1); // first loot menu
    }
}

void Loot::loot_menu(short y)
{
    if (y == 1)
    {
        char choice;
        cout << "Loot:\n-(Primary) Sawed-off Shotgun\n-(Secondary) Revolver\n\n Inventory: Primary: " << inventory.primary_weapon << " Secondary: " << inventory.secondary_weapon << " Armour: "<< inventory.armour << "/" << inventory.INV_SLOT <<endl;
        cout << "\n\nTake:\n1. Sawed-off Shotgun (S)\n2. Revolver (R)\n3. Exit\n (E)\n";
        cin >> choice;
        choice = tolower(choice); 
        if (choice == 's')
        {
            SawedOff item;
            new_item = "Sawed-off Shotgun";
            new_item_num = 2;
            check_inventory(item);
        }
        else if (choice == 'r')
        {
            Revolver item;
            new_item = "Revolver";
            new_item_num = 1;
            check_inventory(item);
        }
        else if (choice == 'e')
        {
            cout << "You have exited the chest\n";
        }
    }
    else if (y == 2)
    {
        //placeholder for loot menu 2 (chest 2)
    }
}
