#pragma once

#include "Managers/GraphicsManager.hpp"
#include "Managers/EventsManager.hpp"


class Game
{
private:
    Managers::GraphicsManager* graphics;
    Managers::EventsManager* events;
    Managers::InputManager* inputs;

public:
    Game();
    ~Game();
    void execute();
};
