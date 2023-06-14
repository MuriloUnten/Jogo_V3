#include "../../include/Entities/Entity.hpp"


namespace Entities {
    Managers::GraphicsManager* Entity::graphics = Managers::GraphicsManager::getInstance();

    Entity::Entity(sf::Vector2f position, sf::Vector2f size):
        graphicalRepresentation(position, size),
        size(size),
        velocity(0.0f, 0.0f),
        maxVelocity(0.0f, 0.0f),
        acceleration(0.0f , GRAVITY),
        executable(true)
    {

    }

    
    Entity::~Entity()
    {
        
    }


    void Entity::draw()
    {
        if(!executable)
            return;
    
        graphicalRepresentation.draw();
    }


    void Entity::execute()
    {
        if(!executable)
            return;

        float dt = graphics->getDeltaTime();
        updateTimers(dt);
        move(dt);
        
        handleGraphicsLogic();
    }


    void Entity::move(float dt)
    {
        handleMovementLogic();
        updateVelocity(dt);
        updatePosition(dt);
    }


    void Entity::updateTimers(float dt)
    {

    }


    void Entity::handleMovementLogic()
    {

    }


    void Entity::handleGraphicsLogic()
    {

    }


    const ID::EntityID Entity::getID() const
    {
        return id;
    }


    void Entity::setPosition(sf::Vector2f newPosition)
    {
        position = newPosition;
        graphicalRepresentation.setPosition(position);
    }


    void Entity::setPosition(float x, float y)
    {
        position.x = x;
        position.y = y;
        graphicalRepresentation.setPosition(x, y);
    }
    
    const sf::Vector2f Entity::getPosition() const
    {
        return position;
    }


    const sf::Vector2f Entity::getVelocity() const
    {
        return velocity;
    }


    void Entity::setAcceleration(sf::Vector2f newAcc)
    {
        acceleration = newAcc;
    }


    void Entity::setAcceleration(float x, float y)
    {
        acceleration = sf::Vector2f(x, y);
    }


    const sf::Vector2f Entity::getAcceleration() const
    {
        return acceleration;
    }


    const sf::Vector2f Entity::getSize() const
    {
        return size;
    }


    void Entity::updatePosition(float dt)
    {
        setPosition(position + velocity * dt);
    }


    void Entity::updateVelocity(float dt)
    {
        velocity += acceleration * dt;

        if(velocity.x < -maxVelocity.x)
            velocity.x = -maxVelocity.x;
        else if(velocity.x > maxVelocity.x)
            velocity.x = maxVelocity.x;

        if(velocity.y > maxVelocity.y)
            velocity.y = maxVelocity.y;
    }


    const int Entity::getDamage() const
    {
        return damage;
    }


    void Entity::setExecutable(const bool condition)
    {
        executable = condition;
    }


    const bool Entity::isExecutable() const
    {
        return executable;
    }
}// namespace Entities
