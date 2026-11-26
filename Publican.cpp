#include <conio.h>

#include "HeadsOrTails.h"
#include "Publican.h"
#include "loot.h"
#include "AtkBar.h"
#include "narrative.h"

Publican::Publican() = default;

Publican::~Publican() = default;

void Publican::pubText()
{
    Narrative nar;
    nar.typingText("The Bar smells like a mixture cigarettes, gunpowder and cheap alcohol.", 5);
    nar.cont_clr();
    nar.typingText("You hear shouting in the back of the bar.", 5);
    nar.cont_clr();
    nar.typingText("Path Option: \n", 1);
    nar.typingText("Would you like to:", 1);
    nar.typingText("1. Go outside and investigate", 1);
    nar.typingText("2. Go get a drink at the bar", 1);
    char key;
    do
    {
        key = _getch();
        switch (key)
        {
        case '1':
            investigateOutside();
            break;
        case '2':
            goToBar();
            break;
        default:
            std::cout << key << " is invalid, Please try again.";
            nar.cont_clr();
        }
    } while (key != '1' && key != '2');
}

void Publican::goToBar()
{
    bartenderConv();
}

void Publican::investigateOutside()
{
    std::cout << "Working.. outside now\n";
}

std::string Publican::bartenderConv()
{
    Narrative nar;
    nar.typingText("Welcome!\nWhat would you like to order?\n", 5);
    nar.typingText("MENU:\n1. ", 1);
    return std::string();
}
