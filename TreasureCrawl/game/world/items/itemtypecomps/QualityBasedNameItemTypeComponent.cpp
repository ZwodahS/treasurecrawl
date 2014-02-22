#include "QualityBasedNameItemTypeComponent.hpp"
#include "../ItemInstance.hpp"
#include "../ItemInstanceComponent.hpp"
#include "../iteminstancecomps/QualityItemInstanceComponent.hpp"
QualityBasedNameItemTypeComponent::QualityBasedNameItemTypeComponent(const std::vector<std::string>& names)
    : _names(names)
{
}

QualityBasedNameItemTypeComponent::~QualityBasedNameItemTypeComponent()
{
}

std::string QualityBasedNameItemTypeComponent::getName(const ItemInstance& itemInstance) const
{
    ItemInstanceComponent* itemComp = itemInstance.getComponent(ItemInstanceComponent::QualityItemInstanceComponent);
    if(itemComp == 0 || _names.size() == 0)
    {
        return "";
    }
    QualityItemInstanceComponent* qualityComp = static_cast<QualityItemInstanceComponent*>(itemComp);
    return qualityComp->getQualityValue() < 0 ? _names.front() : qualityComp->getQualityValue() >= _names.size() ? _names.back() : _names[qualityComp->getQualityValue()] ;
}
