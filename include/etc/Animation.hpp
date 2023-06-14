#pragma once

#include <iostream>
#include "../Managers/GraphicsManager.hpp"

class Animation
{
private:
    
    static Managers::GraphicsManager* graphics;

    sf::Texture* texture;
    sf::IntRect imageSection;

    sf::Vector2f scale;
    sf::Vector2f offset;

    const unsigned int numberOfFrames;
    float frameTime;
    unsigned int currentFrame;

public:
    float elapsedTime;
    Animation(std::string filePath, sf::Vector2f scale, sf::Vector2f offset, const unsigned int numberOfFrames, float frameTime);
    ~Animation();

    void executeAnimation(const bool facingRight);
    void resetAnimation();

    sf::Texture* getTexture() const;
    const sf::Vector2f getScale() const;
    const sf::IntRect& getImageSection() const;

    const unsigned int getNumberOfFrames() const;
    const float getFrameTime() const;
};
