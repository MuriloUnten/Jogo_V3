#include "../../include/etc/TimerMap.hpp"


TimerMap::TimerMap()
{
    iterator = timers.begin();
}


TimerMap::~TimerMap()
{
    for(iterator = timers.begin(); iterator != timers.end(); iterator++)
    {
        if(iterator->second)
            delete (iterator->second);
    }
}


void TimerMap::createTimer(std::string key, float limit)
{
    Timer* timer = new Timer(limit);
    timers[key] = timer;
}


Timer* TimerMap::getTimer(std::string key)
{
    return timers[key];
}


void TimerMap::updateTimers(float dt)
{
    for(iterator = timers.begin(); iterator != timers.end(); iterator++)
    {
        Timer* tmp = iterator->second;
        if(tmp->isActive())
            tmp->update(dt);
    }
}


void TimerMap::setTimerLimit(std::string key, float limit)
{
    for(iterator = timers.begin(); iterator != timers.end(); iterator++)
    {
        if(key == iterator->first)
        {
            iterator->second->setLimit(limit);
            return;
        }
    }

    std::cout << "Key not in map\n";
}


const float TimerMap::getTimerValue(std::string key)
{
    for(iterator = timers.begin(); iterator != timers.end(); iterator++)
    {
        if(key == iterator->first)
            return (iterator->second->getElapsedTime());
    }

    std::cout << "Key not in map.\n";
    return -1.0f;
}


void TimerMap::activateTimer(std::string key)
{
    for(iterator = timers.begin(); iterator != timers.end(); iterator++)
    {
        if(key == iterator->first)
        {
            iterator->second->activateTimer();
            return;
        }
    }

    std::cout << "Key not in map\n";
}


const bool TimerMap::isTimerActive(std::string key)
{
    for(iterator = timers.begin(); iterator != timers.end(); iterator++)
    {
        if(key == iterator->first)
        {
            return iterator->second->isActive();
        }
    }

    std::cout <<"Key not in map\n";
    exit(0);
}

