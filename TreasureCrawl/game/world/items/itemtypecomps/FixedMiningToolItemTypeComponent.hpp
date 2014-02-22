#ifndef _GAME_WORLD_ITEMS_FIXEDMININGTOOLITEMTYPECOMPONENT_H_
#define _GAME_WORLD_ITEMS_FIXEDMININGTOOLITEMTYPECOMPONENT_H_
#include "MiningToolItemTypeComponent.hpp"
/**
 * FixedMiningToolItemTypeComponent
 *
 * defines a fixed value for strength of mining tool.
 */
class FixedMiningToolItemTypeComponent : public MiningToolItemTypeComponent
{
public:
    FixedMiningToolItemTypeComponent(const int& power = 0);
    virtual ~FixedMiningToolItemTypeComponent();

    virtual int getPower(const ItemInstance& itemInstance) const;
private:
    int _power;
};
#endif
