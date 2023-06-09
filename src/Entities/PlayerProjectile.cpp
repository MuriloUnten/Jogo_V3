#include "../../include/Entities/PlayerProjectile.hpp"
#include "../../include/Entities/Player.hpp"

namespace Entities
{
    PlayerProjectile::PlayerProjectile(Player* player):
    Projectile(sf::Vector2f(0.0f, 0.0f), PLAYER_PROJECTILE_SIZE),
    player(player)
    {
        graphicalRepresentation.changeTexture(PLAYER_PROJECTILE_TEXTURE_PATH);

        maxVelocity.x = PLAYER_PROJECTILE_VELOCITY;
    }


    PlayerProjectile::~PlayerProjectile()
    {

    }

    

    void PlayerProjectile::shoot()
    {
        executable = true;
        facingRight = player->isFacingRight();
        float vel = facingRight? PLAYER_PROJECTILE_VELOCITY : -PLAYER_PROJECTILE_VELOCITY;
        velocity = sf::Vector2f(vel, 0.0f);
        setPosition(player->getPosition());
    }
}// namespace Entities
