#pragma once

#include <SFML/Graphics.hpp>
#include "../Entities/Entity.hpp"
#include "../etc/EntityList.hpp"
#include <list>
#include <iterator>
#include <cmath>

#define COLLISION_IN_X true
#define COLLISION_IN_Y false

namespace Managers
{
    class CollisionManager
    {
    private:
        GraphicsManager* graphics;

        std::list<Entities::Entity*>* list;
        EntityList* entityList;

    public:
        CollisionManager();
        ~CollisionManager();
        void setList(std::list<Entities::Entity*>* list);

        void execute();
        sf::Vector2f calculateIntersection(Entities::Entity* first, Entities::Entity* second);
        sf::Vector2f calculateMinimumDistanceForCollision(sf::Vector2f firstSize, sf::Vector2f secondSize);
        sf::Vector2f calculateDistanceBetweenCenters(sf::Vector2f firstPosition, sf::Vector2f secondPosition);
        bool calculateCollisionAxis(Entities::Entity* first, Entities::Entity* second, sf::Vector2f intersection);
    };

}// namespace Managers
