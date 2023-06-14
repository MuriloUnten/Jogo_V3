#include "../../include/etc/Animation.hpp"

Managers::GraphicsManager* Animation::graphics = Managers::GraphicsManager::getInstance();

Animation::Animation(std::string filePath, sf::Vector2f scale, sf::Vector2f offset, const unsigned int numberOfFrames, float frameTime):
    scale(scale),
    offset(offset),
    imageSection(0, 0, 0, 0),
    numberOfFrames(numberOfFrames),
    frameTime(frameTime),
    elapsedTime(0.0f),
    currentFrame(0)
{
    texture = graphics->loadTexture(filePath);

    // TODO Fix the section logic.
    imageSection.width = (int) (texture->getSize().x / numberOfFrames);
    imageSection.height = (int) texture->getSize().y;
}


Animation::~Animation()
{

}


void Animation::executeAnimation(const bool facingRight)
{
    elapsedTime += graphics->getDeltaTime();

    if(elapsedTime >= frameTime)
    {
        elapsedTime = 0.0f;
        if(++currentFrame == numberOfFrames)
            resetAnimation();
    }

    if(facingRight)
    {
        imageSection.left = currentFrame * imageSection.width;
        imageSection.width = abs(imageSection.width);
    }
    else
    {
        imageSection.left = (currentFrame + 1) * abs(imageSection.width);
        imageSection.width = -abs(imageSection.width);
    }
}


void Animation::resetAnimation()
{
    currentFrame = 0;
    imageSection.left = 0;
    elapsedTime = 0.0f;
}


sf::Texture* Animation::getTexture() const
{
    return texture;
}


const sf::Vector2f Animation::getScale() const
{
    return scale;
}


const sf::IntRect& Animation::getImageSection() const
{
    return imageSection;
}


const unsigned int Animation::getNumberOfFrames() const
{
    return numberOfFrames;
}


const float Animation::getFrameTime() const
{
    return frameTime;
}


