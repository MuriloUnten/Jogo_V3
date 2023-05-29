#include "../../include/etc/GraphicalObject.hpp"

Managers::GraphicsManager* graphics = Managers::GraphicsManager::getInstance();

GraphicalObject::GraphicalObject(sf::Vector2f size)
{
    sprite.setOrigin(size / 2.0f);
}


GraphicalObject::~GraphicalObject()
{

}


void GraphicalObject::draw()
{
    graphics->draw(sprite);    
}


void GraphicalObject::setOrigin(sf::Vector2f size)
{
    sprite.setOrigin(size / 2.0f);
}


void GraphicalObject::setPosition(sf::Vector2f position)
{
    sprite.setPosition(position);
}


void GraphicalObject::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
}
