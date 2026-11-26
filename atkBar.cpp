#include "AtkBar.h"

// oc
bool AtkBar::initAttkBar()
{
    // to hide cursor
    ShowCursor(false);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo{};
    GetConsoleCursorInfo(handle, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(handle, &cursorInfo);
    // setting start and end brackets

    createBar(handle);
    gotoXY(getX(), getY());
    // setting first direction to 1, and rtn to false
    bool rtn = false;
    int dir = 1;

    setNumRuns(3);
    setBarSpeed(60);

    // print cursor going right
    for (numberRuns; numberRuns > 0;)
    {
        if (dir == 1)
        {
            for (int i = 0; i <= getBarLength(); i++)
            {
                gotoXY(getX() + i, getY());
                std::cout << getCursor();
                Sleep(getBarSpeed());
                if (_kbhit())
                {
                    int key = _getch();
                    if ((key == '\r' || key == ' ') && (getX() + i == firstAttackPoint || getX() + i == secondAttackPoint || getX() + i == (firstAttackPoint) + 1 || getX() + i == (secondAttackPoint)-1))
                    {
                        system("cls");
                        setBarSpeed(getBarSpeed() - 10);
                        numberRuns = numberRuns - 1;
                        std::cout << "HIT!\n"
                                  << numberRuns << " more hits until you deal damage.";
                        system("pause");
                        system("cls");
                        if (numberRuns != 0)
                        {
                            createBar(handle);
                            continue;
                        }
                        gotoXY(0, 0);
                        rtn = true;
                        return rtn;
                    }
                    else
                    {
                        system("cls");
                        std::cout << "MISSED!\nTurn forfited.\n";
                        system("pause");
                        system("cls");
                        rtn = false;
                        return rtn;
                    }
                }
                gotoXY(getX() + i, getY());
                std::cout << getBlankSpots();
            }
            dir = -1;
        }

        // print cursor going left
        else if (dir == -1)
        {
            for (int i = getBarLength() - 1; i > 0; i--)
            {
                gotoXY(getX() + i, getY());
                std::cout << getCursor();
                Sleep(getBarSpeed());
                if (_kbhit())
                {
                    int key = _getch();
                    if ((key == '\r' || key == ' ') && (getX() + i == firstAttackPoint || getX() + i == secondAttackPoint || getX() + i == (firstAttackPoint) + 1 || getX() + i == (secondAttackPoint)-1))
                    {
                        system("cls");
                        setBarSpeed(getBarSpeed() - 10);
                        numberRuns = numberRuns - 1;
                        std::cout << "HIT!\n"
                                  << numberRuns << " more hits until you deal damage.";
                        system("pause");
                        system("cls");
                        if (numberRuns != 0)
                        {
                            createBar(handle);
                            continue;
                        }
                        gotoXY(0, 0);
                        rtn = true;
                        return rtn;
                    }
                    else
                    {
                        system("cls");
                        std::cout << "MISSED!\nTurn forfitted.\n";
                        system("pause");
                        system("cls");
                        rtn = false;
                        return rtn;
                    }
                }
                gotoXY(getX() + i, getY());
                std::cout << getBlankSpots();
            }
            dir = 1;
        }
    }
    gotoXY(0, 0);
    rtn = true;
    return rtn;
}

void AtkBar::createBar(HANDLE handle)
{
    gotoXY(getX() - 1, getY());
    std::cout << getBarCasingStart();
    gotoXY(getX() + getBarLength() + 1, getY());
    std::cout << getBarCasingEnd();

    randAttackArea();
    gotoXY(getAttackPoint1(), getY() + 1);
    std::cout << getAttackChar();
    gotoXY(getAttackPoint2(), getY() + 1);
    std::cout << getAttackChar();

    // generate all blanks before generating cursor
    for (int i = 0; i <= getBarLength(); i++)
    {
        gotoXY(getX() + i, getY());
        std::cout << getBlankSpots();
    }
}

void AtkBar::randAttackArea()
{
    firstAttackPoint = rand() % 6 + 1;
    secondAttackPoint = firstAttackPoint + 3;
}

AtkBar::AtkBar()
{
    setBarLength(10);
    setBlankSpots('_');
    setCursor('V');
    setBarCasingStart('[');
    setBarCasingEnd(']');
    setAttackChar('^');
    setXY(1, 1);
}

AtkBar::~AtkBar()
{
}