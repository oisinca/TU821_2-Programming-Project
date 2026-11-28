#pragma once

#include <iostream>
#include <conio.h>
#include "tiers.h"

using namespace std;

class Inventory;

class Player
{
private:
    Inventory *Inventory;

    int hp;
    int xtraHp;

public:

    Player();
    ~Player();

    int getHp() { return hp; }
    void setHp(int hlth) { hp = hlth; }

    int getXtraHp() { return xtraHp; }
    void setXtraHp(int xtr) { xtraHp = xtr; }
    
    void addXtraHp(int xtr) { xtraHp += xtr; }
    
    void takeDamage(int damage); // may not need this...
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
    ItemTier getTier() {return tier;}
};

class Inventory
{
private:
    GunsNArmour **allGunsNArmour;
    int counter;

public:
    Inventory();
    ~Inventory();
    void take(int gunTake, int gOrA);
    GunsNArmour *items[2];
    GunsNArmour *getItem(int index); // add definition
};