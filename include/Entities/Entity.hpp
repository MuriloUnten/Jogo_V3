#pragma once

#include "../Managers/GraphicsManager.hpp"
#include "../ID/EntityID.hpp"

namespace Entities
{
    class Entity
    {
    protected:
        static Managers::GraphicsManager* graphics;

        sf::Sprite sprite;
        ID::EntityID id;

        sf::Vector2f position;
        sf::Vector2f velocity;
        sf::Vector2f acceleration;

        int damage;
        bool executable;

    public:
        Entity(sf::Vector2f position=sf::Vector2f(0.0f, 0.0f));
        virtual ~Entity();

        virtual void draw();
        void execute(); // template method
        virtual void move(float dt);
        virtual void updateTimers(float dt);

        const ID::EntityID getID() const;
        const sf::Vector2f getPosition() const;
        const sf::Vector2f getVelocity() const;
        const sf::Vector2f getAcceleration() const;

        void updatePosition(float dt);
        void updateVelocity(float dt);

        const int getDamage() const;
        const bool isExecutable() const;
    };
}// namespace Entities
