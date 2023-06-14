#include "../../include/Entities/Obstacle.hpp"

namespace Entities
{
Obstacle::Obstacle(sf::Vector2f position, sf::Vector2f size):
    Entity(position, OBSTACLE_SIZE)
{
    id = ID::EntityID::obstacle;
    size = OBSTACLE_SIZE;
    graphicalRepresentation.changeTexture(OBSTACLE_TEXTURE_PATH);
    setPosition(position);
}


Obstacle::~Obstacle()
{

}


void Obstacle::move(float dt)
{

}


void Obstacle::handleCollision(Entity* otherEntity, sf::Vector2f intersection, bool collisionAxis)
{
    if(collisionAxis)
    {
        sf::Vector2f entityPosition = otherEntity->getPosition();
        if(position.x < entityPosition.x)
            otherEntity->setPosition(entityPosition.x - intersection.x, entityPosition.y);
        else
            otherEntity->setPosition(entityPosition.x + intersection.x, entityPosition.y);
    }
    else
    {
        sf::Vector2f entityPosition = otherEntity->getPosition();
        if(position.y < entityPosition.y)
            otherEntity->setPosition(entityPosition.x, entityPosition.y - intersection.y);
        else
            otherEntity->setPosition(entityPosition.x, entityPosition.y + intersection.y);
    }
}

}// namespace Entities
