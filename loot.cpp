#include <iostream>
#include <string>

#include "loot.h"
#include "inventory.h"
using namespace std;

void Loot::check_inventory()
{
    Inventory inventory;
    char choice;
    if (items[0]>0)
    {
        cout << "You have -" << inventory.primary_weapon  <<"- in your inventory\n";
        cout << "Would you like to swap it for -" << new_item << "-?\n";
        cout << "Yes (y)\nNo (n)\n";
        cin >> choice;
        choice = tolower(choice);
        
        if (choice == 'y')
        {
            cout << "You have swapped your -" << inventory.primary_weapon << "- for -" << new_item << "-\n";
            items[0] = new_item_num;
        }
        else if (choice == 'n')
        {
            cout << "You have kept your -" << inventory.primary_weapon << "-\n";
        }
    }
    else if (items[0] == 0)
    {
        items[0] = new_item_num;
        cout << "You have taken -" << new_item << "-\n";
        inventory.primary_weapon = new_item;
    }
    
    if (items[1]>0)
    {
        cout << "You have -" << inventory.secondary_weapon <<"- in your inventory\n";
        cout << "Would you like to swap it for -" << new_item << "-?\n";
        cout << "Yes (y)\nNo (n)\n";
        cin >> choice;
        choice = tolower(choice);

        if (choice == 'y')
        {
            cout << "You have swapped your -" << inventory.secondary_weapon << "- for -" << new_item << "-\n";
            items[1] = new_item_num;
        }
        else if (choice == 'n')
        {
            cout << "You have kept your -" << inventory.secondary_weapon << "-\n";
        }
    }
    
    else if (items[1] == 0)
    {
        items[1] = new_item_num;
        cout << "You have taken -" << new_item << "-\n";
        inventory.secondary_weapon = new_item;
    }

    if (items[2]>0)
    {
        cout << "You have -" << inventory.armour <<"- in your inventory\n";
        cout << "Would you like to swap it for -" << new_item << "-?\n";
        cout << "Yes (y)\nNo (n)\n";
        cin >> choice;
        choice = tolower(choice);

        if (choice == 'y')
        {
            cout << "You have swapped your -" << inventory.armour << "- for -" << new_item << "-\n";
            items[2] = new_item_num;
        }
        else if (choice == 'n')
        {
            cout << "You have kept your -" << inventory.armour << "-\n";
        }
    }
    
    else if (items[2] == 0)
    {
        items[2] = new_item_num;
        cout << "You have taken -" << new_item << "-\n";
        inventory.armour = new_item;
    }
    
}

Loot::Loot()
{

}

Loot::~Loot()
{

}

Loot::Loot(string x)
{  
    if (x == "Ch1"); // chest 1
    {
        loot_menu(1); // first loot menu
    }
}

void Loot::loot_menu(short y)
{
    Inventory inventory;
    if (y == 1)
    {
        char choice;
        cout << "Loot:\n-(Secondary) Sawed-off Shotgun\n-(Secondary) Revolver\n\n Inventory: Primary: " << inventory.primary_weapon << " Secondary: " << inventory.secondary_weapon << " Armour: "<< inventory.armour << "/" << inventory.INV_SLOT <<endl;
        cout << "\n\nTake:\n1. Sawed-off Shotgun (S)\n2. Revolver (R)\n3. Exit\n (E)\n";
        cin >> choice;
        choice = tolower(choice); 
        if (choice == 's')
        {
            new_item = "Sawed-off Shotgun";
            new_item_num = 2;
            check_inventory();
        }
        else if (choice == 'r')
        {
            new_item = "Revolver";
            new_item_num = 1;
            check_inventory();
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
