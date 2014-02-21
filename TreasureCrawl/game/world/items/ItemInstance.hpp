#ifndef _GAME_WORLD_ITEMS_ITEMINSTANCE_H_
#define _GAME_WORLD_ITEMS_ITEMINSTANCE_H_
#include "ItemInstanceComponent.hpp"
#include <vector>
/**
 * ItemInstance
 *
 * defines an instance of an ItemType.
 * It is also a container for all the ItemInstanceComponent.
 */
class ItemType;
class ItemInstance
{
public:
    ItemInstance(const ItemType& type);
    ~ItemInstance();

    /**
     * The ItemType for this instance.
     */
    const ItemType& type;
    /* 
     * add a new component to this item instance.
     * No check for duplicated component type.
     */
    void addComponent(ItemInstanceComponent& component);
    /* 
     * get the component of this type.
     * if multiplie exists, returns the first.
     */
    ItemInstanceComponent* getComponent(const ItemInstanceComponent::Type& type) const;
    /* 
     * check if the instance have this component
     */
    bool hasComponent(const ItemInstanceComponent::Type& type) const;

    /**
     * remove this component from this instance. 
     * return true if the component exists inside this item instance.
     * memory is freed elsewhere, not here
     */
    bool removeComponent(ItemInstanceComponent& component);

    /**
     * check if this item instance is similar as another
     */
    bool isSimilarTo(const ItemInstance& instance) const;
    /**
     * check if this item instance is equal to another
     */
    bool isEqualTo(const ItemInstance& instance) const;
private:
    /**
     * Store the list of ItemInstanceComponent.
     * TODO : change to map later.
     */
    std::vector<ItemInstanceComponent*> _components;
};
#endif
