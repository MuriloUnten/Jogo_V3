#pragma once

#include "Managers/GraphicsManager.hpp"
#include "Managers/EventsManager.hpp"
#include "Managers/StateMachine.hpp"

class Game
{
private:
    Managers::GraphicsManager* graphics;
    Managers::EventsManager* events;
    Managers::InputManager* inputs;
    Managers::StateMachine* stateMachine;

public:
    Game();
    ~Game();
    void execute();
};
