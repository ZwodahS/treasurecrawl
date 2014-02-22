#include "FixedNameItemTypeComponent.hpp"

FixedNameItemTypeComponent::FixedNameItemTypeComponent(const std::string& name) 
    : _name(name)
{
}

FixedNameItemTypeComponent::~FixedNameItemTypeComponent()
{
}

std::string FixedNameItemTypeComponent::getName(const ItemInstance& iteminstance) const
{
    return _name;
}
