#ifndef _GAME_WORLD_STATES_PLAYERMOVESTATE_H_
#define _GAME_WORLD_STATES_PLAYERMOVESTATE_H_
#include "State.hpp"
#include "../../../z_framework/zf_common/Direction.hpp"
/**
 * This state handles the state after a direction key has been pressed.
 */
class PlayerMoveState : public State
{
public:
    PlayerMoveState(World& world, StateManager& manager, const zf::Direction& direction);
    virtual ~PlayerMoveState();

    virtual bool draw(sf::RenderWindow& window);
    virtual bool update(sf::RenderWindow& window, const sf::Time& delta);
    virtual bool input(char inputChar);

protected:
    void move(const zf::Direction& direction);

    const zf::Direction _direction;

    bool _processed;
};
#endif
