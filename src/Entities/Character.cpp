#include "../../include/Entities/Character.hpp"

#define TIMECOLLISON 0.3

namespace Entities
{
    Character::Character(sf::Vector2f position):
    Entity(position),
    timers(),
    facingRight(true)
    {
        canJump = true;
        attacking = false;
        walking = false;
    }


    Character::~Character()
    {

    }


    void Character::handleCollision(Entity* otherEntity, sf::Vector2f intersection, bool collisionAxis)
    {
        ID::EntityID ID = otherEntity->getID();
        switch (ID)
        {
            case ID::EntityID::player:
                break;
            
            case ID::EntityID::obstacle:
                otherEntity->handleCollision(this, intersection, collisionAxis);
                if(!collisionAxis)
                {
                    if(this->position.y < otherEntity->getPosition().y)
                    {
                        jumping = false;
                        canJump = true;
                    }
                    velocity.y = 0.0f;
                }
                else
                    velocity.x = 0.0f;
                break;

            case ID::EntityID::projectile:
                break;

        }

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
