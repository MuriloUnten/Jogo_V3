#include "../../include/etc/CharacterGraphics.hpp"


CharacterGraphics::CharacterGraphics(GraphicalObject* object)
{
    graphicalObject = object;
    currentAnimation = nullptr;
}


CharacterGraphics::~CharacterGraphics()
{
    std::map<std::string, Animation*>::iterator it;
    for(it = animations.begin(); it != animations.end(); it++)
    {
        delete (it->second);
    }
}


void CharacterGraphics::draw()
{
    graphicalObject->draw();
}


void CharacterGraphics::addAnimation(std::string name, std::string filePath, sf::Vector2f scale, sf::Vector2f offset, const unsigned int numberOfFrames, float frameTime)
{
    Animation* newAnimation = new Animation(filePath, scale, offset, numberOfFrames, frameTime);
    animations.insert(std::pair<std::string, Animation*>(name, newAnimation));
}


void CharacterGraphics::changeAnimation(std::string nextAnimation)
{
    Animation* animation;
    try
    {
        animation = animations.at(nextAnimation);
    }
    catch(std::out_of_range)
    {
        std::cerr << "Animation with that name does NOT exist.\n";
        return;
    }
    
    if(currentAnimation)
        currentAnimation->resetAnimation();

    currentAnimation = animation;
}


void CharacterGraphics::executeAnimation(const bool facingRight)
{
    currentAnimation->executeAnimation(facingRight);
    graphicalObject->setTextureRect(currentAnimation->getImageSection());
    graphicalObject->setTexture(*(currentAnimation->getTexture()));
    graphicalObject->setScale(currentAnimation->getScale().x, currentAnimation->getScale().y);
}
