#pragma once

class HealthBar
{
private:
    int length;
    char healthChars, extraHealthChar;
    char hpBarCasingStart, hpBarCasingEnd, extraHpCasingStart, extraHpCasingEnd;
    char attackAreaCharacter;
    int x, y;

    void setHpBarLgth(int lgth) { length = lgth; }
    void setHpChar(char blank) { healthChars = blank; }
    void setHpBarCasStrt(char casing) { hpBarCasingStart = casing; }
    void setHpBarCasEnd(char casing) { hpBarCasingEnd = casing; }
    void setXY(int xPos, int yPos) { x = xPos, y = yPos; }
    void setXtrHpChar(char extra) { extraHealthChar = extra; }
    void setXtrHpCasStrt(char extra) { extraHpCasingStart = extra; }
    void setXtrHpCasEnd(char extra) { extraHpCasingEnd = extra; }

    int getHpBarLgth() { return length; }
    char getHealthChar() { return healthChars; }
    char getHpBarCasStrt() { return hpBarCasingStart; }
    char getHpBarCasEnd() { return hpBarCasingEnd; }
    char getXtrHpCasStrt() { return extraHpCasingEnd; }
    char getXtrHpCasEnd() { return extraHpCasingEnd; }
    char getXtrHpChar() { return extraHealthChar; }
    int getX() { return x; }
    int getY() { return y; }

public:

    void showHp();
    HealthBar();
    ~HealthBar();
};