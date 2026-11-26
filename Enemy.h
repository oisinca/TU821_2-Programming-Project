#pragma once

#include "Health.h"

class Inventory;

class Enemy
{
private:
    int turnBasedCombat(Inventory &inventory);
    int baddyHp;
    std::string baddysName;
    void setBaddyHp(int hp) { baddyHp = hp; }
    void setBaddyName(std::string name) { baddysName = name; }
    void baddysGo(){}
public:
    Enemy(int eHp, std::string name, Inventory &inventory);
    int getBaddyHp() { return baddyHp; }
    std::string getBaddyName() { return baddysName; }
    void reload(int *ammos, int maxAmmos);
};