#include "HeadsOrTails.h"

void HeadsOrTails::flipAnimate()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    gamble(handle, pos);
    gnrtHRT();
    hideCurs();

    pos.X = getX();
    pos.Y = getY()-5;
    SetConsoleCursorPosition(handle,pos);
    std::cout << "\nBeginning Flip... ";
    Sleep(100);

    pos.Y = getY();
    SetConsoleCursorPosition(handle,pos);
    std::cout << "_";
    SetConsoleCursorPosition(handle,pos);
    Sleep(getDelay());
    std::cout << "      ";

    pos.Y--;
    pos.X++;
    SetConsoleCursorPosition(handle,pos);
    std::cout << "\\";
    SetConsoleCursorPosition(handle,pos);
    Sleep(getDelay());
    std::cout << "      ";

    pos.X++;
    pos.X++;
    pos.Y--;
    SetConsoleCursorPosition(handle,pos);
    std::cout << "|";

    for(int i = 0; i<3; i++)
    {
        getDelay();
        Sleep(getDelay());
        SetConsoleCursorPosition(handle,pos);
        std::cout << "/";
        Sleep(getDelay());
        SetConsoleCursorPosition(handle,pos);
        std::cout<< "-";
        Sleep(getDelay());
        SetConsoleCursorPosition(handle,pos);
        std::cout << "\\";
        Sleep(getDelay());
        SetConsoleCursorPosition(handle,pos);
        std::cout << "|";
    }
    
    Sleep(getDelay());
    SetConsoleCursorPosition(handle,pos);
    std::cout << "      ";

    pos.Y++;
    SetConsoleCursorPosition(handle,pos);
    std::cout << "  /";
    SetConsoleCursorPosition(handle,pos);
    Sleep(getDelay());
    std::cout << "      ";

    pos.Y++;
    pos.X++;
    SetConsoleCursorPosition(handle,pos);
    std::cout << "  _";
    Sleep(100);
    std::cout << " .";
    Sleep(100);
    std::cout << ".";
    Sleep(100);
    std::cout << ".";
    Sleep(500);
    std::cout << " " << result;
    if (result == choice)
        std::cout << "! Congrats!";
    else
        std::cout << " :( Unlucky";
    showCurs();
    int stop;
    std::cin >> stop;
    if (stop == 0)
        return;
}

void HeadsOrTails::gamble(HANDLE &handle, COORD &pos)
{
    pos.X = getX();
    pos.Y = getY()-9;
    SetConsoleCursorPosition(handle,pos); 
    std::cout << "Pick: \n(1)Heads\n(2)Tails\n";
    char key = _getch();
    switch(key)
    {
    case(49):
        choice = "Heads";
        std::cout << choice;
        break;
    case(50):
        choice = "Tails";
        std::cout << choice;
        break;
    default:
        std::cout << "You must enter either 1, or 2.\nPlease retry :)";
        system("pause");
        system("cls");
        gamble(handle, pos);
    }
}

void HeadsOrTails::gnrtHRT()

{
    int HRT = rand() %2; 
    if(HRT == 1)
        result = "Heads";
    else   
        result = "Tails";
}

void HeadsOrTails::hideCurs()
{
    ShowCursor(false);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo{};
    GetConsoleCursorInfo(handle, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(handle, &cursorInfo);
}

void HeadsOrTails::showCurs()
{
    ShowCursor(true);
}

HeadsOrTails::HeadsOrTails()
{
    setXY(0,10);
    setDelay(100);
}

HeadsOrTails::~HeadsOrTails(){}
