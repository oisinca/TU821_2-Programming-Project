#pragma once

#include <iostream>
#include <string>

#include "tiers.h"
using namespace std;

// Inventory is used through a reference by Loot.
class Inventory;

class Loot
{
private:
    string chest_num;
    string new_item;
    int new_item_num;
    void check_inventory(ItemTier tier);
    void chest_menu(short y, Inventory& inv); // 1 = chest 1 (starter chest), 2 = chest 2, 3 = chest 3...

public:
    ~Loot();
    Loot(string x, int y); // input type of looting menu, and what level its at eg chest 1, boss 2 etc. 
    short const INV_SLOT = 3;
    

};