#include "Player.h"

Inventory::Inventory()
{
    allGunsNArmour = new GunsNArmour *[6];                                   // number can change idk how many guns we will need.
    allGunsNArmour[0] = new GunsNArmour("Revolver", ItemTier::Gun, 2, 6, 0); // name, damage, ammo, extrahp.
    allGunsNArmour[1] = new GunsNArmour("Shotgun", ItemTier::Gun, 10, 2, 0);
    allGunsNArmour[2] = new GunsNArmour("Platinum Deagle", ItemTier::Gun, 8, 7, 0);
    allGunsNArmour[3] = new GunsNArmour("Holy Bible", ItemTier::Gun, 100, 100, 3);
    allGunsNArmour[4] = new GunsNArmour("AK-47", ItemTier::Gun, 3, 30, 0);
    allGunsNArmour[5] = new GunsNArmour("Leather Jacket", ItemTier::Armour, 0, 0, 2);
    items[0] = nullptr;
    items[1] = nullptr;
}

Inventory::~Inventory()
{
    for (int ctr = 0; ctr < 6; ctr++)
    {
        delete allGunsNArmour[ctr];
    }
    delete[] allGunsNArmour;
}

void Inventory::take(int gunTake, int gOrA)
{
    cout << "taking " << allGunsNArmour[gunTake]->getName() << endl;
    items[gOrA] = allGunsNArmour[gunTake];
}

GunsNArmour *Inventory::getItem(int index)
{
    return allGunsNArmour[index];
}
