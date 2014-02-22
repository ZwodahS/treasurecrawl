#ifndef _GAME_WORLD_ITEMS_QUALITYBASEDNAMEITEMCOMPONENT_H_
#define _GAME_WORLD_ITEMS_QUALITYBASEDNAMEITEMCOMPONENT_H_
#include "NameItemTypeComponent.hpp"
#include <vector>
#include <string>
/**
 * QualityBasedNameItemTypeComponent
 *
 * Defines a name for every quality of the item.
 *
 * it will return _names[0] for quality < 0, and last name value if the quality exceed the size of _names.
 * If _names.size() == 0, then it will return empty string.
 */
class QualityBasedNameItemTypeComponent : public NameItemTypeComponent
{
public:
    QualityBasedNameItemTypeComponent(const std::vector<std::string>& names);
    virtual ~QualityBasedNameItemTypeComponent();

    virtual std::string getName(const ItemInstance& itemInstance) const;
private:
    
    std::vector<std::string> _names;    
};
#endif
