#pragma once

#include "Timer.hpp"
#include <map>
#include <string>
#include <iostream>

class TimerMap
{
private:
    std::map<std::string, Timer*> timers;
    std::map<std::string, Timer*>::iterator iterator;
        
public:
    TimerMap();
    ~TimerMap();

    void createTimer(std::string key, float limit);
    Timer* getTimer(std::string key);

    void updateTimers(float dt);
    void setTimerLimit(std::string key, float limit);
    const float getTimerValue(std::string key);
    void activateTimer(std::string key);
    const bool isTimerActive(std::string key);
};
