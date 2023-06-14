#pragma once

#define PLAYER_ATTACK_COOLDOWN 0.5f
#define PLAYER_SIZE sf::Vector2f(192.0f, 192.0f)
#define N_PROJECTILES 10
#define PLAYER_ACCELERATION_X 2000
#define PLAYER_BREAK_COEFFICIENT 10
#define PLAYER_MAX_VELOCITY sf::Vector2f(600.0f, 2000.0f)
#define PLAYER_JUMP_SPEED -1000

#define PLAYER_TEXTURE_PATH "../assets/player.png"

#define STR_ATTACK_TIMER "attackTimer"

#include "Character.hpp"
#include "../etc/PlayerControl.hpp"
#include "PlayerProjectile.hpp"
#include <array>


namespace Entities
{
    class PlayerProjectile;

    class Player : public Character
    {
    private:
        PlayerControl* controls;

        std::array<PlayerProjectile*, N_PROJECTILES>* projectiles;
        int currentProjectile;

        int score;

    public:
        Player(sf::Vector2f position=sf::Vector2f(0, 0));
        Player();
        ~Player();

        void handleMovementLogic();

        void jump();
        void attack();
        void shoot();
        void stopWalking(bool side);
        void stopAttacking();

        void addScore(const int extraScore);
        const int getScore() const;

        PlayerControl* getControls() const;
        std::array<PlayerProjectile*, N_PROJECTILES>* getProjectiles() const;
    };
}// namespace Entities
