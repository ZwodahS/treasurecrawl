#ifndef _GAME_WORLD_ITEMS_MININGTOOLITEMTYPECOMPONENT_H_
#define _GAME_WORLD_ITEMS_MININGTOOLITEMTYPECOMPONENT_H_
#include "../ItemTypeComponent.hpp"
/**
 * MiningToolItemTypeComponent
 *
 * defines a item can be used as a mining tool.
 *
 * This is the abstract parent class for all the different type of mining tools.
 * Mining tools defines a "strength" for the mining tool.
 * Other attributes can be implemented in the future if we want.
 *
 * Mining tool may have various quality.
 * Sometimes you may want to have different way to calculate the strength of the tools.
 * This is why this is done using polymorphism
 */
class ItemInstance;
class MiningToolItemTypeComponent : public ItemTypeComponent
{
public:
    MiningToolItemTypeComponent();
    virtual ~MiningToolItemTypeComponent();

    virtual int getPower(const ItemInstance& itemInstance) const = 0;
};
#endif
