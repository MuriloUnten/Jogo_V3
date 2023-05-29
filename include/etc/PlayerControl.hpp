#pragma once

#include "Observer.hpp"

namespace Entities
{
    class Player;
}

class PlayerControl : public Observer
{
private:
    Entities::Player* pPlayer;
    std::map<std::string, bool> pressedKeys;

    std::string jump;
    std::string left;
    std::string right;
    std::string shoot;

public:
    PlayerControl(Entities::Player* player);
    ~PlayerControl();

    void handleKeyPressed(std::string key);
    void handleKeyReleased(std::string key);

    void executePressedKeys();

    void setPlayer(Entities::Player* player);
    void setKeys(std::string jump, std::string left, std::string right, std::string shoot);
};
