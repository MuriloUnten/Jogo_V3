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

    void pushEntity(Entities::Entity* entity);
    std::list<Entities::Entity*>* getList();
};
