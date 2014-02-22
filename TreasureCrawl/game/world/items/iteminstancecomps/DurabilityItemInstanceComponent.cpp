#include "../ItemInstance.hpp"
#include "DurabilityItemInstanceComponent.hpp"
DurabilityItemInstanceComponent::DurabilityItemInstanceComponent(const int& durability)
    : ItemInstanceComponent(ItemInstanceComponent::DurabilityItemInstanceComponent), _currentDurability(durability)
{
}

DurabilityItemInstanceComponent::~DurabilityItemInstanceComponent()
{
}

int DurabilityItemInstanceComponent::getCurrentDurability() const
{
    return _currentDurability;
};

bool DurabilityItemInstanceComponent::isSimilarTo(const ItemInstanceComponent& component) const
{
    return isEqualTo(component);
}

bool DurabilityItemInstanceComponent::isEqualTo(const ItemInstanceComponent& component) const
{
    if(component.type != this->type)
    {
        return false;
    }
    return static_cast<const DurabilityItemInstanceComponent&>(component)._currentDurability == _currentDurability;
}

ItemInstanceComponent& DurabilityItemInstanceComponent::makeCopy() const
{
    return *(new DurabilityItemInstanceComponent(_currentDurability));
}
