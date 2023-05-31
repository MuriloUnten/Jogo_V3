#pragma once

#include "Projectile.hpp"

#define PLAYER_PROJECTILE_SIZE sf::Vector2f(50.0f, 50.0f)
#define PLAYER_PROJECTILE_VELOCITY 1000
#define PLAYER_PROJECTILE_DAMAGE 1

#define PLAYER_PROJECTILE_TEXTURE_PATH "../assets/bullet.png"

namespace Entities
{
    class Player;

    class PlayerProjectile : public Projectile
    {
    private:
        Player* player;

    public:
        PlayerProjectile(Player* player=nullptr);
        ~PlayerProjectile();

        void move(float dt);
        void shoot();
    };
}
