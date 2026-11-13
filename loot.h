#pragma once

#include <iostream>
#include <string>

#include "tiers.h"
#include "gunsNArmour.h"
using namespace std;

//oc

class Loot
{
private:
    string chest_num;
    string new_item;
    int new_item_num;
    void check_inventory(ItemTier tier);
    void chest_menu(short y); // 1 = chest 1 (starter chest), 2 = chest 2, 3 = chest 3...


public:
    Loot();
    ~Loot();
    Loot(string x, int y); // input type of looting menu, and what level its at eg chest 1, boss 2 etc. 
    short const INV_SLOT = 3;
    string items[3] = {"Empty","Empty","Empty"}; // 0 = empty, 1 = revolver, 2 = sawed-off shotgun

};