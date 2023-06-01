#pragma once

#include "Entity.hpp"

namespace Entities
{
    class Projectile : public Entity
    {
    protected:
        bool facingRight;
    
    public:
        Projectile();
        virtual ~Projectile();

        virtual void shoot() = 0;
        void handleMovementLogic();
        virtual void handleCollision(Entity* otherEntity, sf::Vector2f intersection, bool collisionAxis);
    };
}//namespace Entities
