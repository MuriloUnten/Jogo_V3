#include "../../include/Managers/CollisionManager.hpp"


namespace Managers
{

    CollisionManager::CollisionManager()
    {
        graphics = GraphicsManager::getInstance();
    }


    CollisionManager::~CollisionManager()
    {

    }


    void CollisionManager::setList(std::list<Entities::Entity*>* list)
    {
        this->list = list;
    }


    void CollisionManager::execute()
    {
        std::list<Entities::Entity*>::iterator first;
        for(first = list->begin(); first != list->end(); first++)
        {
            if(!(*first)->isExecutable())
                continue;

            std::list<Entities::Entity*>::iterator second;
            for(second = std::next(first); second != list->end(); second++)
            {
                if(!(*second)->isExecutable())
                    continue;

                sf::Vector2f intersection = calculateIntersection(*first, *second);
                if(intersection.x < 0.0f && intersection.y < 0.0f)
                {
                    bool collisionAxis = calculateCollisionAxis(*first, *second, intersection);
                    (*first)->handleCollision(*second, intersection, collisionAxis);
                }
            }
        }
    }


    sf::Vector2f CollisionManager::calculateIntersection(Entities::Entity* first, Entities::Entity* second)
    {
        sf::Vector2f minimumDistance = calculateMinimumDistanceForCollision(first->getSize(), second->getSize());
        sf::Vector2f centersDistance = calculateDistanceBetweenCenters(first->getPosition(), second->getPosition());

        return centersDistance - minimumDistance;
    }


    sf::Vector2f CollisionManager::calculateMinimumDistanceForCollision(sf::Vector2f firstSize, sf::Vector2f secondSize)
    {
        return ((firstSize + secondSize) / 2.0f);
    }


    sf::Vector2f CollisionManager::calculateDistanceBetweenCenters(sf::Vector2f firstPosition, sf::Vector2f secondPosition)
    {
        return (sf::Vector2f(fabs(firstPosition.x - secondPosition.x),
                             fabs(firstPosition.y - secondPosition.y)));
    }


    bool CollisionManager::calculateCollisionAxis(Entities::Entity* first, Entities::Entity* second, sf::Vector2f intersection)
    {
        sf::Vector2f firstEntityPreviousPosition = first->getPosition() - (first->getVelocity() * graphics->getDeltaTime());
        sf::Vector2f secondEntityPreviousPosition = second->getPosition() - (second->getVelocity() * graphics->getDeltaTime());

        sf::Vector2f minimumDistance = calculateMinimumDistanceForCollision(first->getSize(), second->getSize());
        sf::Vector2f centersDistance = calculateDistanceBetweenCenters(firstEntityPreviousPosition, secondEntityPreviousPosition);
        sf::Vector2f intersectionBeforeMoving = centersDistance - minimumDistance;

        if(intersectionBeforeMoving.x < 0.0f && intersectionBeforeMoving.y > 0.0f)
            return COLLISION_IN_Y;
        if(intersectionBeforeMoving.x > 0.0f && intersectionBeforeMoving.y < 0.0f)
            return COLLISION_IN_X;

        if(intersection.x > intersection.y)
            return COLLISION_IN_X;

        return COLLISION_IN_Y;
    }
}// namespace Managers
