#pragma once

#include "Entity.hpp"

namespace Entities
{
    class Projectile : public Entity
    {
    protected:
        bool facingRight;
    
    public:
        Projectile(sf::Vector2f position=sf::Vector2f(0.0f, 0.0f), sf::Vector2f size=sf::Vector2f(0.0f, 0.0f));
        virtual ~Projectile();

        virtual void shoot() = 0;
        void handleMovementLogic();
        virtual void handleCollision(Entity* otherEntity, sf::Vector2f intersection, bool collisionAxis);
    };
}//namespace Entities
