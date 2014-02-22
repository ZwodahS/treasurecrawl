#ifndef _GAME_WORLD_ITEMS_FIXEDNAMEITEMTYPECOMPONENT_H_
#define _GAME_WORLD_ITEMS_FIXEDNAMEITEMTYPECOMPONENT_H_
#include "NameItemTypeComponent.hpp"
#include <string>
/**
 * FixedNameItemTypeComponent
 *
 * Defines a fixed name for this item type.
 */
class FixedNameItemTypeComponent : public NameItemTypeComponent
{
public:
    FixedNameItemTypeComponent(const std::string& name);
    virtual ~FixedNameItemTypeComponent();

    virtual std::string getName(const ItemInstance& itemInstance) const;

private:
    std::string _name;
};
#endif
