#include <iostream>
#include <string>
#include <conio.h>

#include "loot.h"
#include "Player.h"
#include "narrative.h"

// oc

Loot::~Loot()
{
}

Loot::Loot()
{
}

bool Loot::check_inventory_empty(short x, Inventory &inv)
{

    if (inv.items[x] == NULL)
        return true;

    return false;
}

void Loot::chest_menu(short x, short y, Inventory &inv)
// pass in any int for x and y depending on what gun or armour
// you need (look at default Inventory Constructor), and put inv in
//... syntax: object.chest_meu(0,5,inv);

{
    int g; // for checking what type of item it is
    int h; // checking same as above, for second input weapon
           // if we add consumables, repeat the if below for
           //  ItemTier::Consumable; eg... else {g = 2} // else {h = 2}
    if (inv.getItem(x)->getTier() == ItemTier::Gun)
        g = 0;
    else if (inv.getItem(x)->getTier() == ItemTier::Armour)
        g = 1;

    if (inv.getItem(y)->getTier() == ItemTier::Gun)
        h = 0;
    else if (inv.getItem(y)->getTier() == ItemTier::Armour)
        h = 1;

    Narrative nar;

    nar.typingText("What gun would you like?\n", 1);
    nar.typingText("1. ", 1);
    nar.typingText(inv.getItem(x)->getName(), 1);
    std::cout << "\n";

    nar.typingText("2. ", 1);
    nar.typingText(inv.getItem(y)->getName(), 1);
    std::cout << "\n";

    char choice = _getch();

    switch (choice)
    {
    case '1': // taking option x
        if (check_inventory_empty(x, inv))
            inv.take(x, 0); // take gun (revolver = 0), for slot 0
        else
        {
            nar.typingText("You already have a ", 1);
            nar.typingText(inv.items[g]->getName(), 1);
            nar.typingText(" in your inventory, would you like to swap it for ", 1);
            nar.typingText(inv.getItem(x)->getName(), 1);
            std::cout << "\n";
        }
        break;

    case '2': // taking option y
        if (check_inventory_empty(y, inv))
            inv.take(y, 0); // take gun (revolver = 0), for slot 0
        else
        {
        nar.typingText("You already have a", 1);
        nar.typingText(inv.items[h]->getName(), 1);
        nar.typingText(" in your inventory, would you like to swap it for ", 1);
        nar.typingText(inv.getItem(y)->getName(), 1);
        }   
        break;

    default:
        break;
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
