#include <iostream>
#include <string>
#include <conio.h>

#include "loot.h"
#include "Player.h"

using namespace std;

// oc

Loot::~Loot()
{
}

Loot::Loot(string x, int y)
{
    Inventory inv;
    if (x == "Chest") // Loot menu for chests
    {
        if (y == 1) // Loot menu for chest 1
        {
            chest_menu(1, inv); // first loot menu
        }
        else if (y == 2) // Loot menu for chest 2 (just a placeholder for now, can be changed later)
        {
            //   loot_menu(2);  // (placeholder for now) second loot menu
        }
    }
}

void Loot::check_inventory(ItemTier tier)
{
    int checker;
    switch (tier)
    {
    }
}

void Loot::chest_menu(short y, Inventory& inv)
{
    if(y == 1)
    {
        std::cout << "What gun would you like?\n";
        std::cout << "1. " << "...";
        char choice = _getch();
        switch(choice)
        {
            case '1':
                inv.items[0] = inv.getItem(0);
                break;

            case '2':
                inv.items[1] = inv.getItem(1);
                break;

            default:
                break;
        }
    }
}

// will probably have to be reimplemented, however in a different form
//  void Loot::check_inventory(ItemTier tier)
//  {

//     int slot;
//     switch (tier)
//     {
//         case ItemTier::Primary:
//             slot = 0;
//             break;
//         case ItemTier::Secondary:
//             slot = 1;
//             break;
//         case ItemTier::Armour:
//             slot = 2;
//             break;
//         default:
//             return;
//     }

//     if (items[slot] != "Empty")
//     {
//         cout << "You have -" << items[slot] << "- in your inventory\n";
//         cout << "Would you like to swap it for -" << new_item << "-?\n";
//         cout << "Yes (y)\nNo (n)\n";

//         char choice;
//         cin >> choice;
//         choice = tolower(choice);

//         if (choice != 'y')
//         {
//             cout << "You have kept your -" << items[slot] << "-\n";
//             return;
//         }

//         cout << "You have swapped your -" << items[slot]
//              << "- for -" << new_item << "-\n";
//     }
//     else
//     {
//         cout << "You have taken -" << new_item << "-\n";
//     }

//     items[slot] = new_item;
// }

// From original loot system:
//  void Loot::chest_menu(short y)
//  {
//      if (y == 1)
//      {
//          char choice;
//          cout << "Loot:\n" << "-(Secondary) Sawed-off Shotgun\n-(Secondary) Revolver\n\n Inventory:\nPrimary: " << inv.items[0] << "\nSecondary: " << inv.items[1] << "\nArmour: "<< inv.items[2] <<endl;
//          cout << "\n\nTake:\n1. Sawed-off Shotgun (S)\n2. Revolver (R)\n3. Exit\n (E)\n";
//          cin >> choice;
//          choice = tolower(choice);
//          if (choice == 's')
//          {
//              SawedOff shotty;
//              new_item = "Sawed-off Shotgun";
//              new_item_num = 2;
//              check_inventory(shotty.tier);
//          }
//          else if (choice == 'r')
//          {
//              Revolver revolv;
//              new_item = "Revolver";
//              new_item_num = 1;
//              check_inventory(revolv.tier);
//          }
//          else if (choice == 'e')
//          {
//              cout << "You have exited the chest\n";
//          }
//      }
//      else if (y == 2)
//      {
//          //placeholder for loot menu 2 (chest 2)
//      }
//  }
