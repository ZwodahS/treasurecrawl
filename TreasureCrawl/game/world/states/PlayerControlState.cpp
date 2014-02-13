#include "PlayerControlState.hpp"
#include "../World.hpp"
#include "../entity/Unit.hpp"
PlayerControlState::PlayerControlState(World& world)
    : State(world)
{
}

PlayerControlState::~PlayerControlState()
{
}

void PlayerControlState::draw(sf::RenderWindow& window)
{
    _world.drawFloor(window, 0);
}

void PlayerControlState::update(sf::RenderWindow& window, const sf::Time& delta)
{
}

void PlayerControlState::input(char inputChar)
{
    switch(inputChar)
    {
        case 'h' : move(zf::West);
                   break;
        case 'j' : move(zf::South);
                   break;
        case 'k' : move(zf::North);
                   break;
        case 'l' : move(zf::East);
                   break;
        case 'y' : move(zf::NorthWest);
                   break;
        case 'u' : move(zf::NorthEast);
                   break;
        case 'b' : move(zf::SouthWest);
                   break;
        case 'n' : move(zf::SouthEast);
                   break;
        default : break;
    }
}



void PlayerControlState::move(const zf::Direction& direction)
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
        // The unit successfully moved.
        // For now, we do nothing. Later we will need to transit to the state
        // to calculate whose turn it is.
    }
    else
    {
        // The unit cannot move there.
        // We will display a message later.
    }
}
