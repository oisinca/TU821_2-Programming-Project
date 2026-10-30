#pragma once

#include <iostream>
#include <string>
using namespace std;

class Inventory{
private:

public:
    Inventory();
    ~Inventory();
    
    short const INV_SLOT = 3;
    string primary_weapon = "Empty";
    string secondary_weapon = "Empty";
    string armour = "Empty";

};