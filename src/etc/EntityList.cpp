#include "../../include/etc/EntityList.hpp"


EntityList::EntityList()
{

}


EntityList::~EntityList()
{
    std::list<Entities::Entity*>::iterator iterator;
    for(iterator = list.begin(); iterator != list.end(); iterator++)
    {
        delete(*iterator);
    }
}


void EntityList::draw()
{
    std::list<Entities::Entity*>::iterator iterator;
    for(iterator = list.begin(); iterator != list.end(); iterator++)
    {
        (*iterator)->draw();
    }
}


void EntityList::execute()
{
    std::list<Entities::Entity*>::iterator iterator;
    for(iterator = list.begin(); iterator != list.end(); iterator++)
    {
        (*iterator)->execute();
    }
}


void EntityList::pushEntity(Entities::Entity* entity)
{
    list.push_back(entity);
}


std::list<Entities::Entity*>* EntityList::getList()
{
    return &list;
}
