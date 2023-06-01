#pragma once

#include "../GameState.hpp"
#include "../../etc/EntityList.hpp"
#include "../../etc/GraphicalObject.hpp"
#include "../../Managers/CollisionManager.hpp"

namespace GameStates
{
    class Level : public GameState
    {
    protected:
        EntityList entities;
        GraphicalObject* graphicalRepresentation;
        Managers::CollisionManager* collisions;

    public:
        Level();
        virtual ~Level();

        void draw();
        void execute();
        void resetState();

        const EntityList* getEntities() const;
        // virtual void buildLevel() = 0;
    };

}// namespace GameStates
