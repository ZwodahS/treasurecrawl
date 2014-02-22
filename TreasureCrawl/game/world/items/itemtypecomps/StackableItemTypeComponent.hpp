#ifndef _GAME_WORLD_ITEMS_STACKABLEITEMTYPECOMPONENT_H_
#define _GAME_WORLD_ITEMS_STACKABLEITEMTYPECOMPONENT_H_
#include "../ItemTypeComponent.hpp"
/**
 * StackableItemTypeComponent
 *
 * Tells the ItemType that all instance of this ItemType is stackable, and thus have the StackSizeItemInstanceComponent.
 *
 * Stacking uses the isSimilarTo function of ItemInstance to check for similarity.
 */
class StackableItemTypeComponent : public ItemTypeComponent
{
public:
    StackableItemTypeComponent(const int& maxStackSize = -1);
    virtual ~StackableItemTypeComponent();
    
    /**
     * Get the maximum stack size for this ItemType.
     * value less than 0 = infinite.
     */
    virtual int getMaxStackSize() const;
private:
    int _maxStackSize;

};
#endif
