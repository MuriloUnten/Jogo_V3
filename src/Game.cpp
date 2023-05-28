#include "../include/Game.hpp"


Game::Game():
    graphics(Managers::GraphicsManager::getInstance()),
    events(Managers::EventsManager::getInstance()),
    inputs(Managers::InputManager::getInstance())
{



    execute();
}


Game::~Game()
{
    graphics->deleteInstance();
}


void Game::execute()
{
    while(graphics->isWindowOpen())
    {
        events->pollEvents();

        graphics->clear();
        graphics->display();
    }
}
