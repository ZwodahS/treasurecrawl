#ifndef _GAME_WORLD_ITEMS_NAMEITEMTYPECOMPONENT_H_
#define _GAME_WORLD_ITEMS_NAMEITEMTYPECOMPONENT_H_
#include "../ItemTypeComponent.hpp"
/**
 * NameItemTypeComponent
 *
 * defines the get name for instance.
 *
 * This is the abstract parent class for all name definition.
 * The use for this is simple.
 * 
 * You could have different way to name the item based on the different quantity.
 * Like for example, if you have a low quality emerald, you may want to call it "Emerald Shards"
 * while higher quality emerald can be called "Perfect Emerald"
 * 
 * You also can have different name for weapon with different enchantment.
 * For example, a sword with a quickness enchantment + a fire enchantment can be named
 * " Fire sword of quickness " 
 * 
 * Other uses include localization.
 */
class ItemInstance;
class NameItemTypeComponent : public ItemTypeComponent
{
public:
    NameItemTypeComponent();
    virtual ~NameItemTypeComponent();
    
    virtual std::string getName(const ItemInstance& itemInstance) const = 0;
private:
};
#endif
