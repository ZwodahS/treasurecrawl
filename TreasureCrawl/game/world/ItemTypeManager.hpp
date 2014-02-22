#ifndef _GAME_WORLD_ITEMTYPEMANAGER_H_
#define _GAME_WORLD_ITEMTYPEMANAGER_H_
#include <map>
#include <vector>

#include "items/g_all.hpp"
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

    ItemTypeComponent& makeStackableItemTypeComponent(const int& maxStackSize = -1) const;

    ItemTypeComponent& makeVaryQualityItemTypeComponent(const int& minQuality = 0, const int& maxQuality = 0) const;

    ItemTypeComponent& makeNameItemTypeComponent(const std::vector<std::string> names) const;
    ItemTypeComponent& makeNameItemTypeComponent(const std::string& name) const;

    ItemTypeComponent& makeMiningToolItemTypeComponent(const int& strength) const;
    ItemTypeComponent& makeMiningToolItemTypeComponent(const std::vector<int> strengths) const;

    ItemTypeComponent& makeBreakableItemTypeComponent(const int& maxDurability) const;

    /**
     * Create a default component of this type.
     * This will call the empty constructor
     */
    ItemInstanceComponent& makeItemInstanceComponent(ItemInstanceComponent::Type type) const;
};
#endif
