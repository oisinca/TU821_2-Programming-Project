#pragma once
  
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
  
//Goal:
//Give a gun or armour, play a game, chance to win a 
//better weapon or armour (depends on input), 
//or to lose it all.
// possible issues: 
//         can only input a gun or weapon as no money system
//         has been implemented. User will likely only have 1
//         weapon, so if they lose it game will not be fun.
// solutions?:
//         could be fixed by rigging in users favour.
//         or could give pitty prize for losing (crap gun).
// would be good if prize scales by items value... better gun
// means better reward.
//Idea:
//  heads or tails (easy to make, ideally make small animation)
//  would generate randint(1,2), 1=heads, 2=tails
//  Animation: _ -> \ -> | - > / - > _ 
  
class HeadsOrTails
{
  
private:
    std::string result;
    int x, y;
    int delay;
    std::string choice;
    void hideCurs();
    void showCurs();
    void setXY(int xpos, int ypos){x = xpos, y = ypos;}
    void setDelay(int del){delay = del;}
    int getX(){return x;}
    int getY(){return y;}
    void gamble(HANDLE &handle, COORD &pos);
    void gnrtHRT();
    int getDelay(){return delay;}
  
public:
    HeadsOrTails();
    ~HeadsOrTails();
    void flipAnimate();
  
};