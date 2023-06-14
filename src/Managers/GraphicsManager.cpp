#include "../../include/Managers/GraphicsManager.hpp"


namespace Managers
{
    GraphicsManager* GraphicsManager::instance = nullptr;
    float GraphicsManager::deltaTime = 0;

    GraphicsManager* GraphicsManager::getInstance()
    {
        if (instance == nullptr)
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
        window->setFramerateLimit(144);
    }


    GraphicsManager::~GraphicsManager()
    {
        delete window;
        window = nullptr;
        instance = nullptr;
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
        if(!isWindowOpen())
            return;
    
        window->draw(body);
    }
    

    void GraphicsManager::draw(sf::RectangleShape& body)
    {
        if(!isWindowOpen())
            return;

        window->draw(body);
    }


    sf::RenderWindow* GraphicsManager::getWindow()
    {
        return window;
    }


    sf::Texture* GraphicsManager::loadTexture(std::string path)
    {
        sf::Texture* texture;
        try
        {
            texture = textures.at(path);
        }
        catch(std::out_of_range)
        {
            texture = new sf::Texture;
            texture->loadFromFile(path);
            textures.insert(std::pair<std::string, sf::Texture*>(path, texture));
        }

        return texture;
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
