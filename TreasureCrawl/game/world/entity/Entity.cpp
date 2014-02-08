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
