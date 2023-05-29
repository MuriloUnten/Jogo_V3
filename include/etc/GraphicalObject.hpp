#pragma once

#include "../Managers/GraphicsManager.hpp"
#include <SFML/Graphics.hpp>

class GraphicalObject
{
private:
    static Managers::GraphicsManager* graphics;

    sf::Sprite sprite;

public:
    GraphicalObject(sf::Vector2f position=sf::Vector2f(0.0f, 0.0f));
    virtual ~GraphicalObject();

    virtual void draw();
    void setOrigin(sf::Vector2f size);
    void setPosition(sf::Vector2f position);
    void setPosition(float x, float y);
};