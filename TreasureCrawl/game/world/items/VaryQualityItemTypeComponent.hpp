#ifndef _GAME_WORLD_ITEMS_VARYQUALITYITEMTYPECOMPONENT_H_
#define _GAME_WORLD_ITEMS_VARYQUALITYITEMTYPECOMPONENT_H_
#include "ItemTypeComponent.hpp"
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
class VaryQualityItemTypeComponent : public ItemTypeComponent
{
public: 
    VaryQualityItemTypeComponent(const int& minQuality = 0, const int& maxQuality = 0);
    virtual ~VaryQualityItemTypeComponent();

    /**
     * Get the range that the value for quality can be.
     */
    virtual std::pair<int, int> getQualityRange() const;

private:
    int _minQuality;
    int _maxQuality;
};
#endif
