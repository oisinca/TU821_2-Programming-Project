#pragma once

#include <iostream>
#include <string>

#include "HeadsOrTails.h"

class Publican
{
private:
    void goToBar();
    void investigateOutside();
    std::string bartenderConv();

public:
    std::string drink;
    int lockedLvl;

    Publican();
    ~Publican();
    Publican(int lkd, int dmg)
    {
        lockedLvl = lkd;
    }
    void pubText();
};

class shot : public Publican
{
};