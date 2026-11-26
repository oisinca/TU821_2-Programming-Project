#include "Health.h"

Health::Health()
{
    setHp(3); // sets hp at start of game to 3
    setXtraHp(0);
    setHpBarCasStrt('[');
    setHpBarCasEnd(']');
    setHpBarLgth(3);
    setHpChar('#');
    setXtrHpCasStrt('{');
    setXtrHpCasEnd('}');
    setXtrHpChar('+');
    setXY(20, 1);
}

Health::~Health() = default;

void Health::takeDamage(int damage)
{
    if (damage <= 0)
    {
        return;
    }

    int absorbedDamage = xtraHp;
    if (damage < xtraHp)
    {
        absorbedDamage = damage;
    }
    xtraHp -= absorbedDamage;
    hp -= damage - absorbedDamage;

    if (hp < 0)
    {
        hp = 0;
        // run end screen here.
    }
}

void Health::showHp()
{
    // must show Health points: [###], each # is a health point, extra heath/armour: [###]{++}
}
