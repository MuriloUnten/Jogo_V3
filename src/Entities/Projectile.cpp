#include "../../include/Entities/Projectile.hpp"

namespace Entities
{
    Projectile::Projectile():
    Entity()
    {
        executable = false;
        acceleration = sf::Vector2f(0.0f, 0.0f);
        velocity = sf::Vector2f(0.0f, 0.0f);
        position = sf::Vector2f(0.0f, 0.0f);
    }


    Projectile::~Projectile()
    {

    }

    void Projectile::handleMovementLogic()
    {
        if(facingRight)
            graphicalRepresentation->setScale(1.0f, 1.0f);
        else
            graphicalRepresentation->setScale(-1.0f, 1.0f);
}
}// namespace Entities
