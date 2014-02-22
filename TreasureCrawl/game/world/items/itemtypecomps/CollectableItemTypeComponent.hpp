#ifndef _GAME_WORLD_ITEMS_COLLECTABLECOMPONENT_H_
#define _GAME_WORLD_ITEMS_COLLECTABLECOMPONENT_H_
#include "../ItemTypeComponent.hpp"
/**
 * CollectableItemTypeComponent
 *
 * defines the scoring mechanism for the game.
 *
 * This class is an abstract class.
 * Different valuation functions can be implemented for different type of items.
 */
class ItemInstance;
class CollectableItemTypeComponent : public ItemTypeComponent
{
public:
    CollectableItemTypeComponent();
    virtual ~CollectableItemTypeComponent();

    /**
     * get the value for this ItemInstance.
     */
    virtual int getValue(const ItemInstance& itemInstance) const = 0;
private:
};
#endif
