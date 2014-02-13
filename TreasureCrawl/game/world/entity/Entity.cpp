#include "Entity.hpp"

Entity::Entity(EntityType t)
    : type(t)
{
}

Entity::~Entity()
{
}

void Entity::setPosition(const zf::Grid& gridPosition, const sf::Vector2f& spritePosition)
{
    _gridPosition = gridPosition;
    _spritePosition = spritePosition;
    positionChanged();
}

void Entity::setZPosition(const int& position)
{
    _zPosition = position;
    positionChanged();
}

const zf::Grid& Entity::getGridPosition() const
{
    return _gridPosition;
}

const int& Entity::getZPosition() const
{
    return _zPosition;
}
