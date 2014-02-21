#ifndef _GAME_WORLD_ITEMS_ITEMTYPE_H_
#define _GAME_WORLD_ITEMS_ITEMTYPE_H_
/**
 * ItemType
 *
 * This is the type definition for all the possible item types in the game.
 *
 * It stores all the components for this ItemType.
 */
#include "ItemTypeComponent.hpp"
#include <vector>
#include <string>
class ItemType
{
public:
    ItemType(std::string uniqueId);
    virtual ~ItemType();

    /* 
     * the unique identifier for this item type.
     */
    const std::string uniqueId;
    /* 
     * add a new component of this type
     */
    void addComponent(ItemTypeComponent& component);
    /* 
     * get the component of this type.
     * We assumme now that now we only have one type of this component.
     */
    ItemTypeComponent* getComponent(const ItemTypeComponent::Type& type) const;
    /* 
     * check if the itemtype has this component.
     */
    bool hasComponent(const ItemTypeComponent::Type& type) const;
    /* remove this component from the item.
     * true if it exist inside this itemtype, else false.
     */
    bool removeComponent(ItemTypeComponent& component);
    /**
     * get the list of component for this item type.
     */
    const std::vector<ItemTypeComponent*> getComponents() const;    
private:
    std::vector<ItemTypeComponent*> _components;
};
#endif
