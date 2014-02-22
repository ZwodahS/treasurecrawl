#include "FixedMiningToolItemTypeComponent.hpp"

FixedMiningToolItemTypeComponent::FixedMiningToolItemTypeComponent(const int& power)
    : _power(power)
{
}

FixedMiningToolItemTypeComponent::~FixedMiningToolItemTypeComponent()
{
}

int FixedMiningToolItemTypeComponent::getPower(const ItemInstance& itemInstance) const
{
    return _power;
}
