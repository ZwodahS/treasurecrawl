#include "Unit.hpp"
#include "../terrain/Terrain.hpp"
Unit::Unit(const sf::Sprite& symbol)
    : Entity(EType_Unit), _symbol(symbol)
{
}

Unit::~Unit()
{
}

void Unit::drawOnWorld(sf::RenderWindow& window)
{
    window.draw(_symbol);
}

void Unit::positionChanged()
{
    _symbol.setPosition(_spritePosition);
}

int Unit::getVisionRange()
{
    return 10;
}

bool Unit::canSee(const Terrain& terrain)
{
    return terrain.isLit();
}

bool Unit::canSeeThrough(const Terrain& terrain)
{
    return !terrain.hasVisionBlocker();
}
