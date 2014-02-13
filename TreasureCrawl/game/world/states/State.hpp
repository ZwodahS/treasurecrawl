#ifndef _GAME_WORLD_STATES_STATE_H_
#define _GAME_WORLD_STATES_STATE_H_
#include <SFML/Graphics.hpp>
class World;
class State
{
public:
    State(World& world);
    virtual ~State();

    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void update(sf::RenderWindow& window, const sf::Time& delta) = 0;
    virtual void input(char inputChar) = 0;

protected:
    World& _world;
};
#endif
