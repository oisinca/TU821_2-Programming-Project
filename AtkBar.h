#pragma once

#include <iostream>
#include <windows.h>
#include <conio.h>

//oc
class AtkBar
{
private:
    int length;
    char blankSpots, cursor;
    char barCasingStart, barCasingEnd;
    char attackAreaCharacter;
    int x, y;
    int numberRuns;
    int barSpeed;


    void setBarLength(int lgth){length = lgth;};
    void setBlankSpots(char blank){blankSpots = blank;};  
    void setCursor(char cur){cursor = cur;};
    void setBarCasingStart(char casing){barCasingStart = casing;};
    void setBarCasingEnd(char casing){barCasingEnd = casing;};
    void setXY(int xPos, int yPos){x = xPos, y = yPos;};
    void setNumRuns(int num){numberRuns = num;};
    void setAttackChar(char figure){attackAreaCharacter = figure;};
    void createBar(HANDLE console);


public:
    AtkBar();
    ~AtkBar();

    int firstAttackPoint, secondAttackPoint;

    void randAttackArea();
    int getBarLength(){return length;};
    char getBlankSpots(){return blankSpots;};
    char getCursor(){return cursor;};
    char getBarCasingStart(){return barCasingStart;};
    char getBarCasingEnd(){return barCasingEnd;};
    int getX(){return x;};
    int getY(){return y;};
    int initAttkBar();
    int getNumRuns(){return numberRuns;};

    int getBarSpeed()
    {
        if (barSpeed<=0)
        {
            barSpeed = 1;
        }
        return barSpeed;};
        
    int getAttackPoint1(){return firstAttackPoint;};
    int getAttackPoint2(){return secondAttackPoint;};
    char getAttackChar(){return attackAreaCharacter;};
    void setBarSpeed(int spd){barSpeed = spd;};
    
    //both placeholders, must return damage in the future   
    int correctHit();
    int missedHit();
};