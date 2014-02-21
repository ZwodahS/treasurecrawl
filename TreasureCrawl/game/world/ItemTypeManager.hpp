#ifndef _GAME_WORLD_ITEMTYPEMANAGER_H_
#define _GAME_WORLD_ITEMTYPEMANAGER_H_
#include <map>
#include <vector>

#include "items/ItemTypeComponent.hpp"
#include "items/ItemInstanceComponent.hpp"
class ItemType;
class ItemInstance;
class ItemTypeManager
{
public:
    ItemTypeManager();
    ~ItemTypeManager();

    void load();

    ItemType* getItemType(const std::string unique_name) const;

    ItemInstance* makeItemInstance(const std::string unique_name) const;
private:
    std::map<std::string, ItemType*> _itemTypes;

    void addItemType(ItemType& type);

    /***
     * All the ItemType specific component.
     */
    ItemTypeComponent& makeCollectableItemTypeComponent(const int& baseValue, const int& multiplier) const;

    /**
     * Create a default component of this type.
     * This will call the empty constructor
     */
    ItemInstanceComponent& makeItemInstanceComponent(ItemInstanceComponent::Type type) const;
};
#endif
