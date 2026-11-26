#include <iostream>
#include <windows.h>

#include "Enemy.h"
#include "Health.h"
#include "AtkBar.h"
#include "narrative.h"
#include "Player.h"
int Enemy::turnBasedCombat(Inventory &inventory)
{
    Narrative nar;
    AtkBar bar;
    Health myHp;

    // creating local ammo and damage.
    // creating starting ammo (stays constant once set at start of combat) to reload with later.
    int amo = 0;
    int strtAmo = 0;
    int dmg = 0;
    system("cls");

    nar.typingText("Entering Bossfight!\nKill ", 1);
    nar.typingText(getBaddyName(), 1);
    nar.typingText("!\n", 1);
    nar.typingText("They have ",1);
    std::cout << getBaddyHp();
    nar.typingText(" hp.",1);

    GunsNArmour *weapon = inventory.items[0];
    if (weapon == nullptr)
    {
        nar.typingText("\nYou need to select a weapon before fighting!\n", 1);
        return -1;
    }

    amo = weapon->getAmmo();
    strtAmo = amo;
    dmg = weapon->getDamage();

    // can add healthbar etc later, and also armour...
    // and consumable...
    nar.cont_clr();
    while (baddyHp > 0)
    {
        nar.typingText("What would you like to do?\n1. Shoot \n2. Reload\n3. Dodge", 1);
        // Dodge will probably be changed to use consumable...
        char choice = _getch();
        switch (choice)
        {
        case ('1'):
            if (amo == 0)
            {
                system("cls");
                nar.typingText("You must reload before you can shoot!\nReloading for you and skipping turn.", 1);
                reload(&amo, strtAmo);
                choice = 2;
            }
            else
            {
                system("cls");
                nar.typingText("Shooting your ", 1);
                nar.typingText(weapon->getName(), 1);
                std::cout << "\n";
                nar.typingText("You must hit Enter or Space-Bar in the attack bracket 3 times to deal damage!\nGet ready!\n", 1);
                nar.cont_clr();
                std::cout << "3, ";
                Sleep(1000);
                std::cout << "2, ";
                Sleep(1000);
                std::cout << "1, ";
                Sleep(1000);
                std::cout << "Begin!";
                Sleep(1000);
                system("cls");

                if (bar.initAttkBar())
                {
                    amo--;
                    baddyHp = baddyHp - dmg;
                    if (baddyHp < 0)
                        baddyHp = 0;
                    nar.typingText("You dealt ", 1);
                    std::cout << dmg;
                    nar.typingText(" damage to ", 1);
                    nar.typingText(getBaddyName(), 1);
                    nar.typingText(", they are now on ", 1);
                    std::cout << baddyHp;
                    nar.typingText(" hp", 1);
                    nar.cont_clr();
                    // bad guys turn
                }
                else
                {
                    // bad guys turn
                }
            }
            break;
        case ('2'):
            if (amo == strtAmo)
            {
                nar.typingText("\nYour ammo is already full!\n", 1);
                std::cout << amo << "/" << strtAmo << " ammo" << "\n";
                continue;
            }
            reload(&amo, strtAmo);
            // put bad guys turn function here
            break;
        case ('3'):
            nar.typingText("\nYou dodge!\n", 1);
            // dodge or somehting;
            break;
        }
    }
    // give good loot option
    nar.typingText("\nCongrats you killed ", 5);
    std::cout << getBaddyName() << "!" << std::endl;
    return 0;
}

Enemy::Enemy(int eHp, std::string name, Inventory &inventory)
{
    setBaddyHp(eHp);
    setBaddyName(name);
    turnBasedCombat(inventory);
}
void Enemy::reload(int *ammos, int maxAmmos)
{
    Narrative nar;
    std::cout << std::endl;
    std::cout << *ammos << "/" << maxAmmos << " ammo" << "\n";
    *ammos = maxAmmos;
    nar.typingText("Has been reloaded to full \n", 1);
    std::cout << *ammos << "/" << maxAmmos << " ammo" << "\n";
}