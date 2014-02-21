#ifndef _GAME_WORLD_ITEMS_LINEARCOLLECTABLEITEMTYPECOMPONENT_H_
#define _GAME_WORLD_ITEMS_LINEARCOLLECTABLEITEMTYPECOMPONENT_H_
#include "CollectableItemTypeComponent.hpp"
/**
 * LinearCollectableItemTypeComponent
 *
 * This is an concrete class of CollectableItemTypeComponent.
 * It defines a linear function to determine the value of the gem based on quality and stack.
 */
class LinearCollectableItemTypeComponent : public CollectableItemTypeComponent
{
public:
    LinearCollectableItemTypeComponent(const int& baseValue = 0, const int& multiplier = 0);
    ~LinearCollectableItemTypeComponent();

    /* 
     * make use of StackSizeItemInstanceComponent and QualityItemInstanceComponent
     */
    int getValue(const ItemInstance& itemInstance) const;
private:
    int _baseValue; // the base value of this collectable
    int _multiplier; // the multiplier per level of grade for this collectable.
};
#endif
