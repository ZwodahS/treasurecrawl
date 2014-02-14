#ifndef _GAME_WORLD_STATES_STATE_H_
#define _GAME_WORLD_STATES_STATE_H_
#include <SFML/Graphics.hpp>
class World;
class StateManager;
class State
{
public:
    State(World& world, StateManager& manager);
    virtual ~State();

    // boolean telling if the StateManager should call the draw method of the previous state.
    virtual bool draw(sf::RenderWindow& window) = 0;
    // boolean telling if the StateManager should call the update method of the previous state.
    virtual bool update(sf::RenderWindow& window, const sf::Time& delta) = 0;
    // boolean telling if the StateManager should pass the input to the previous state for handling.
    virtual bool input(char inputChar) = 0;

protected:
    World& _world;
    StateManager& _manager;
};
#endif
