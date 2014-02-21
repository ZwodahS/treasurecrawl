#include "StackableItemTypeComponent.hpp"

StackableItemTypeComponent::StackableItemTypeComponent(const int& maxStackSize)
    : ItemTypeComponent(ItemTypeComponent::StackableItemTypeComponent), _maxStackSize(maxStackSize)
{
    // specify that any item that has this in their type, will have the stack size item instance in their instance.
    _requiredInstanceComponentTypes.push_back(ItemInstanceComponent::StackSizeItemInstanceComponent);
}

StackableItemTypeComponent::~StackableItemTypeComponent()
{
}

int StackableItemTypeComponent::getMaxStackSize() const
{
    return _maxStackSize;
}
