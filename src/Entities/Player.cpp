#include "../../include/Entities/Player.hpp"
#include <math.h>

namespace Entities
{
    Player::Player(sf::Vector2f position):
    Character(position),
    controls(new PlayerControl(this))
    {
        sprite.setOrigin(PLAYER_SIZE / 2.0f);

        facingRight = true;
        timers.createTimer("attackTimer", PLAYER_ATTACK_COOLDOWN);
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
            velocity.y = -600;
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
