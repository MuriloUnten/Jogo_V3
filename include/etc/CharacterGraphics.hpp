#pragma once

#include "GraphicalObject.hpp"
#include "Animation.hpp"

class CharacterGraphics
{
private:
    GraphicalObject* graphicalObject;
    std::map<std::string, Animation*> animations;
    Animation* currentAnimation;

public:
    CharacterGraphics(GraphicalObject* object);
    ~CharacterGraphics();

    void draw();

    void addAnimation(std::string name, std::string filePath, sf::Vector2f scale, sf::Vector2f offset, const unsigned int numberOfFrames, float frameTime);
    void changeAnimation(std::string nextAnimation);
    void executeAnimation(const bool facingRight);
};
