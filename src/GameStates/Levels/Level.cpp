#include "../../../include/GameStates/Levels/Level.hpp"
#include "../../../include/Entities/Player.hpp"

namespace GameStates
{
    Level::Level():
    GameState()
    {
        id = level;

        {// Temporary. TODO Remove 
            Entities::Player* player = new Entities::Player(sf::Vector2f(0.0f, 0.0f));
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

    }


    void Level::draw()
    {
        entities.draw();
    }


    void Level::execute()
    {
        entities.execute();
    }


    void Level::resetState()
    {

    }


    const EntityList* Level::getEntities() const
    {
        return &entities;
    }
}// namespace GameStates
