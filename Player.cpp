#include "Player.h"
    
Inventory::Inventory()
{
    allGunsNArmour = new GunsNArmour*[6]; //number can change idk how many guns we will need.

}

Inventory::~Inventory()
{
    for(int ctr = 0; ctr < 6; ctr++)
    {
        delete allGunsNArmour[ctr];
    }
    delete[] allGunsNArmour;
}

void Inventory::take(int gCount, int aCount)
{
    cout << "wanna take: " << allGunsNArmour[gCount]->getName() << endl;
    items[0] = allGunsNArmour[0];
    cout << "armour to take: " << allGunsNArmour[aCount]->getName() << endl;
    items[1] = allGunsNArmour[5];
}

GunsNArmour *Inventory::getItem(int index)
{
    return allGunsNArmour[index];
}


