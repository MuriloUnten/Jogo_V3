#include "../../include/Managers/CollisionManager.hpp"


namespace Managers
{

CollisionManager::CollisionManager(std::list<Entities::Entity*>* list)
{
    this->list = list;
}


CollisionManager::~CollisionManager()
{

}


void CollisionManager::execute()
{

}


sf::Vector2f CollisionManager::calculateIntersection(Entities::Entity* first, Entities::Entity* second)
{

}

}// namespace Managers
