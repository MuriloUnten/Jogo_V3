#include "../../include/Entities/PlayerProjectile.hpp"
#include "../../include/Entities/Player.hpp"

namespace Entities
{
    PlayerProjectile::PlayerProjectile(Player* player):
    Projectile(),
    player(player)
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
        float vel = facingRight? PLAYER_PROJECTILE_VELOCITY : -PLAYER_PROJECTILE_VELOCITY;
        velocity = sf::Vector2f(vel, 0.0f);
        position = sf::Vector2f(player->getPosition());
    }
}// namespace Entities
