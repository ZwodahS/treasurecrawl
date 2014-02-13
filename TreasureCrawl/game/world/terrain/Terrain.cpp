#include "Terrain.hpp"
#include "../entity/Unit.hpp"
#include "../entity/TerrainObject.hpp"
Terrain::Terrain(const sf::Sprite& background)
    : _gridPosition(0, 0), _spritePosition(0, 0), _background(background), _unit(0), _terrainObject(0)
{
}

Terrain::~Terrain()
{
}

void Terrain::draw(sf::RenderWindow& window)
{
    window.draw(_background);
    if(_unit != 0)
    {
        _unit->drawOnWorld(window);
    }
    else if(_terrainObject != 0)
    {
        _terrainObject->drawOnWorld(window);
    }
}

void Terrain::setPosition(const zf::Grid& gridPosition, const sf::Vector2f& spritePosition)
{
    _gridPosition = gridPosition;
    _spritePosition = spritePosition;
    _background.setPosition(_spritePosition);
    if(_unit != 0)
    {
        _unit->setPosition(gridPosition, spritePosition);
    }
    if(_terrainObject != 0)
    {
        _terrainObject->setPosition(gridPosition, spritePosition);
    }
}

std::pair<zf::Grid, sf::Vector2f> Terrain::getPosition() const
{
    return std::pair<zf::Grid, sf::Vector2f>(_gridPosition, _spritePosition);
}

bool Terrain::canPutUnitIntoTerrain(Unit& unit)
{
    if(_unit != 0)
    {
        return false;
    }
    //TODO , check if the terrain object forbids it.
    if(_terrainObject != 0)
    {
        return false;
    }
    return true;
}

bool Terrain::putUnitIntoTerrain(Unit& unit)
{
    if(!canPutUnitIntoTerrain(unit))
    {
        return false;
    }
    _unit = &unit;
    return true;
}

Unit* Terrain::getUnitInTerrain() const
{
    return _unit;
}

Unit* Terrain::removeUnitFromTerrain() 
{
    Unit* temp = _unit;
    _unit = 0 ;
    return temp;
}

bool Terrain::canPutTerrainObjectIntoTerrain(TerrainObject& object)
{
    if(_terrainObject != 0)
    {
        return false;
    }
    // TODO : Check for unit and object collision
    return true;
}

bool Terrain::putTerrainObjectIntoTerrain(TerrainObject& object)
{
    if(!canPutTerrainObjectIntoTerrain(object))
    {
        return false;
    }
    _terrainObject = &object;
    return true;
}

TerrainObject* Terrain::getTerrainObjectInTerrain() const
{
    return _terrainObject;
}

TerrainObject* Terrain::removeTerrainObjectFromTerrain() 
{
    TerrainObject* temp = _terrainObject;
    _terrainObject = 0 ;
    return temp;
}

