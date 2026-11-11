#include "game.h"
#include "narrative.h"
#include <iostream>
#include <limits>

using namespace std;
//if you wanna look at the headers for each section
//look at the name of the .cpp, and find its corresponding .h file, 
//they are in the same folder as the .cpp files

bool Game::Initl()
{
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
        // in the menu if the user types letters instead of numbers(error checking)
        char key = _getch();
       do{
            if (key != 49 && key != 50 && key != 51 && key != 52)
            {
                cerr << "Invalid input entered.\nPlease try again.\n ";
            }

            switch(key)
            {
            case 49:
                currentState = Play;
                break;
            case 50:
                currentState = Instructions;
                break;
            case 51:
                currentState = Settings;
                break;
            case 52:
                currentState = Exit;
                g_isRunning = false;
                break;
        }
        }while(key != 49 && key != 50 && key != 51 && key != 52);
       
    }


}

void Game::Update()
{
//placeholder for updating game state, not sure if this will be used in the final version of the game,
//but it is here just in case
}

void Game::Draw()
{
    //draws the game, 
    //(its just a text based game so it will be mostly cout statements ie from narative.cpp)
    //GAME MENU
    if (currentState == MENU)
    {
        cout << "****MAIN MENU****" << endl;
        cout << "(1) Play " << endl;
        cout << "(2) Instructions" << endl;
        cout << "(3) Settings" << endl;
        cout << "(4) Exit" << endl;
    }
    else if (currentState == Play) // once character selected?? 
    {
    Narrative narrate;
    narrate.Narrative::intro(); //go to narrative.cpp to see the intro sequence, 
                                //which is the first part of the game
    } 
    else if (currentState == Instructions)
    {
        cout << "****INSTRUCTIONS****" << endl;
        cout << "This is a text based adventure game where you are given different options to choose from." << endl;
        cout << "Press the key thats presented beside the option you want to chose and press Enter to proceed. " << endl;
        cout << "To return to main menu, press any key and Enter. " << endl;
        //placeholder
    }
    else if (currentState == Settings)
    {
        cout << "Settings are not available yet." << endl;
        cout << "Press any key and Enter to return to the menu." << endl;
        //placeholder
    }
}

Game::Game()
    :   g_isRunning{true} //initialize game state to running by setting g_isRunning to true
{
    currentState = MENU; // starts game at the menu
}

Game::~Game()
{
}

void Game::Run()
{
    if (!Initl()) //if the game fails to initialize, return and end the game
    {
        return;
    }

    while (g_isRunning)
    {
        Draw();

        if (currentState == Play)
        {
            currentState = MENU;
            continue;
        }

        ProcInpts();
    }
}
