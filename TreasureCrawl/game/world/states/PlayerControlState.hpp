#ifndef _GAME_WORLD_STATES_PLAYERCONTROLSTATE_H_
#define _GAME_WORLD_STATES_PLAYERCONTROLSTATE_H_
#include "State.hpp"
#include "../../../z_framework/zf_common/Direction.hpp"
class PlayerControlState : public State
{
public:
    PlayerControlState(World& world, StateManager& manager);
    virtual ~PlayerControlState();

    virtual bool draw(sf::RenderWindow& window);
    virtual bool update(sf::RenderWindow& window, const sf::Time& delta);
    virtual bool input(char inputChar);

protected:
    
    virtual void move(const zf::Direction& direction);
};
#endif
