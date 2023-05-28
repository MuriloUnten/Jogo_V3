#pragma once

#include "../Managers/InputManager.hpp"


class Observer
{
protected:
    Managers::InputManager* pInput;

public:
    Observer();
    ~Observer();

    virtual void handleKeyPressed(std::string key) = 0;
    virtual void handleKeyReleased(std::string key) = 0;
};
