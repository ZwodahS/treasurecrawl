#include "VaryQualityItemTypeComponent.hpp"
#include "../ItemInstance.hpp"
#include "../ItemInstanceComponent.hpp"
#include "../iteminstancecomps/QualityItemInstanceComponent.hpp"
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

bool VaryQualityItemTypeComponent::setQualityValue(ItemInstance& itemInstance, const int& intValue) const
{
    if(intValue < _minQuality || intValue > _maxQuality)
    {
        return false;
    }
    ItemInstanceComponent* qualityComponent = itemInstance.getComponent(ItemInstanceComponent::QualityItemInstanceComponent);
    if(qualityComponent == 0)
    {
        return false;
    }
    static_cast<QualityItemInstanceComponent*>(qualityComponent)->setQualityValue(intValue);
    return true;
}
