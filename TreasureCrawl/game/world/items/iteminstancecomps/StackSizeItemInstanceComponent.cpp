#include "StackSizeItemInstanceComponent.hpp"

StackSizeItemInstanceComponent::StackSizeItemInstanceComponent(const int& stackSize)
    : ItemInstanceComponent(ItemInstanceComponent::StackSizeItemInstanceComponent), _stackSize(stackSize)
{
}

StackSizeItemInstanceComponent::~StackSizeItemInstanceComponent()
{
}

ItemInstanceComponent& StackSizeItemInstanceComponent::makeCopy() const
{
    return *(new StackSizeItemInstanceComponent(_stackSize));
}

int StackSizeItemInstanceComponent::getStackSize() const
{
    return _stackSize;
}

bool StackSizeItemInstanceComponent::isSimilarTo(const ItemInstanceComponent& component) const
{
    return component.type == this->type;
}

bool StackSizeItemInstanceComponent::isEqualTo(const ItemInstanceComponent& component) const
{
    if(component.type != this->type)
    {
        return false;
    }
    return static_cast<const StackSizeItemInstanceComponent&>(component)._stackSize == _stackSize;
}
