#include "BreakableItemTypeComponent.hpp"

BreakableItemTypeComponent::BreakableItemTypeComponent()
    : ItemTypeComponent(ItemTypeComponent::BreakableItemTypeComponent)
{
    _requiredInstanceComponentTypes.push_back(ItemInstanceComponent::DurabilityItemInstanceComponent);
}

BreakableItemTypeComponent::~BreakableItemTypeComponent()
{
}
