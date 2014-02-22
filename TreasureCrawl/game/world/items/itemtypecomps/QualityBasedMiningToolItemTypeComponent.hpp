#ifndef _GAME_WORLD_ITEMS_QUALITYBASEDMININGTOOLITEMTYPECOMPONENT_H_
#define _GAME_WORLD_ITEMS_QUALITYBASEDMININGTOOLITEMTYPECOMPONENT_H_
#include "MiningToolItemTypeComponent.hpp"
#include <vector>
/**
 * QualityBasedMiningToolItemTypeComponent
 *
 * defines a mining tool that its strength is based on quality.
 *
 * If the quality component do not exist (which SHOULD never be the case), then it assume to be 0
 */
class QualityBasedMiningToolItemTypeComponent : public MiningToolItemTypeComponent
{
public:
    QualityBasedMiningToolItemTypeComponent(const std::vector<int>& strengths = std::vector<int>());
    virtual ~QualityBasedMiningToolItemTypeComponent();

    virtual int getPower(const ItemInstance& itemInstance) const ;
private:
    std::vector<int> _strengths;
};
#endif
