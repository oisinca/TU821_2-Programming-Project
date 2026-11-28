#pragma once

#include "HealthBar.h"

class Inventory;

class Enemy
{
private:
    int difclty;
    int turnBasedCombat(Inventory &inventory);
    int baddyHp;
    std::string baddysName;
    void setBaddyHp(int hp) { baddyHp = hp; }
    void setBaddyName(std::string name) { baddysName = name; }
    void baddysGo(int dif);
public:
    void setDifficulty(int dif){difclty = dif;} // lower number is harder!, 1 will mean baddy will always damage...
    int getDifficulty(){return difclty;}
    Enemy(int eHp, std::string name, int difficulty, Inventory &inventory);
    int getBaddyHp() { return baddyHp; }
    std::string getBaddyName() { return baddysName; }
    void reload(int *ammos, int maxAmmos);
};