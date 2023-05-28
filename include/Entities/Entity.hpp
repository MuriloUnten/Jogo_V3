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

        bool executable;

    public:
        Entity();
        virtual ~Entity();

        virtual void draw();
        virtual void execute() = 0;

        const ID::EntityID getID() const;
        
        const sf::Vector2f getPosition() const;
        const sf::Vector2f getVelocity() const;
        const sf::Vector2f getAcceleration() const;

        void updatePosition(float dt);
        void updateVelocity(float dt);

        const bool isExecutable() const;
    };
}// namespace Entities
