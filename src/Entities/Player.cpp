#include "../../include/Entities/Player.hpp"
#include <math.h>

namespace Entities
{
    Player::Player(sf::Vector2f position):
    Entity(position),
    controls(new PlayerControl(this))
    {
        facingRight = true;
        attackTimer->setLimit(PLAYER_ATTACK_COOLDOWN);
        score = 0;
    }


    Player::Player():
    Entity(),
    controls(new PlayerControl(this))
    {
        hp = 10;
        facingRight = true;
        attackTimer->setLimit(PLAYER_ATTACK_COOLDOWN);
        score = 0;
    }


    Player::~Player()
    {
        delete controls;
    }


    void Player::jump()
    {
        if(canJump)
        {
            vel.y = -600;
            jumping = true;
            canJump = false;
        }
    }


    void Player::move(bool right)
    {
        walking = true;
        setFacingRight(right);
    }


    void Player::attack()
    {
        attacking = true;
    }


    void Player::stopWalking(bool side)
    {
        if(side == facingRight)
        walking = false;
    }


    void Player::stopAttacking()
    {
        attacking = false;
    }

    void Player::draw()
    {
        graphics->draw(sprite);
    }


    void Player::addScore(const int extraScore)
    {
        score += extraScore;
    }


    const int Player::getScore() const
    {
        return score;
    }


    PlayerControl* Player::getControls() const
    {
        return controls;
    }
}// namespace Entities
