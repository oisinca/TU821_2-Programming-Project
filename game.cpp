#include "game.h"
#include "narrative.h"

//if you wanna look at the headers for each section
//look at the name of the .cpp, and find its corresponding .h file, 
//they are in the same folder as the .cpp files

bool Game::Initl()
{
    return true;
}

void Game::ProcInpts()
{
//placeholder for input processing, not sure if this will be used in the final version of the game, 
//but it is here just in case
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
    Narrative narrate;
    narrate.Narrative::intro(); //go to narrative.cpp to see the intro sequence, 
                                //which is the first part of the game
}

Game::Game()
    :   g_isRunning{true} //initialize game state to running by setting g_isRunning to true
{

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

    Draw(); //else draw the game (ie run the narrative.cpp code)
}
