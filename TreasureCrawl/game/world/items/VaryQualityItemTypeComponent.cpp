#include "VaryQualityItemTypeComponent.hpp"

VaryQualityItemTypeComponent::VaryQualityItemTypeComponent(const int& minQuality, const int& maxQuality)
    : ItemTypeComponent(ItemTypeComponent::VaryQualityItemTypeComponent), _minQuality(minQuality), _maxQuality(maxQuality)
{
    _requiredInstanceComponentTypes.push_back(ItemInstanceComponent::QualityItemInstanceComponent);
}

VaryQualityItemTypeComponent::~VaryQualityItemTypeComponent()
{
}

std::pair<int, int> VaryQualityItemTypeComponent::getQualityRange() const
{
    return std::pair<int, int>(_minQuality, _maxQuality);
}
