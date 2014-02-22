#include "../ItemInstance.hpp"
#include "../ItemInstanceComponent.hpp"
#include "QualityBasedMiningToolItemTypeComponent.hpp"
#include "../iteminstancecomps/QualityItemInstanceComponent.hpp"
QualityBasedMiningToolItemTypeComponent::QualityBasedMiningToolItemTypeComponent(const std::vector<int>& strengths)
    : _strengths(strengths)
{
}

QualityBasedMiningToolItemTypeComponent::~QualityBasedMiningToolItemTypeComponent()
{
}

int QualityBasedMiningToolItemTypeComponent::getPower(const ItemInstance& itemInstance) const
{
    if(_strengths.size() == 0)
    {
        return 0;
    }
    ItemInstanceComponent* comp = itemInstance.getComponent(ItemInstanceComponent::QualityItemInstanceComponent);
    int quality = comp == 0 ? 0 : static_cast<QualityItemInstanceComponent*>(comp)->getQualityValue();
    return quality < 0 ? _strengths.front() : quality >= _strengths.size() ? _strengths.back() : _strengths[quality];
}
