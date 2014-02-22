#ifndef _GAME_WORLD_ITEMS_VARYQUALITYITEMTYPECOMPONENT_H_
#define _GAME_WORLD_ITEMS_VARYQUALITYITEMTYPECOMPONENT_H_
#include "../ItemTypeComponent.hpp"
#include <utility>
/**
 * VaryQualityItemTypeComponent
 *
 * This tells the ItemType that the instance of the ItemType can have different quality.
 *
 * Quality can affect many things like value, or in weapon, damage.
 *
 * It is up to the different component to intepret the meaning of the quality.
 * Because of that, we choose to store a int value here instead.
 */
class ItemInstance;
class VaryQualityItemTypeComponent : public ItemTypeComponent
{
public: 
    VaryQualityItemTypeComponent(const int& minQuality = 0, const int& maxQuality = 0);
    virtual ~VaryQualityItemTypeComponent();

    /**
     * Get the range that the value for quality can be.
     */
    virtual std::pair<int, int> getQualityRange() const;


    /**
     * use this to set the quality value of this item instance.
     * return false if the intValue is out of range.
     * return false if there is no quality component. It WILL NOT attempt to create one.
     */
    bool setQualityValue(ItemInstance& itemInstance, const int& intValue) const;
private:
    /**
     * min/max inclusive/
     */
    int _minQuality;
    int _maxQuality;
};
#endif
