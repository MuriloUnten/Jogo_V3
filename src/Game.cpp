#include "../include/Game.hpp"


Game::Game():
    graphics(Managers::GraphicsManager::getInstance()),
    events(Managers::EventsManager::getInstance()),
    inputs(Managers::InputManager::getInstance()),
    stateMachine(Managers::StateMachine::getInstance())
{



    execute();
}


Game::~Game()
{
    graphics->deleteInstance();
    events->deleteInstance();
    inputs->deleteInstance();
    stateMachine->deleteInstance();
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
