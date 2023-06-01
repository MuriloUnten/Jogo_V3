#include "../../../include/GameStates/Levels/Level.hpp"
#include "../../../include/Entities/Player.hpp"

namespace GameStates
{
    Level::Level():
    GameState(),
    collisions(new Managers::CollisionManager())
    {
        collisions->setList(entities.getList());
        id = level;

        {// Temporary. TODO Remove 
            Entities::Player* player = new Entities::Player(sf::Vector2f(200.0f, 200.0f));
            entities.pushEntity(player);

            std::array<Entities::PlayerProjectile*, N_PROJECTILES>* projectiles = player->getProjectiles();
            for(int i = 0; i < N_PROJECTILES; i++)
            {
                entities.pushEntity(projectiles->operator[](i));
            }
        }
    }


    Level::~Level()
    {
        delete collisions;
    }


    void Level::draw()
    {
        entities.draw();
    }


    void Level::execute()
    {
        entities.execute();
        collisions->execute();
        draw();
    }


    void Level::resetState()
    {

    }


    const EntityList* Level::getEntities() const
    {
        return &entities;
    }
}// namespace GameStates
