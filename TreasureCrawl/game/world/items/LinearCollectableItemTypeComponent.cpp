#include "LinearCollectableItemTypeComponent.hpp"
#include "ItemInstance.hpp"
#include "QualityItemInstanceComponent.hpp"
#include "StackSizeItemInstanceComponent.hpp"
LinearCollectableItemTypeComponent::LinearCollectableItemTypeComponent(const int& baseValue, const int& multiplier)
    : _baseValue(baseValue), _multiplier(multiplier)
{
}

LinearCollectableItemTypeComponent::~LinearCollectableItemTypeComponent()
{
}

int LinearCollectableItemTypeComponent::getValue(const ItemInstance& itemInstance) const
{
    ItemInstanceComponent* stack = itemInstance.getComponent(ItemInstanceComponent::StackSizeItemInstanceComponent);
    ItemInstanceComponent* quality = itemInstance.getComponent(ItemInstanceComponent::QualityItemInstanceComponent);

    int qualityInt = quality == 0 ? 0 : static_cast<QualityItemInstanceComponent*>(quality)->getQualityValue();
    int stackInt = stack == 0 ? 1 : static_cast<StackSizeItemInstanceComponent*>(stack)->getStackSize();
    return (_baseValue + (_multiplier * qualityInt)) * stackInt;
}
