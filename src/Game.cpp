#include "../include/Game.hpp"
#include "../include/GameStates/Levels/Level.hpp"


Game::Game():
    graphics(Managers::GraphicsManager::getInstance()),
    events(Managers::EventsManager::getInstance()),
    inputs(Managers::InputManager::getInstance()),
    stateMachine(Managers::StateMachine::getInstance())
{
    stateMachine->addState(new GameStates::Level());

    stateMachine->changeState(stateID::level);
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
