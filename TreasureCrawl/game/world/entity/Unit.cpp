#include "Unit.hpp"

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
