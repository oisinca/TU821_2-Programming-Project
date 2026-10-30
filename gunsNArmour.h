#pragma once

enum class ItemTier {
    Primary,
    Secondary,
    Armour
};

class GunsNArmour {
public:
    ItemTier tier;
    int damage;
    int ammo;
    int bonusHP;
    int extraStorage; // Added extraStorage member variable

    GunsNArmour(ItemTier tierValue, int damageValue, int ammoValue, int bonusHPValue, int extraStorageValue = 0)
        : tier{tierValue},
          damage{damageValue},
          ammo{ammoValue},
          bonusHP{bonusHPValue},
          extraStorage{extraStorageValue} {} // Initialize extraStorage in the constructor
};  

class Revolver : public GunsNArmour {
public:
    Revolver() : GunsNArmour{ItemTier::Secondary, 2, 6, 0, 0} {}
};

class SawedOff : public GunsNArmour {
public:
    SawedOff() : GunsNArmour{ItemTier::Primary, 5, 2, 0, 0} {}
};

class leatherJacket : public GunsNArmour {
public: 
    leatherJacket() : GunsNArmour{ItemTier::Armour, 0, 0, 5, 1} {}
};