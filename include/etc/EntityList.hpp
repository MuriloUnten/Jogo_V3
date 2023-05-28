#pragma once

#include "../Entities/Entity.hpp"
#include <list>

class EntityList
{
private:
    std::list<Entities::Entity*> list;

public:
    EntityList();
    ~EntityList();

    void draw();
    void execute();

};