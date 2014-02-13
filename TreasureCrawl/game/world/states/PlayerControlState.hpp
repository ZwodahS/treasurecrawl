#ifndef _GAME_WORLD_STATES_PLAYERCONTROLSTATE_H_
#define _GAME_WORLD_STATES_PLAYERCONTROLSTATE_H_
#include "State.hpp"
#include "../../../z_framework/zf_common/Direction.hpp"
class PlayerControlState : public State
{
public:
    PlayerControlState(World& world);
    virtual ~PlayerControlState();

    virtual void draw(sf::RenderWindow& window);
    virtual void update(sf::RenderWindow& window, const sf::Time& delta);
    virtual void input(char inputChar);

protected:

    void move(const zf::Direction& direction);
};
#endif
