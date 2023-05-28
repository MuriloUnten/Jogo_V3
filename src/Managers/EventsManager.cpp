#include "../../include/Managers/EventsManager.hpp"

namespace Managers
{
    EventsManager* EventsManager::instance = nullptr;

    EventsManager::EventsManager()
    {
        pGraphics = GraphicsManager::getInstance();
        pInput = InputManager::getInstance();
    }


    EventsManager::~EventsManager()
    {
        pGraphics = nullptr;
        pInput->deleteInstance();
        pInput = nullptr;
    }


    EventsManager* EventsManager::getInstance()
    {
        if(instance == nullptr)
            instance = new EventsManager();

        return instance;
        
    }


    void EventsManager::deleteInstance()
    {
        if(instance)
            delete instance;
    }


    void EventsManager::pollEvents()
    {
        sf::Event event;
        while(pGraphics->getWindow()->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                pGraphics->close();
            else if(event.type == sf::Event::KeyPressed)
                pInput->notifyKeyPressed(event.key.code);
            else if(event.type == sf::Event::KeyReleased)
                pInput->notifyKeyReleased(event.key.code);
        }
    }


}// namespace Managers
