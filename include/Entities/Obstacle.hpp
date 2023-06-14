#pragma once

#include "Entity.hpp"

#define OBSTACLE_SIZE sf::Vector2f(50.0f, 50.0f)
#define OBSTACLE_TEXTURE_PATH "../assets/obstacle.png"

namespace Entities
{

class Obstacle : public Entity
{
protected:
    

public:
    Obstacle(sf::Vector2f position=sf::Vector2f(0.0f, 0.0f), sf::Vector2f size=sf::Vector2f(0.0f, 0.0f));
    virtual ~Obstacle();

    virtual void move(float dt);
    virtual void handleCollision(Entity* otherEntity, sf::Vector2f intersection, bool collisionAxis);
};
}// namespace Entities
