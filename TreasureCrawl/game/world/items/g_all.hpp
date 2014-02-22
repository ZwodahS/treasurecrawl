/**
 * This is just the header for World to use to include all the type, component , instancecomponent etc.
 */

/*****************************************
 * Item Type 
 *****************************************/
#include "ItemType.hpp"
/**
 * Parent ItemType Component
 */
#include "ItemTypeComponent.hpp"
/**
 * Collectable ItemTypeComponent and its children
 */
#include "itemtypecomps/CollectableItemTypeComponent.hpp"
#include "itemtypecomps/LinearCollectableItemTypeComponent.hpp"
/**
 * Name ItemTypeComponent and its children
 */
#include "itemtypecomps/NameItemTypeComponent.hpp"
#include "itemtypecomps/QualityBasedNameItemTypeComponent.hpp"
#include "itemtypecomps/FixedNameItemTypeComponent.hpp"
/**
 * Stackable ItemTypeComponent
 */
#include "itemtypecomps/StackableItemTypeComponent.hpp"
/**
 * Vary ItemTypeComponent
 */
#include "itemtypecomps/VaryQualityItemTypeComponent.hpp"
/**
 * MiningTool ItemTypeComponent and its children
 */
#include "itemtypecomps/MiningToolItemTypeComponent.hpp"
#include "itemtypecomps/FixedMiningToolItemTypeComponent.hpp"
#include "itemtypecomps/QualityBasedMiningToolItemTypeComponent.hpp"
/**
 * Breakable ItemTypeComponent and its children
 */
#include "itemtypecomps/BreakableItemTypeComponent.hpp"
#include "itemtypecomps/FixedDurabilityItemTypeComponent.hpp"

/*****************************************
 * Item Instance
 *****************************************/
#include "ItemInstance.hpp"
/**
 * Parent ItemInstance Component
 */
#include "ItemInstanceComponent.hpp"
/**
 * Quality ItemInstanceComponent
 */
#include "iteminstancecomps/QualityItemInstanceComponent.hpp"
/**
 * StackSize ItemInstanceComponent
 */
#include "iteminstancecomps/StackSizeItemInstanceComponent.hpp"
/**
 * Durability ItemInstanceComponent
 */
#include "iteminstancecomps/DurabilityItemInstanceComponent.hpp"
