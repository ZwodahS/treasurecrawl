#include "QualityItemInstanceComponent.hpp"

QualityItemInstanceComponent::QualityItemInstanceComponent(const int& quality)
    : ItemInstanceComponent(ItemInstanceComponent::QualityItemInstanceComponent), _quality(quality)
{
}

QualityItemInstanceComponent::~QualityItemInstanceComponent()
{
}

ItemInstanceComponent& QualityItemInstanceComponent::makeCopy() const
{
    return *(new QualityItemInstanceComponent(_quality));
}

int QualityItemInstanceComponent::getQualityValue() const
{
    return _quality;
}

bool QualityItemInstanceComponent::isSimilarTo(const ItemInstanceComponent& component) const
{
    return isEqualTo(component);
}

bool QualityItemInstanceComponent::isEqualTo(const ItemInstanceComponent& component) const
{
    if(component.type != this->type)
    {
        return false;
    }
    return static_cast<const QualityItemInstanceComponent&>(component)._quality == _quality;
}
