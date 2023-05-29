#include "../../include/etc/PlayerControl.hpp"
#include "../../include/Entities/Player.hpp"

PlayerControl::PlayerControl(Entities::Player* player):
Observer(),
pPlayer(player)
{
    pressedKeys["jump"] = false;
    pressedKeys["left"] = false;
    pressedKeys["right"] = false;
    pressedKeys["shoot"] = false;
}


PlayerControl::~PlayerControl()
{
    pPlayer = nullptr;
}


void PlayerControl::handleKeyPressed(std::string key)
{
    if(key == jump)
        pressedKeys["jump"] = true;

    else if(key == left)
        pressedKeys["left"] = true;

    else if(key == right)
        pressedKeys["right"] = true;

    else if(key == shoot)
        pressedKeys["shoot"] = true;
}


void PlayerControl::handleKeyReleased(std::string key)
{
    if(key == jump)
        pressedKeys["jump"] = false;

    else if(key == left)
        pressedKeys["left"] = false;

    else if(key == right)
        pressedKeys["right"] = false;

    else if(key == shoot)
        pressedKeys["shoot"] = false;
}


void PlayerControl::executePressedKeys()
{
    float acc = 0.0f;
    float xVel = pPlayer->getVelocity().x;

    if(pressedKeys["left"] && !pressedKeys["right"])
    {
        acc -= PLAYER_ACCELERATION_X;
        if(xVel > 0)
            acc -= xVel * PLAYER_BREAK_COEFFICIENT;
    }
    else if(pressedKeys["right"] && !pressedKeys["left"])
    {
        acc += PLAYER_ACCELERATION_X;
        if(xVel < 0)
            acc += xVel * PLAYER_BREAK_COEFFICIENT;
    }
    else
        acc = -xVel * PLAYER_BREAK_COEFFICIENT;

    if(pressedKeys["jump"])
        pPlayer->jump();
    if(pressedKeys["shoot"])
        pPlayer->shoot();

    pPlayer->setAcceleration(acc, pPlayer->getAcceleration().y);
}


void PlayerControl::setPlayer(Entities::Player* player)
{
    pPlayer = player;
}


void PlayerControl::setKeys(std::string jump, std::string left, std::string right, std::string shoot)
{
    this->jump = jump;
    this->left = left;
    this->right = right;
    this->shoot = shoot;
}
