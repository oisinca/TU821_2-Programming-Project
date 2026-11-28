#include "HealthBar.h"

HealthBar::HealthBar()
{
    setHpBarCasStrt('[');
    setHpBarCasEnd(']');
    setHpBarLgth(3);
    setHpChar('#');
    setXtrHpCasStrt('{');
    setXtrHpCasEnd('}');
    setXtrHpChar('+');
    setXY(20, 1);
}

HealthBar::~HealthBar() = default;



void HealthBar::showHp()
{
    // must show HealthBar points: [###], each # is a health point, extra heath/armour: [###]{++}
}
