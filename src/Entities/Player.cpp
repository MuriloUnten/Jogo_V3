#include "../../include/Entities/Player.hpp"
#include <math.h>

namespace Entities
{
    Player::Player(sf::Vector2f position):
    Character(position),
    controls(new PlayerControl(this)),
    projectiles(new std::array<PlayerProjectile*, N_PROJECTILES>),
    score(0),
    currentProjectile(0)
    {
        controls->setKeys("W", "A", "D", "Space");

        graphicalRepresentation = new GraphicalObject(position, PLAYER_SIZE);
        setPosition(position);
        maxVelocity = PLAYER_MAX_VELOCITY;

        timers.createTimer(STR_ATTACK_TIMER, PLAYER_ATTACK_COOLDOWN);

        for(int i = 0; i < N_PROJECTILES; i++)
        {
            projectiles->operator[](i) = new PlayerProjectile(this);
        }
    }


    Player::~Player()
    {
        delete controls;

        for(int i = 0; i < N_PROJECTILES; i++)
        {
            delete projectiles->operator[](i);
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

    projectiles->operator[](currentProjectile)->shoot();

    currentProjectile = (currentProjectile + 1) % N_PROJECTILES;
    projectiles->operator[](currentProjectile)->setExecutable(false);

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


    std::array<PlayerProjectile*, N_PROJECTILES>* Player::getProjectiles() const
    {
        return projectiles;
    }
}// namespace Entities
