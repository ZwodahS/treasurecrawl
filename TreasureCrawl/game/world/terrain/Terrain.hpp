#ifndef _GAME_WORLD_TERRAIN_H_
#define _GAME_WORLD_TERRAIN_H_
#include <SFML/Graphics.hpp>
#include "../../../z_framework/zf_common/Grid.hpp"
#include <utility>
class Unit;
class TerrainObject;
class Terrain
{
public:
    Terrain(const sf::Sprite& background);
    virtual ~Terrain();

    // draw the terrain background and symbol.
    virtual void draw(sf::RenderWindow& window);
    
    // set the grid position and the draw position
    virtual void setPosition(const zf::Grid& gridPosition, const sf::Vector2f& spritePosition);

    // get the position of this terrain object.
    std::pair<zf::Grid, sf::Vector2f> getPosition() const;

    // return false if existing terrain object forbids it or if there is an existing unit.
    bool canPutUnitIntoTerrain(Unit& unit);
    // put unit into the terrain. return false if !canPutUnitIntoTerrain(unit);
    bool putUnitIntoTerrain(Unit& unit);
    // get the unit that is on this terrain.
    Unit* getUnitInTerrain() const;
    // remove the unit from this terrain.
    Unit* removeUnitFromTerrain();

    // return false if there is an existing terrain object or if this object cannot share a space with a unit.
    bool canPutTerrainObjectIntoTerrain(TerrainObject& object);
    // put terrain object into the terrain
    bool putTerrainObjectIntoTerrain(TerrainObject& object);
    // get the terrain object on this terrain.
    TerrainObject* getTerrainObjectInTerrain() const;
    // remove the terrain object from this terrain.
    TerrainObject* removeTerrainObjectFromTerrain();
protected:
    // the positions of the terrain object
    zf::Grid _gridPosition;
    sf::Vector2f _spritePosition;

    // the sprite for this terrain object.
    sf::Sprite _background;

    // Store the unit that is currently on this terrain.
    Unit* _unit;

    TerrainObject* _terrainObject;
private:
};
#endif
