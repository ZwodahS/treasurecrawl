#include "ItemInstance.hpp"
#include "ItemType.hpp"


ItemInstance::ItemInstance(const ItemType& t)
    : type(t)
{
}

ItemInstance::~ItemInstance()
{
    for(std::vector<ItemInstanceComponent*>::iterator it = _components.begin() ; it != _components.end() ; ++it)
    {
        delete *it;
    }
}

void ItemInstance::addComponent(ItemInstanceComponent& component)
{
    _components.push_back(&component);
}

ItemInstanceComponent* ItemInstance::getComponent(const ItemInstanceComponent::Type& type) const
{
    for(std::vector<ItemInstanceComponent*>::const_iterator it = _components.begin() ; it != _components.end() ; ++it)
    {
        if((**it).type == type)
        {
            return *it;
        }
    }
    return 0;
}

bool ItemInstance::hasComponent(const ItemInstanceComponent::Type& type) const
{
    return getComponent(type) != 0;
}

bool ItemInstance::removeComponent(ItemInstanceComponent& component)
{
    for(std::vector<ItemInstanceComponent*>::iterator it = _components.begin() ; it != _components.end() ; )
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

bool ItemInstance::isSimilarTo(const ItemInstance& instance) const
{
    if(&this->type != &instance.type)
    {
        return false;
    }
    // we can guaranteed that their list of component is the same.
    for(std::vector<ItemInstanceComponent*>::const_iterator it = _components.begin() ; it != _components.end() ; ++it)
    {
        ItemInstanceComponent* component = instance.getComponent((**it).type);
        if(component == 0 || !(component->isSimilarTo(**it)))
        {
            return false;
        }
    }
    return true;
}

bool ItemInstance::isEqualTo(const ItemInstance& instance) const
{
    if(&this->type != &instance.type)
    {
        return false;
    }
    // we can guaranteed that their list of component is the same.
    for(std::vector<ItemInstanceComponent*>::const_iterator it = _components.begin() ; it != _components.end() ; ++it)
    {
        ItemInstanceComponent* component = instance.getComponent((**it).type);
        if(component == 0 || !(component->isEqualTo(**it)))
        {
            return false;
        }
    }
    return true;
}
