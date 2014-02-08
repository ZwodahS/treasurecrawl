#ifndef _GAME_WORLD_ENTITY_UNIT_H_
#define _GAME_WORLD_ENTITY_UNIT_H_
#include "Entity.hpp"
class Unit : public Entity
{
public:
    Unit(const sf::Sprite& symbol);
    virtual ~Unit();

    // draw the unit on the world.
    virtual void drawOnWorld(sf::RenderWindow& window);

    // overide the method in parent.
    virtual void positionChanged();
private:
    // the symbol of this unit.
    sf::Sprite _symbol;
};
#endif
