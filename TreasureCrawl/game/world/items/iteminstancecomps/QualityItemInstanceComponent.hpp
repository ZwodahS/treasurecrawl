#ifndef _GAME_WORLD_ITEMS_QUALITYITEMINSTANCECOMPONENT_H_
#define _GAME_WORLD_ITEMS_QUALITYITEMINSTANCECOMPONENT_H_
#include "../ItemInstanceComponent.hpp"
/**
 * QualityItemInstanceComponent
 *
 * This stores the quality value for ItemInstance that have the VaryQualityItemTypeComponent.
 */
class QualityItemInstanceComponent : public ItemInstanceComponent
{
public: 
    /**
     * Quality range from 0 +, 0 being the lousiest
     * I could use an enum here, but I choose not to because this component might
     * be reused by various type of item, which may have different level,
     * and different meaning for each quality.
     */
    QualityItemInstanceComponent(const int& quality = 0);
    ~QualityItemInstanceComponent();

    /**
     * get the quality value of the ItemInstance
     */
    int getQualityValue() const;

    /**
     * set the quality value. Before setting, check if the value is in range of the VaryQualityItemTypeComponent
     * Or just use VaryQualityItemTypeComponent to set instead.
     */
    void setQualityValue(const int& value);

    /**
     * Required by ItemTypeComponent
     */
    ItemInstanceComponent& makeCopy() const;
    virtual bool isSimilarTo(const ItemInstanceComponent& component) const;
    virtual bool isEqualTo(const ItemInstanceComponent& component) const;

private:
    int _quality;
};
#endif
