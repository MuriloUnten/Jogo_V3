#include "../../include/Entities/Entity.hpp"


namespace Entities {
    Managers::GraphicsManager* Entity::graphics = Managers::GraphicsManager::getInstance();

    Entity::Entity(sf::Vector2f position)
    {
        this->position = position;
    }

    
    Entity::~Entity()
    {

    }


    void Entity::draw()
    {
        graphics->draw(sprite);
    }


    void Entity::execute()
    {
        if(!executable)
            return;

        float dt = graphics->getDeltaTime();
        updateTimers(dt);
        move(dt);
    }


    void Entity::move(float dt)
    {

    }


    void Entity::updateTimers(float dt)
    {

    }


    const ID::EntityID Entity::getID() const
    {
        return id;
    }
    
    const sf::Vector2f Entity::getPosition() const
    {
        return position;
    }


    const sf::Vector2f Entity::getVelocity() const
    {
        return velocity;
    }


    const sf::Vector2f Entity::getAcceleration() const
    {
        return acceleration;
    }


    void Entity::updatePosition(float dt)
    {
        position += velocity * dt;
    }


    void Entity::updateVelocity(float dt)
    {
        velocity += acceleration * dt;
    }


    const bool Entity::isExecutable() const
    {
        return executable;
    }
}// namespace Entities
