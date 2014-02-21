#include "ItemType.hpp"

ItemType::ItemType(std::string u)
    : uniqueId(u)
{
}

ItemType::~ItemType()
{
    // delete all the components
    for(std::vector<ItemTypeComponent*>::iterator it = _components.begin() ; it != _components.end() ; ++it)
    {
        delete *it;
    }
}

void ItemType::addComponent(ItemTypeComponent& component)
{
    _components.push_back(&component);
}

ItemTypeComponent* ItemType::getComponent(const ItemTypeComponent::Type& type) const
{
    for(std::vector<ItemTypeComponent*>::const_iterator it = _components.begin() ; it != _components.end() ; ++it)
    {
        if((**it).type == type)
        {
            return *it;
        }
    }
    return 0;
}

bool ItemType::hasComponent(const ItemTypeComponent::Type& type) const
{
    return getComponent(type) != 0 ;
}

bool ItemType::removeComponent(ItemTypeComponent& component)
{
    for(std::vector<ItemTypeComponent*>::iterator it = _components.begin() ; it != _components.end() ; )
    {    
        if(*it == &component)
        {
            it = _components.erase(it);
            return true;
        }
        ++it;
    }
    return false;
}

const std::vector<ItemTypeComponent*> ItemType::getComponents() const
{
    return _components;
}
