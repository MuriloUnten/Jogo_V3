#pragma once

#include "../Managers/GraphicsManager.hpp"
#include "../ID/EntityID.hpp"
#include "../etc/GraphicalObject.hpp"

namespace Entities
{
    class Entity
    {
    protected:
        static Managers::GraphicsManager* graphics;

        GraphicalObject* graphicalRepresentation;
        ID::EntityID id;

        sf::Vector2f position;
        sf::Vector2f velocity;
        sf::Vector2f maxVelocity;
        sf::Vector2f acceleration;
        sf::Vector2f size;

        int damage;
        bool executable;

    public:
        Entity(sf::Vector2f position=sf::Vector2f(0.0f, 0.0f));
        virtual ~Entity();

        void draw();
        void execute(); // template method
        virtual void move(float dt);
        virtual void updateTimers(float dt); // hook
        virtual void handleMovementLogic();

        virtual void handleCollision(Entity* otherEntity, sf::Vector2f intersection, bool collisionAxis) = 0;

        const ID::EntityID getID() const;

        void setPosition(sf::Vector2f newPosition);
        void setPosition(float x, float y);
        const sf::Vector2f getPosition() const;

        const sf::Vector2f getVelocity() const;

        void setAcceleration(sf::Vector2f newAcc);
        void setAcceleration(float x, float y);
        const sf::Vector2f getAcceleration() const;

        const sf::Vector2f getSize() const;

        void updatePosition(float dt);
        void updateVelocity(float dt);

        const int getDamage() const;
        void setExecutable(const bool condition);
        const bool isExecutable() const;
    };
}// namespace Entities
