#include "../../include/Entities/Character.hpp"

#define TIMECOLLISON 0.3

namespace Entities
{
    Character::Character(sf::Vector2f position):
    Entity(position),
    timers(),
    facingRight(true)
    {
        canJump = false;
        attacking = false;
        walking = false;
    }


    Character::~Character()
    {

    }

    void Character::updateTimers(float dt)
    {
        timers.updateTimers(dt);
    }


    void Character::setFacingRight(const bool facingRight)
    {
        this->facingRight = facingRight;
    }


    const bool Character::isFacingRight() const
    {
        return facingRight;
    }


    const int Character::getHp() const
    {
        return hp;
    }


    void Character::takeDamage(const int damageTaken)
    {
        hp -= damageTaken;
    }

    
    const bool Character::isAttacking() const
    {
        return attacking;
    }


    void Character::setCanJump(const bool jump)
    {
        canJump = jump;
    }
}// namespace Entities
