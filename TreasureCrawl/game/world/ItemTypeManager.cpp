#include "ItemTypeManager.hpp"
#include "items/ItemType.hpp"

#include "items/CollectableItemTypeComponent.hpp"
#include "items/LinearCollectableItemTypeComponent.hpp"

#include "items/ItemInstance.hpp"

#include "items/QualityItemInstanceComponent.hpp"
#include "items/StackSizeItemInstanceComponent.hpp"
ItemTypeManager::ItemTypeManager()
{
}

ItemTypeManager::~ItemTypeManager()
{
}

void ItemTypeManager::load()
{
    // create a simple gem item type
    ItemType* item = 0;
    // ruby 
    item = new ItemType("item_gem_ruby");
    item->addComponent(makeCollectableItemTypeComponent(5, 5));
    addItemType(*item);

    // emerald
    item = new ItemType("item_gem_emerald");
    item->addComponent(makeCollectableItemTypeComponent(5, 5));
    addItemType(*item);

    // sapphire
    item = new ItemType("item_gem_sapphire");
    item->addComponent(makeCollectableItemTypeComponent(5, 5));
    addItemType(*item);
}

ItemType* ItemTypeManager::getItemType(const std::string unique_name) const
{
    std::map<std::string, ItemType*>::const_iterator it = _itemTypes.find(unique_name);
    return it == _itemTypes.end() ? 0 : (*it).second;
}

ItemInstance* ItemTypeManager::makeItemInstance(const std::string unique_name) const
{
    ItemType* type = getItemType(unique_name);
    if(type == 0)
    {
        return 0;
    }
    ItemInstance* instance = new ItemInstance(*type);
    // iterate through all the ItemTypeComponent in this item type, 
    // for each of them, get their required component and create a default component
    // and add it to the instance.
    const std::vector<ItemTypeComponent*> components = (*type).getComponents();
    for(std::vector<ItemTypeComponent*>::const_iterator it = components.begin() ; it != components.end() ; ++it)
    {
        std::vector<ItemInstanceComponent::Type> requiredTypes = (**it).getRequiredInstanceComponents();
        for(std::vector<ItemInstanceComponent::Type>::const_iterator reqType = requiredTypes.begin() ; reqType != requiredTypes.end() ; ++reqType)
        {
            // Make sure there is no duplicate.
            if(instance->hasComponent(*reqType))
            {
                continue;
            }
            instance->addComponent(makeItemInstanceComponent(*reqType));
        }
    }
    return instance;
}

void ItemTypeManager::addItemType(ItemType& type)
{
    _itemTypes.insert(std::pair<std::string, ItemType*>(type.uniqueId, &type));
}

ItemTypeComponent& ItemTypeManager::makeCollectableItemTypeComponent(const int& baseValue, const int& multiplier) const
{
    return *(new LinearCollectableItemTypeComponent(baseValue, multiplier));
}

ItemInstanceComponent& ItemTypeManager::makeItemInstanceComponent(ItemInstanceComponent::Type type) const
{
    switch(type)
    {
        case ItemInstanceComponent::QualityItemInstanceComponent :
            return *(new QualityItemInstanceComponent());
        case ItemInstanceComponent::StackSizeItemInstanceComponent :
            return *(new StackSizeItemInstanceComponent());
    }
}

