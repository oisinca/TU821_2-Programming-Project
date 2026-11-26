#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

#include "narrative.h"
#include "loot.h"
#include "AtkBar.h"
#include "PlaceManager.h"

enum GameState
{
    MENU,
    Play,
    Settings,
    Instructions,
    Exit,
    DEVSKIPPER,
};

class Game
{
private:
    bool g_isRunning;

    bool Initl();

    void ProcInpts();
    void Update();
    void Draw();
    GameState currentState;

    // game objects
    Narrative story;      // creates a narrative object belonging to game
    PlaceManager manager; // creates a placemanager object belonging to game

    // starts the game
    void startAdventure(); // controls the progression through the locations

public:
    Game();
    ~Game();

    void Run();
};
