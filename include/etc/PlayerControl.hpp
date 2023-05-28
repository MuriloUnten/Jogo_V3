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

    std::string jump;
    std::string left;
    std::string right;
    std::string attack;

public:
    PlayerControl(Entities::Player* player);
    ~PlayerControl();

    void handleKeyPressed(std::string key);
    void handleKeyReleased(std::string key);

    void setPlayer(Entities::Player* player);

    void setKeys(std::string jump, std::string left, std::string right, std::string attack);
};
