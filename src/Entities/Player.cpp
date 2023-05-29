#include "../../include/Entities/Player.hpp"
#include <math.h>

namespace Entities
{
    Player::Player(sf::Vector2f position):
    Character(position),
    controls(new PlayerControl(this)),
    score(0),
    currentProjectile(0)
    {
        graphicalRepresentation = new GraphicalObject(position, PLAYER_SIZE);
        timers.createTimer(STR_ATTACK_TIMER, PLAYER_ATTACK_COOLDOWN);

        for(int i = 0; i < N_PROJECTILES; i++)
        {
            projectiles[i] = new PlayerProjectile(this);
        }
    }


    Player::~Player()
    {
        delete controls;

        for(int i = 0; i < N_PROJECTILES; i++)
        {
            delete projectiles[i];
        }
    }


    void Player::move(float dt)
    {
        controls->executePressedKeys();
        updateVelocity(dt);
        updatePosition(dt);
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


    void Player::attack()
    {
        attacking = true;
    }


    void Player::shoot()
{
    if(timers.isTimerActive(STR_ATTACK_TIMER))
        return;

    projectiles[currentProjectile]->shoot();
    currentProjectile = (currentProjectile + 1) % N_PROJECTILES;
    projectiles[currentProjectile]->setExecutable(false);

    timers.activateTimer(STR_ATTACK_TIMER);
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
        graphicalRepresentation->draw();
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
