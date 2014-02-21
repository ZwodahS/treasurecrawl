#include "ItemTypeComponent.hpp"

ItemTypeComponent::ItemTypeComponent(const Type& t)
    : type(t)
{
}

ItemTypeComponent::~ItemTypeComponent()
{
}

const std::vector<ItemInstanceComponent::Type> ItemTypeComponent::getRequiredInstanceComponents() const
{
    return _requiredInstanceComponentTypes;
}
