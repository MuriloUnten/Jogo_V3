#include "../../include/Entities/Player.hpp"
#include <math.h>

namespace Entities
{
    Player::Player(sf::Vector2f position):
    Character(position, PLAYER_SIZE),
    controls(new PlayerControl(this)),
    projectiles(new std::array<PlayerProjectile*, N_PROJECTILES>),
    currentProjectile(0),
    score(0)
    {
        id = ID::EntityID::player;
        controls->setKeys("W", "A", "D", "Space");

        setPosition(position);
        size = PLAYER_SIZE;
        maxVelocity = PLAYER_MAX_VELOCITY;

        timers.createTimer(STR_ATTACK_TIMER, PLAYER_ATTACK_COOLDOWN);

        for(int i = 0; i < N_PROJECTILES; i++)
        {
            projectiles->operator[](i) = new PlayerProjectile(this);
        }
        
        animation.addAnimation("idle", "../assets/gunner/gunner_idle.png", sf::Vector2f(1.0f, 1.0f), sf::Vector2f(27.0f, 47.0f), 5, 0.7f);
        animation.changeAnimation("idle");
    }


    Player::~Player()
    {
        delete controls;

        for(int i = 0; i < N_PROJECTILES; i++)
        {
            delete projectiles->operator[](i);
        }
    }


    void Player::handleMovementLogic()
    {
        controls->executePressedKeys();

        // if(facingRight)
        //     graphicalRepresentation.setScale(1.0f, 1.0f);
        // else
        //     graphicalRepresentation.setScale(-1.0f, 1.0f);
    }


    void Player::jump()
    {
        if(canJump)
        {
            velocity.y = PLAYER_JUMP_SPEED;
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
