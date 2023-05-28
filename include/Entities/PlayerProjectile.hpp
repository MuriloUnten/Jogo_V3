#pragma once

#include "Projectile.hpp"
#include "Player.hpp"

#define PLAYER_PROJECTILE_SIZE sf::Vector2f(50.0f, 50.0f)
#define PLAYER_PROJECTILE_VELOCITY 50
#define PLAYER_PROJECTILE_DAMAGE 1

namespace Entities
{
    class PlayerProjectile : public Projectile
    {
    private:
        Player* player;

    public:
        PlayerProjectile();
        ~PlayerProjectile();

        void move(float dt);
        void shoot();
    };
}