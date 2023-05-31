#include "../../include/etc/GraphicalObject.hpp"

Managers::GraphicsManager* GraphicalObject::graphics = Managers::GraphicsManager::getInstance();

GraphicalObject::GraphicalObject(sf::Vector2f position, sf::Vector2f size)
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


void GraphicalObject::changeTexture(std::string path)
{
    sprite.setTexture(*(graphics->loadTexture(path)));
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
