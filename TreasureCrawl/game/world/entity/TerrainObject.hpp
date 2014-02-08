#ifndef _GAME_WORLD_ENTITY_TERRAINOBJECT_H_
#define _GAME_WORLD_ENTITY_TERRAINOBJECT_H_
#include "Entity.hpp"
class TerrainObject : public Entity
{
public:
    TerrainObject(const sf::Sprite& sprite);
    virtual ~TerrainObject();

    // draw the terrain object on the world
    virtual void drawOnWorld(sf::RenderWindow& window);
    
    // over the method in parent.
    virtual void positionChanged();
private:
    // the symbol of the terrain object .
    sf::Sprite _symbol;
};
#endif
