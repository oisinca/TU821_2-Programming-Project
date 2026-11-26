#include <iostream>
#include <windows.h>

#include "Enemy.h"
#include "Health.h"
#include "AtkBar.h"
#include "narrative.h"


int Enemy::turnBasedCombat()
{
    Narrative nar;
    AtkBar bar;
    Health myHp;
    int amo = 0;
    int strtAmo = 0;
    int dmg = 0;
    system("cls");
    nar.typingText("Entering Bossfight!\nKill",1);
    nar.typingText(getBaddyName(),1);
    nar.typingText("!",1);
    //will have to redo differently
    // if(inv.items[1] == "Revolver")
    // {
    //     Revolver rev;
    //     strtAmo = rev.ammo;
    //     amo = strtAmo;
    //     dmg = rev.damage;
    // }

//elseif(sg)
//elseif(otherGun)

    while (baddyHp>0)
    {
            nar.cont_clr();
            nar.typingText("What would you like to do?\n1. Shoot \n2. Reload\n3. Dodge",1);
            char choice = _getch();
            switch(choice)
            {
                case ('1'):
                if(amo == 0)
                {
                    system("cls");
                    nar.typingText("You must reload before you can shoot!\nReloading for you and skipping turn.",1);
                    //Make it reload;
                    choice = 2;
                }
                else
                {
                    system("cls");
                    nar.typingText("Shooting your \n",1);
                    //gun name here;
                    //will have to redo this also
                    ///nar.typingText(inv.items[1],1);
                    std::cout << "\n";
                    nar.typingText("You must hit Enter or Space-Bar in the attack bracket 3 times to deal damage!\nReady?\n",1);
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
                    
                    if (bar.initAttkBar() == 1)
                    {
                        amo--;
                        baddyHp = baddyHp - dmg;
                        //bad guys turn
                    }
                    else
                    {
                        //bad guys turn
                    }
                }
                break; 
                case ('2'):
                reload(&amo, &strtAmo);
                //end turn
                break;
                case('3'):
                nar.typingText("You dodge!",1);
                //dodge or somehting;
                break;
            }
        }
        //give good loot option
        nar.typingText("Congrats you killed ",5);
        std::cout << getBaddyName() <<"!";
    return 0;
}

Enemy::Enemy(int eHp, std::string name)
{
    setBaddyHp(eHp);
    setBaddyName(name);
    turnBasedCombat();
}
void Enemy::reload(int *ammos, int *maxAmmos)
{
    Narrative nar;
    if(*ammos == *maxAmmos)
    {
        nar.typingText("Your ammo is already full!",1);
        std::cout << *ammos << "/" << *maxAmmos << " ammo" << "\n";

    }
    else{
        std::cout << *ammos << "/" << *maxAmmos << " ammo" << "\n";
        *ammos = *maxAmmos;
        nar.typingText("Reloaded your ammo to full",1);
        std::cout << *ammos << "/" << *maxAmmos << " ammo" << "\n";
    }
}