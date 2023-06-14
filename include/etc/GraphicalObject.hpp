#pragma once

#include "../Managers/GraphicsManager.hpp"
#include <SFML/Graphics.hpp>

class GraphicalObject
{
protected:
    static Managers::GraphicsManager* graphics;

    sf::Sprite sprite;

public:
    GraphicalObject(sf::Vector2f position=sf::Vector2f(0.0f, 0.0f), sf::Vector2f size=sf::Vector2f(0.0f, 0.0f));
    ~GraphicalObject();

    virtual void draw();
    void changeTexture(std::string path);
    void setOrigin(sf::Vector2f size);
    void setPosition(sf::Vector2f position);
    void setPosition(float x, float y);
    void setScale(float x, float y);
    void setTexture(sf::Texture& texture);
    void setTextureRect(const sf::IntRect& rect);
};
