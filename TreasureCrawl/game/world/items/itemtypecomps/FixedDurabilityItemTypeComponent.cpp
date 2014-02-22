#include "FixedDurabilityItemTypeComponent.hpp"

FixedDurabilityItemTypeComponent::FixedDurabilityItemTypeComponent(const int& durability)
    : _durability(durability)
{
}

FixedDurabilityItemTypeComponent::~FixedDurabilityItemTypeComponent()
{
}

int FixedDurabilityItemTypeComponent::getMaxDurablity(const ItemInstance&)
{
    return _durability;
}
