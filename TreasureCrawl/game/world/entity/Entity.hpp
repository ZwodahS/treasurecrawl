#ifndef _GAME_WORLD_ENTITY_ENTITY_H_
#define _GAME_WORLD_ENTITY_ENTITY_H_
/**
 * Entity is the abstract class of all the object that are on the terrain.
 * This primarily includes units like the hero, neutral, enemy, etc and terrain objects
 * like stone that can be mined, cobwebs etc. 
 *
 * Some terrains object allow you to pass through while some don't 
 *
 */
#include <SFML/Graphics.hpp>
#include "../../../z_framework/zf_common/Grid.hpp"
class Entity
{
public:
    enum EntityType
    {
        EType_Unit,
        EType_TerrainObject,
    };
    // this is used only when there is a need to downcast.
    // Since this is defined by the subclass, we will set it as constant.
    const EntityType type;

    Entity(EntityType type);
    virtual ~Entity();

    // draw this entity on the world.
    virtual void drawOnWorld(sf::RenderWindow& window) = 0;

    // set the position of this entity.
    void setPosition(const zf::Grid& gridPosition, const sf::Vector2f& spritePositon);

    // this method is called by Entity class when there is a position changed.
    // sub class MUST implement this method to be notified of the change.
    virtual void positionChanged() = 0;
protected:
    // the position of the entity.
    zf::Grid _gridPosition;
    sf::Vector2f _spritePosition;
};
#endif
