#include "State.hpp"

State::State(World& world, StateManager& manager)
    : _world(world), _manager(manager)
{
}

State::~State()
{
}
