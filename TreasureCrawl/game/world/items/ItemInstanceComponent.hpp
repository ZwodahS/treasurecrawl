#ifndef _GAME_WORLD_ITEMS_ITEMINSTANCECOMPONENT_H_
#define _GAME_WORLD_ITEMS_ITEMINSTANCECOMPONENT_H_
/**
 * ItemInstanceComponent
 *
 * the abstract parent class of all the ItemInstanceComponent.
 *
 * It also stores an enum for all the possible type of ItemInstanceComponent.
 * Since components are not dynamically created, I think it is okay for me to use a enum instead of a string.
 */
class ItemInstanceComponent
{
public:
    enum Type
    {
        // Define a "quality" value for the instance.
        // Use to calculate the value of the collectable.
        // Other potential uses include weapon damage, armor defence etc.
        QualityItemInstanceComponent,
        // This is use for items that are stackable.
        StackSizeItemInstanceComponent,
        // For storing the durability of the item. Max durability is stored in item type.
        DurabilityItemInstanceComponent,
    };
    // store the type for casting to child.
    const Type type;
    
    /**
     * Constructors/Deconstructors
     */
    ItemInstanceComponent(const Type& type);
    virtual ~ItemInstanceComponent();

    // make a copy of this item instance component.
    virtual ItemInstanceComponent& makeCopy() const = 0;
    
    /**
     * Check whether this component is similar to the given component.
     * This is used by ItemInstance for similarity checking.
     * There are many potential uses for this, but primarily used for checking if an item
     * can be stack with another.
     *
     * Some ItemInstanceComponent may always return true when their type is the same.
     * For example, since this is used in stacking, even if the stack value is different, it should still be stackable.
     */
    virtual bool isSimilarTo(const ItemInstanceComponent& component) const = 0;

    /**
     * A stricter version of isSimilarTo. 
     * This compares the exact value inside the component.
     * For example, StackSizeItemInstanceComponent will return false if their stack size is different.
     * May not have use case for this, but it is here in case some component needs it in the future.
     */
    virtual bool isEqualTo(const ItemInstanceComponent& component) const = 0;
private:
};
#endif
