#include "../../include/Managers/GraphicsManager.hpp"


namespace Managers
{
    GraphicsManager* GraphicsManager::instance = NULL;
    float GraphicsManager::deltaTime = 0;

    GraphicsManager* GraphicsManager::getInstance()
    {
        if (instance == NULL)
        {
            instance = new GraphicsManager();
        }
        return instance;
    }


    void GraphicsManager::deleteInstance()
    {
        if (instance)
            delete instance;
    }
    
    
    GraphicsManager::GraphicsManager() :
        window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Change my name."))
    {
        window->setFramerateLimit(60);
    }


    GraphicsManager::~GraphicsManager()
    {
        delete window;
        window = NULL;
        instance = NULL;
    }


    bool GraphicsManager::isWindowOpen()
    {
        return (window->isOpen());
    }


    void GraphicsManager::clear()
    {
        if (isWindowOpen())
            window->clear();
    }


    void GraphicsManager::close()
    {
        if (isWindowOpen())
            window->close();
    }

    /* Updates the window onto the screen */
    void GraphicsManager::display()
    {
        if (isWindowOpen())
            window->display();
    }

    void GraphicsManager::draw(sf::Sprite& body)
    {
        window->draw(body);
    }
    

    void GraphicsManager::draw(sf::RectangleShape& body)
    {
        window->draw(body);
    }


    sf::RenderWindow* GraphicsManager::getWindow()
    {
        return window;
    }


    void GraphicsManager::updateDeltaTime()
    {
        deltaTime = clock.restart().asSeconds();
        if(deltaTime > 0.1f)
            deltaTime = 0.1f;

    }


    const float GraphicsManager::getDeltaTime()
    {
        return deltaTime;
    }

}// namespace Managers
