#include "../../include/etc/PlayerControl.hpp"
#include "../../include/Entities/Player.hpp"

PlayerControl::PlayerControl(Entities::Player* player):
Observer(),
pPlayer(player)
{

}


PlayerControl::~PlayerControl()
{
    pPlayer = NULL;
}


void PlayerControl::handleKeyPressed(std::string key)
{
    if(key == jump)
    {
        pPlayer->jump();
    }

    else if(key == left)
    {
        pPlayer->move(false);
    }

    else if(key == right)
        pPlayer->move(true);

    else if(key == attack)
        pPlayer->attack();
}


void PlayerControl::handleKeyReleased(std::string key)
{
    if(key == left)
        pPlayer->stopWalking(false);

    else if(key == right)
        pPlayer->stopWalking(true);

    else if(key == attack)
        pPlayer->stopAttacking();
}


void PlayerControl::setPlayer(Entities::Player* player)
{
    pPlayer = player;
}


void PlayerControl::setKeys(std::string jump, std::string left, std::string right, std::string attack)
{
    this->jump = jump;
    this->left = left;
    this->right = right;
    this->attack = attack;
}
