#pragma once

#include <iostream>
#include <conio.h>
#include "tiers.h"

using namespace std;

class Inventory;

class Player
{
private:
    Inventory* Inventory;

public:
};

class GunsNArmour
{
private:
    ItemTier tier;
    int damage;
    int ammo;
    int bonusHp;
    string gunName;

public:
    GunsNArmour(string gName, ItemTier tierValue, int damageValue, int ammoValue, int bonusHPValue)
    {
        gunName = gName;
        tier = tierValue;
        damage = damageValue;
        ammo = ammoValue;
        bonusHp = bonusHPValue;
    }
    int getDamage() { return damage; }
    int getAmmo() { return ammo; }
    int getBonusHp() { return bonusHp; }
    string getName() { return gunName; }
};

class Inventory
{
private:
    GunsNArmour **allGunsNArmour;
    int counter;

public:
    Inventory();
    ~Inventory();
    void take();
    GunsNArmour *items[2];
    GunsNArmour *getItem(int index); // add definition
};