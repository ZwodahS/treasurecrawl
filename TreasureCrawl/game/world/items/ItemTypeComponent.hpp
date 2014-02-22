#ifndef _GAME_WORLD_ITEMS_ITEMTYPECOMPONENT
#define _GAME_WORLD_ITEMS_ITEMTYPECOMPONENT
#include "ItemInstanceComponent.hpp"
#include <vector>
/**
 * ItemTypeComponent
 *
 * This is the abstract parent class of all ItemTypeComponent.
 * 
 * it stores an enum of all the possible component in the game.
 * Since components are not dynamically loaded, I think it is okay to store it as a enum instead of a string.
 */
class ItemTypeComponent
{
public:
    enum Type
    {
        // The component for the gems and ore. 
        // Contains the method to get the value of the ores.
        CollectableItemTypeComponent,
        // Mark this type of item as stackable. Also specifies the max stack size. | creates StackSizeItemInstanceComponent
        StackableItemTypeComponent,
        // State that this object can come in various quality. | creates QualityItemInstanceComponent
        VaryQualityItemTypeComponent,
        // Defines the name of the items.
        NameItemTypeComponent,
        // For Tools that can be used for mining.
        MiningToolItemComponent,
        // For items that will degrade over time/uses. | create DurabilityItemInstanceComponent
        BreakableItemTypeComponent,

    };

    ItemTypeComponent(const Type& type);
    virtual ~ItemTypeComponent();

    /**
     * The type of child class.
     * Used for casting purposes.
     */
    const Type type;

    /**
     * get the list of required instance components for this ItemTypeComponent.
     */
    const std::vector<ItemInstanceComponent::Type> getRequiredInstanceComponents() const;
protected:
    std::vector<ItemInstanceComponent::Type> _requiredInstanceComponentTypes;
private:
};
#endif
