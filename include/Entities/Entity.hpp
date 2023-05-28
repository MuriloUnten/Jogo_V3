#pragma once

#include "../Managers/GraphicsManager.hpp"
#include "../ID/EntityID.hpp"

namespace Entities
{
    class Entity
    {
    private:
        static Managers::GraphicsManager* graphics;
        sf::Sprite sprite;
        ID::EntityID id;

        sf::Vector2f vel;

        bool executable;

    public:
        Entity();
        virtual ~Entity();

        virtual void draw();
        virtual void execute() = 0;
    };
}// namespace Entities
