#pragma once

#include <iostream>
#include <string>

#include "tiers.h"
using namespace std;

// inventory is used through a reference by Loot.
class Inventory;

class Loot
{
private:
    string chest_num;
    string new_item;
    int new_item_num;
    bool check_inventory_empty(short x, Inventory &inv);

public:
    ~Loot();
    Loot(); // input type of looting menu, and what level its at eg chest 1, boss 2 etc.
    void chest_menu(short x, short y, Inventory &inv); // y & x = gun to be input, 2 = chest 2, 3 = chest 3...
};