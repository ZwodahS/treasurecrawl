#ifndef _GAME_WORLD_ITEMS_STACKSIZEITEMINSTANCECOMPONENT_H_
#define _GAME_WORLD_ITEMS_STACKSIZEITEMINSTANCECOMPONENT_H_
#include "../ItemInstanceComponent.hpp"
/**
 * StackSizeItemInstanceComponent
 *
 * This stores the stack value for ItemInstance that are stackable.
 */
class StackSizeItemInstanceComponent : public ItemInstanceComponent
{
public:
    StackSizeItemInstanceComponent(const int& stackSize = 0);
    ~StackSizeItemInstanceComponent();

    /**
     * Get the stack size of this ItemInstance.
     */
    int getStackSize() const;

    /**
     * Required by ItemInstanceComponent
     */
    virtual bool isSimilarTo(const ItemInstanceComponent& component) const;
    virtual bool isEqualTo(const ItemInstanceComponent& component) const;
    ItemInstanceComponent& makeCopy() const;
private:
    int _stackSize;
};
#endif
