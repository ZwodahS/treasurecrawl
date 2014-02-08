#include "TerrainObject.hpp"

TerrainObject::TerrainObject(const sf::Sprite& symbol)
    : Entity(EType_TerrainObject), _symbol(symbol)
{
}

TerrainObject::~TerrainObject()
{
}

void TerrainObject::drawOnWorld(sf::RenderWindow& window)
{
    window.draw(_symbol);
}

void TerrainObject::positionChanged()
{
    _symbol.setPosition(_spritePosition);
}
