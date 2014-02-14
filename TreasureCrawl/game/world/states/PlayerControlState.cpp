#include "PlayerControlState.hpp"
#include "../StateManager.hpp"
#include "../World.hpp"
PlayerControlState::PlayerControlState(World& world, StateManager& manager)
    : State(world, manager)
{
}

PlayerControlState::~PlayerControlState()
{
}

bool PlayerControlState::draw(sf::RenderWindow& window)
{
    _world.drawFloor(window, 0);
    return false;
}

bool PlayerControlState::update(sf::RenderWindow& window, const sf::Time& delta)
{
    return false;
}

bool PlayerControlState::input(char inputChar)
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
    return false;
}

void PlayerControlState::move(const zf::Direction& direction)
{
    _manager.pushState(_manager.makePlayerMoveState(direction));
}
