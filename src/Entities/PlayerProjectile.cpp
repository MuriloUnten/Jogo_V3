#include "../../include/Entities/PlayerProjectile.hpp"

namespace Entities
{
    PlayerProjectile::PlayerProjectile():
    Projectile()
    {
        sprite.setOrigin(PLAYER_PROJECTILE_SIZE / 2.0f);
    }


    PlayerProjectile::~PlayerProjectile()
    {

    }

    
    void PlayerProjectile::move(float dt)
    {
        updatePosition(dt);
    }


    void PlayerProjectile::shoot()
    {
        executable = true;
        velocity = sf::Vector2f(PLAYER_PROJECTILE_VELOCITY, 0.0f);
        position = sf::Vector2f(player->getPosition());
    }
}// namespace Entities
