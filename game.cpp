#include "game.h"
#include "narrative.h"
bool Game::Initl()
{
    return true;
}

void Game::ProcInpts()
{

}

void Game::Update()
{

}

void Game::Draw()
{
    Narrative narrate;
    narrate.Narrative::intro();
}

Game::Game()
    :   g_isRunning{true}
{

}

Game::~Game()
{
}

void Game::Run()
{
    if (!Initl())
    {
        return;
    }

    Draw();
}
