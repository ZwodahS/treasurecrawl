#ifndef _GAME_WORLD_ITEMS_BREAKABLEITEMTYPECOMPONENT_H_
#define _GAME_WORLD_ITEMS_BREAKABLEITEMTYPECOMPONENT_H_
#include "../ItemTypeComponent.hpp"
/**
 * BreakableItemTypeComponent
 *
 * This components is for items can will break after multiple uses or over time. 
 * It adds a durability component to the ItemInstances.
 */
class ItemInstance;
class BreakableItemTypeComponent : public ItemTypeComponent
{
public:
    BreakableItemTypeComponent();
    virtual ~BreakableItemTypeComponent();

    virtual int getMaxDurablity(const ItemInstance& itemInstance) = 0;
private:
};
#endif
