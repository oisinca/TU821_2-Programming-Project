#include <iostream>
#include <limits>

#include "game.h"
#include "narrative.h"
#include "Player.h"
#include "Enemy.h"
using namespace std;
// if you wanna look at the headers for each section
// look at the name of the .cpp, and find its corresponding .h file,
// they are in the same folder as the .cpp files

bool Game::Initl()
{
    manager.createPlaces(); // creates the 5 places when the game starts
    return true;
}

void Game::ProcInpts()
{
    // this sequence of code: if your in the settings or instructions,
    // press any key (character) to go back to the main menu

    if (currentState == Instructions || currentState == Settings)
    {
        char choice;
        if (cin >> choice)
        {
            currentState = MENU;
        }
        else
        {
            g_isRunning = false; // safely shuts down the game if something goes wrong
        }
        return;
    }

    if (currentState == MENU)
    {
        // in the menu if the user types letters instead of numbers
        int choice = 0;
        if (!(cin >> choice))
        {
            cin.clear();                                         // reset cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear previous inputs
            cout << "\nInvalid input: Please choose 1, 2, 3 or 4 " << endl;
            return; // goes back to the start of the loop
        }

        switch (choice)
        {
        case 1:
            currentState = Play;
            break;
        case 2:
            currentState = Instructions;
            break;
        case 3:
            currentState = Settings;
            break;
        case 4:
            currentState = Exit;
            g_isRunning = false;
            break;
        case 0:
            currentState = DEVSKIPPER;
            break;
        default: // like an "else" handles all invalid NUMBER inputs.
            cout << "\nInvalid choice: Please choose 1, 2, 3 or 4";
            break;
        }
    }
}

void Game::Update()
{
    // placeholder for updating game state, not sure if this will be used in the final version of the game,
    // but it is here just in case
}

void Game::Draw()
{
    // draws the game,
    //(its just a text based game so it will be mostly cout statements ie from narative.cpp)
    // GAME MENU
    if (currentState == MENU)
    {
        cout << "****MAIN MENU****" << endl;
        cout << "(1) Play " << endl;
        cout << "(2) Instructions" << endl;
        cout << "(3) Settings" << endl;
        cout << "(4) Exit" << endl;
        // use 0 to skip to a developer part
    }
    else if (currentState == Play) // once character selected??
    {
        Inventory inventory;
        Narrative narrate;
        startAdventure(); //starts the game
    }
    else if (currentState == Instructions)
    {
        cout << "****INSTRUCTIONS****" << endl;
        cout << "This is a text based adventure game where you are given different options to choose from." << endl;
        cout << "Press the key thats presented beside the option you want to chose and press Enter to proceed. " << endl;
        cout << "To return to main menu, press any key and Enter. " << endl;
        // placeholder
    }
    else if (currentState == Settings)
    {
        cout << "Settings are not available yet." << endl;
        cout << "Press any key and Enter to return to the menu." << endl;
        // placeholder
    }
    else if (currentState == DEVSKIPPER)
    {
        // put place to skip to with developer mode here
        //  inv.items[1] = "Revolver";
        Inventory inv;
        inv.take();
    }
}

void Game::startAdventure()
{
    // HOME
    Place currentPlace = manager.getPlace(0);
    currentPlace.displayPlace();
    story.homeDialougue();

    // BAR
    currentPlace = manager.getPlace(1);
    currentPlace.displayPlace();
    story.barDialogue();

    // SHTICKS
    currentPlace = manager.getPlace(2);
    currentPlace.displayPlace();
    story.shticksDialogue();
    
    // CHURCH
    currentPlace = manager.getPlace(3);
    currentPlace.displayPlace();
    story.churchDialogue();

    // CAVE
    currentPlace = manager.getPlace(4);
    currentPlace.displayPlace();
    story.caveDialogue();
}

Game::Game()
    : g_isRunning{true} // initialize game state to running by setting g_isRunning to true
{
    currentState = MENU; // starts game at the menu
}

Game::~Game()
{
}

void Game::Run()
{
    if (!Initl()) // if the game fails to initialize, return and end the game
    {
        return;
    }

    while (g_isRunning)
    {
        Draw();

        if (currentState == Play || currentState == DEVSKIPPER)
        {

            currentState = MENU;
            continue;
        }

        ProcInpts();
    }
}
