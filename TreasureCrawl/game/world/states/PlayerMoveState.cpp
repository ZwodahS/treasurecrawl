#include "PlayerMoveState.hpp"
#include "../StateManager.hpp"
#include "../World.hpp"
#include "../entity/Unit.hpp"
PlayerMoveState::PlayerMoveState(World& world, StateManager& manager, const zf::Direction& direction)
    : State(world, manager), _direction(direction), _processed(false)
{
}

PlayerMoveState::~PlayerMoveState()
{
}

bool PlayerMoveState::draw(sf::RenderWindow& window)
{
    // this state doesn't know how to draw,
    return true;
}

bool PlayerMoveState::update(sf::RenderWindow& window, const sf::Time& delta)
{
    // when the update is called for the first time, this is where the move is applied.
    if(!_processed)
    {
        move(_direction);
        _processed = true;
    }
    return true;
}

bool PlayerMoveState::input(char inputChar)
{
    // in this state, we want to prevent all input going down, since we are kind of in the middle of processing a input
    return false;
}


void PlayerMoveState::move(const zf::Direction& direction)
{
    // since we are in the player control state, the active unit MUST be the hero.
    Unit* playerUnit = _world.getActiveUnit();
    // just a small safety check.
    if(playerUnit == 0)
    {
        return;
    }
    // get the target location
    const zf::Grid target = zf::getModifier(direction) + playerUnit->getGridPosition();
    // we will check if there is something to attack later.
    // for now, we will just call the method to move to that position.
    // We hardcode the value of floor for now.
    if(_world.moveUnitTo(*playerUnit, target, playerUnit->getZPosition()))
    {
    }
    else
    {
        // The unit cannot move there.
        // We will display a message later.
    }
    // for now all, regardless of whether the move suceed or fail, we will just transit to PlayerControlState
    _manager.clearAllState();
    _manager.pushState(_manager.makePlayerControlState());
}
