#pragma once

#include <SFML/Graphics.hpp>
#include "../Entities/Entity.hpp"
#include <list>

namespace Managers
{
    class CollisionManager
    {
    private:
        GraphicsManager* graphics;

        std::list<Entities::Entity*>* list;

    public:
        CollisionManager(std::list<Entities::Entity*>* list);
        ~CollisionManager();

        void execute();
        sf::Vector2f calculateIntersection(Entities::Entity* first, Entities::Entity* second);

    };

}// namespace Managers
