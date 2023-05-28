#include "../../include/etc/Timer.hpp"


Timer::Timer(float newLimit)
{
    limit = newLimit;
    elapsedTime = 0.0f;
}


Timer::~Timer()
{

}


void Timer::setLimit(const float newLimit)
{
    limit = newLimit;
}


const float Timer::getLimit() const
{
    return limit;
}


void Timer::update(const float dt)
{
    elapsedTime += dt;

    if(elapsedTime > limit)
    {
        elapsedTime = limit;
        active = false;
    }
}


const float Timer::getElapsedTime() const
{
    return elapsedTime;
}


void Timer::activateTimer()
{
    if(active)
        return;

    active = true;
    elapsedTime = 0.0f;
}


const bool Timer::isActive() const
{
    return active;
}
