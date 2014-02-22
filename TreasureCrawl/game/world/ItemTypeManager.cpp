#include "ItemTypeManager.hpp"
ItemTypeManager::ItemTypeManager()
{
}

ItemTypeManager::~ItemTypeManager()
{
}

void ItemTypeManager::load()
{
    std::vector<std::string> names;
    // create a simple gem item type
    ItemType* item = 0;
    // ruby 
    item = new ItemType("item_gem_ruby");
    item->addComponent(makeCollectableItemTypeComponent(5, 5));
    item->addComponent(makeVaryQualityItemTypeComponent(0, 4));
    std::string ruby_names[]= {"Ruby Fragments", "Ruby Chunks", "Round Ruby", "Flawless Ruby", "Perfect Ruby" };
    item->addComponent(makeNameItemTypeComponent(std::vector<std::string>(ruby_names, ruby_names + 5)));
    item->addComponent(makeStackableItemTypeComponent());
    addItemType(*item);

    // emerald
    item = new ItemType("item_gem_emerald");
    item->addComponent(makeCollectableItemTypeComponent(5, 5));
    item->addComponent(makeVaryQualityItemTypeComponent(0, 4));
    std::string emerald_names[]= {"Emerald Fragments", "Emerald Chunks", "Round Emerald", "Flawless Emerald", "Perfect Emerald" };
    item->addComponent(makeNameItemTypeComponent(std::vector<std::string>(emerald_names, emerald_names + 5)));
    item->addComponent(makeStackableItemTypeComponent());
    addItemType(*item);

    // sapphire
    item = new ItemType("item_gem_sapphire");
    item->addComponent(makeCollectableItemTypeComponent(5, 5));
    item->addComponent(makeVaryQualityItemTypeComponent(0, 4));
    std::string sapphire_names[]= {"Sapphire Fragments", "Sapphire Chunks", "Round Sapphire", "Flawless Sapphire", "Perfect Sapphire" };
    item->addComponent(makeNameItemTypeComponent(std::vector<std::string>(sapphire_names, sapphire_names + 5)));
    item->addComponent(makeStackableItemTypeComponent());
    addItemType(*item);

    // create 2 pickaxe, a simple 1 with a fix mining strength (Basic Pickaxe) and a advanced one (Iron Pickaxe)

    item = new ItemType("item_pickaxe_basic");
    item->addComponent(makeMiningToolItemTypeComponent(1)); // mining power of 1
    item->addComponent(makeBreakableItemTypeComponent(10)); // fixed durability of 10
    item->addComponent(makeNameItemTypeComponent("Basic Pickaxe")); // this pickaxe has a fixed name
    addItemType(*item);

    item = new ItemType("item_pickaxe_iron");
    int iron_pickaxe_strengths[] = {2, 3, 4, 5, 6};
    item->addComponent(makeVaryQualityItemTypeComponent(0, 4));
    item->addComponent(makeMiningToolItemTypeComponent(std::vector<int>(iron_pickaxe_strengths, iron_pickaxe_strengths + 5)));
    item->addComponent(makeBreakableItemTypeComponent(20));
    std::string iron_pickaxe_names[] = {"Iron Pickaxe", "Refined Iron Pickaxe", "Well-crafted Iron Pickaxe", "Enhanced Iron Pickaxe", "Perfectly-crafted Iron Pickaxe"};
    item->addComponent(makeNameItemTypeComponent(std::vector<std::string>(iron_pickaxe_names, iron_pickaxe_names + 5)));
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

ItemTypeComponent& ItemTypeManager::makeStackableItemTypeComponent(const int& maxStackSize) const
{
    return *(new StackableItemTypeComponent(maxStackSize));
}

ItemTypeComponent& ItemTypeManager::makeVaryQualityItemTypeComponent(const int& minQuality, const int& maxQuality) const
{
    return *(new VaryQualityItemTypeComponent(minQuality, maxQuality));
}

ItemTypeComponent& ItemTypeManager::makeNameItemTypeComponent(const std::vector<std::string> names) const
{
    return *(new QualityBasedNameItemTypeComponent(names));
}

ItemTypeComponent& ItemTypeManager::makeNameItemTypeComponent(const std::string& name) const
{
    return *(new FixedNameItemTypeComponent(name));
}

ItemTypeComponent& ItemTypeManager::makeMiningToolItemTypeComponent(const int& strength) const
{
    return *(new FixedMiningToolItemTypeComponent(strength));
}

ItemTypeComponent& ItemTypeManager::makeMiningToolItemTypeComponent(const std::vector<int> strengths) const
{
    return *(new QualityBasedMiningToolItemTypeComponent(strengths));
}

ItemTypeComponent& ItemTypeManager::makeBreakableItemTypeComponent(const int& maxDurability) const
{
    return *(new FixedDurabilityItemTypeComponent(maxDurability));
}

ItemInstanceComponent& ItemTypeManager::makeItemInstanceComponent(ItemInstanceComponent::Type type) const
{
    switch(type)
    {
        case ItemInstanceComponent::QualityItemInstanceComponent :
            return *(new QualityItemInstanceComponent());
        case ItemInstanceComponent::StackSizeItemInstanceComponent :
            return *(new StackSizeItemInstanceComponent());
        case ItemInstanceComponent::DurabilityItemInstanceComponent :
            return *(new DurabilityItemInstanceComponent());
    }
}

