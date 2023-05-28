#include "../../include/Entities/Entity.hpp"


namespace Entities {
    Managers::GraphicsManager* Entity::graphics = Managers::GraphicsManager::getInstance();

    Entity::Entity()
    {

    }

    
    Entity::~Entity()
    {

    }

    void Entity::draw()
    {
        graphics->draw(sprite);
    }
}// namespace Entities
