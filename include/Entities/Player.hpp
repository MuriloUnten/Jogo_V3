#pragma once

#define PLAYER_ATTACK_COOLDOWN 1
#define PLAYER_SIZE sf::Vector2f(100.0f, 100.0f)
#define N_PROJECTILES 10
#define PLAYER_ACCELERATION_X 200
#define PLAYER_BREAK_COEFFICIENT 10
#define PLAYER_MAX_SPEED sf::Vector2f(200.0f, 200.0f)

#define STR_ATTACK_TIMER "attackTimer"

#include "Character.hpp"
#include "../etc/PlayerControl.hpp"
#include "PlayerProjectile.hpp"


namespace Entities
{
    class PlayerProjectile;

    class Player : public Character
    {
    private:
        PlayerControl* controls;

        PlayerProjectile* projectiles[N_PROJECTILES];
        int currentProjectile;

        int score;

    public:
        Player(sf::Vector2f position=sf::Vector2f(0, 0));
        Player();
        ~Player();

        void move(float dt);

        void jump();
        void attack();
        void shoot();
        void stopWalking(bool side);
        void stopAttacking();
        void draw();

        void addScore(const int extraScore);
        const int getScore() const;

        PlayerControl* getControls() const;
    };
}// namespace Entities
