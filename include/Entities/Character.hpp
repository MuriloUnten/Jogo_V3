#pragma once

#include "Entity.hpp"
#include "../etc/TimerMap.hpp"

namespace Entities
{
    class Character: public Entity
    {
        
    protected:
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
        Character(sf::Vector2f position=sf::Vector2f(0.0f, 0.0f));
        virtual ~Character();

        void updateTimers(float dt);

        void setFacingRight(const bool facingRight);
        const bool isFacingRight() const;

        void takeDamage(const int damageTaken=1);
        const int getHp() const;

        const bool isAttacking() const;

        void setCanJump(const bool jump);
    };
}// namespace Entities
