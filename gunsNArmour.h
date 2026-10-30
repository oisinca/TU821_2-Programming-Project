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

    GunsNArmour(ItemTier tierValue, int damageValue, int ammoValue, int bonusHPValue)
        : tier{tierValue},
          damage{damageValue},
          ammo{ammoValue},
          bonusHP{bonusHPValue} {}
};

class Revolver : public GunsNArmour {
public:
    Revolver() : GunsNArmour{ItemTier::Secondary, 2, 6, 0} {}
};
