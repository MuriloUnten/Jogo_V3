#pragma once

#include "Entity.hpp"
#include "../etc/TimerMap.hpp"
#include "../etc/CharacterGraphics.hpp"

namespace Entities
{
    class Character: public Entity
    {
        
    protected:
        CharacterGraphics animation;
        TimerMap timers;
    
        int hp;

        bool facingRight;
        bool walking;
        bool canAttack;
        bool attacking;
        bool canJump;
        bool jumping;
        bool movingInX;

    public:
        Character(sf::Vector2f position=sf::Vector2f(0.0f, 0.0f), sf::Vector2f size=sf::Vector2f(0.0f, 0.0f));
        virtual ~Character();

        void handleGraphicsLogic();

        virtual void handleCollision(Entity* otherEntity, sf::Vector2f intersection, bool collisionAxis);

        void updateTimers(float dt);

        void setFacingRight(const bool facingRight);
        const bool isFacingRight() const;

        void takeDamage(const int damageTaken=1);
        const int getHp() const;

        const bool isAttacking() const;

        void setCanJump(const bool jump);
    };
}// namespace Entities
