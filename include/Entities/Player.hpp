#pragma once

#define PLAYER_ATTACK_COOLDOWN 1
#define PLAYER_SIZE sf::Vector2f(100, 100)

#include "Character.hpp"
#include "../etc/PlayerControl.hpp"


namespace Entities
{
    class Player : public Character
    {
    private:

        PlayerControl* controls;

        int score;

    public:
        Player(sf::Vector2f position=sf::Vector2f(0, 0));
        Player();
        ~Player();

        void changeVelocity();

        void jump();
        void move(bool right);
        void attack();
        void stopWalking(bool side);
        void stopAttacking();
        void draw();

        void addScore(const int extraScore);
        const int getScore() const;

        PlayerControl* getControls() const;
    };
}// namespace Entities
