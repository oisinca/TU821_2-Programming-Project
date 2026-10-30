#pragma once

#include <iostream>
#include <string>


using namespace std;

class Loot
{
private:
    string chest_num;

    string new_item;
    int new_item_num;
    void check_inventory();


public:
    Loot();
    ~Loot();
    Loot(string x);

    int items[3] = {0,0,0}; // 0 = empty, 1 = revolver, 2 = sawed-off shotgun
    void loot_menu(short y); // 1 = chest 1 (starter chest), 2 = chest 2, 3 = chest 3...
};