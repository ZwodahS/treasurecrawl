#ifndef _GAME_WORLD_ITEMS_DURABILITYITEMINSTANCECOMPONENT_H_
#define _GAME_WORLD_ITEMS_DURABILITYITEMINSTANCECOMPONENT_H_
#include "../ItemInstanceComponent.hpp"
class ItemInstance;
class DurabilityItemInstanceComponent : public ItemInstanceComponent
{
public:
    DurabilityItemInstanceComponent(const int& durability = 0);
    virtual ~DurabilityItemInstanceComponent();

    int getCurrentDurability() const;

    /**
     * Required by ItemInstanceComponent
     */
    virtual bool isSimilarTo(const ItemInstanceComponent& component) const;
    virtual bool isEqualTo(const ItemInstanceComponent& component) const;
    virtual ItemInstanceComponent& makeCopy() const;

private:
    int _currentDurability;
};
#endif
