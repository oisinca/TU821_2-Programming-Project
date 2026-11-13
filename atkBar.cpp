#include "AtkBar.h"

//oc
int AtkBar::initAttkBar()
{
    system("pause");
    getBarLength();
    getBlankSpots();
    getCursor();
    
// to hide cursor
    ShowCursor(false);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo{};
    GetConsoleCursorInfo(handle, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(handle, &cursorInfo);

//setting start and end brackets
    COORD pos;
    createBar(handle);
 

//setting first direction to 1, and resetting cursor position to the start
    pos.X = getX();
    pos.Y = getY();
    SetConsoleCursorPosition(handle, pos);
    int dir = -1;

//print cursor going right
    for (int j = 0; j < getNumRuns(); j++)
    {    
    if(dir == 1) 
    {
        for (int i = 0; i <= getBarLength(); i++)
        {  
            pos.X = getX() + i;
            SetConsoleCursorPosition(handle,pos);
            std::cout << getCursor();
            Sleep(getBarSpeed());
            if(_kbhit())
            {
                int key = _getch();
                 if((key == '\r'|| key == ' ') && (pos.X == (firstAttackPoint)+1 || pos.X == (firstAttackPoint)+2))
                 {
                    system("cls");
                    std::cout<<"YOU CLICKED CORRECT!\n";
                    system("pause");
                    return 0;
                }
                else if ((key == '\r'|| key == ' ') && (pos.X != (firstAttackPoint)+1 && pos.X != (firstAttackPoint)+2))
                {
                    system("cls");
                    setBarSpeed(getBarSpeed()-10);
                    std::cout << "MISSED!\nSpeed Increased!\n";
                    system("pause");
                    system("cls");
                    createBar(handle);
                    continue;
                }
            }
            SetConsoleCursorPosition(handle, pos);
            std::cout << getBlankSpots();
        }
        dir = -1;
    }

//print cursor going left    
    else if (dir == -1)
    {
        for (int i = getBarLength()-1; i > 1; i--)
        {   
            pos.X = getX() + i;
            SetConsoleCursorPosition(handle,pos);
            std::cout << getCursor();
            Sleep(getBarSpeed());
            if(_kbhit())
            {
                int key = _getch();
                 if((key == '\r'|| key == ' ') && (pos.X == (firstAttackPoint)+1 || pos.X == (firstAttackPoint)+2))
                 {
                    system("cls");
                    std::cout<<"YOU CLICKED CORRECT!\n";
                    system("pause");
                    return 0;
                        }
                else if ((key == '\r'|| key == ' ') && (pos.X != (firstAttackPoint)+1 || pos.X != (firstAttackPoint)+2))
                {
                    system("cls");
                    setBarSpeed(getBarSpeed()-10);
                    std::cout << "MISSED!\nSpeed Increased!\n";
                    system("pause");
                    system("cls");
                    createBar(handle);
                    continue;
                }
            }
            SetConsoleCursorPosition(handle, pos);
            std::cout << getBlankSpots();
        } 
        dir = 1;
        }
    }
    return 0;
}

void AtkBar::createBar(HANDLE handle)
{
COORD pos;

    pos.X = getX() - 1;
    pos.Y = getY();
    SetConsoleCursorPosition(handle, pos);
    std::cout << getBarCasingStart();
    pos.X = getX() + getBarLength() + 1;
    SetConsoleCursorPosition(handle, pos);
    std::cout << getBarCasingEnd();

    randAttackArea();
    pos.X = getAttackPoint1();
    pos.Y = getY() + 1;
    SetConsoleCursorPosition(handle, pos);
    std::cout << getAttackChar();
    pos.X = getAttackPoint2();
    SetConsoleCursorPosition(handle, pos);
    std::cout << getAttackChar();
    pos.Y = getY();

//generate all blanks before generating cursor
    for (int i = 0; i <= getBarLength(); i++)
    {
        pos.X = getX() + i;
        SetConsoleCursorPosition(handle, pos);
        std::cout << getBlankSpots();
    }
}

void AtkBar::randAttackArea()
{
    firstAttackPoint = rand() %6 + 1;
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
    setXY(1,1);
    setNumRuns(100);
    setBarSpeed(60);
}

AtkBar::~AtkBar()
{
}