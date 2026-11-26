#pragma once

class Health
{
private:
    int hp, xtraHp, baddyHp;
    int length;
    char healthChars, extraHealthChar;
    char hpBarCasingStart, hpBarCasingEnd, extraHpCasingStart, extraHpCasingEnd;
    char attackAreaCharacter;
    int x, y;

    void setHp(int hlth) { hp = hlth; }
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
    int getHp() { return hp; }
    int getXtraHp() { return xtraHp; }
    void showHp();
    void setXtraHp(int xtr) { xtraHp = xtr; }
    void addXtraHp(int xtr) { xtraHp += xtr; }
    void takeDamage(int damage);

    Health();
    ~Health();
};