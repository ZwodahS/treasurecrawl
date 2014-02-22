#ifndef _GAME_WORLD_ITEMS_FIXEDDURABILITYITEMTYPECOMPONENT_H_
#define _GAME_WORLD_ITEMS_FIXEDDURABILITYITEMTYPECOMPONENT_H_
#include "BreakableItemTypeComponent.hpp"
class FixedDurabilityItemTypeComponent : public BreakableItemTypeComponent
{
public:
    FixedDurabilityItemTypeComponent(const int& durability);
    virtual ~FixedDurabilityItemTypeComponent();

    virtual int getMaxDurablity(const ItemInstance& itemInstance);
private:
    int _durability;
};
#endif
