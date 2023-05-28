#pragma once

class Timer
{
private:
    float elapsedTime;
    float limit;
    bool active;

public:
    Timer(float newLimit=0);
    ~Timer();

    void setLimit(const float newLimit);
    const float getLimit() const;

    void update(const float dt);
    const float getElapsedTime() const;
    void activateTimer();
    const bool isActive() const;
};
