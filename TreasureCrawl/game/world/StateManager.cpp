#include "StateManager.hpp"
#include "states/State.hpp"
#include "states/PlayerControlState.hpp"
#include "states/PlayerMoveState.hpp"
StateManager::StateManager(World& world)
    : _world(world)
{
}

StateManager::~StateManager()
{
    for(std::vector<State*>::iterator it = _stack.begin() ; it != _stack.end() ; ++it)
    {
        delete *it;
    }
    for(std::vector<State*>::iterator it = _markedForRemoval.begin() ; it != _markedForRemoval.end() ; ++it)
    {
        delete *it;
    }
}

void StateManager::draw(sf::RenderWindow& window)
{
    for(int i = _stack.size() - 1; i >= 0 ; i--)
    {
        State* state = _stack[i];
        if(!state->draw(window))
        {
            break;
        }
    }
}

void StateManager::update(sf::RenderWindow& window, const sf::Time& delta)
{
    for(int i = _stack.size() - 1; i >= 0 ; i--)
    {
        State* state = _stack[i];
        if(!state->update(window, delta))
        {
            break;
        }
    }
    // clean up all the state in marked for removal if any
    cleanup();
}

void StateManager::handleKeyInput(char c)
{
    for(int i = _stack.size() - 1; i >= 0 ; i--)
    {
        State* state = _stack[i];
        if(!state->input(c))
        {
            break;
        }
    }
    // clean up all the state in marked for removal if any
    cleanup();
}

void StateManager::pushState(State& state)
{
    _stack.push_back(&state);
}

void StateManager::popState()
{
    if(_stack.size() > 0)
    {
        _markedForRemoval.push_back(_stack.back());
        _stack.pop_back();
    }
}

void StateManager::clearAllState()
{
    _markedForRemoval.insert(_markedForRemoval.begin(), _stack.begin(), _stack.end());
    _stack.clear();
}

void StateManager::cleanup()
{
    // for now, we delete all of them. 
    // If we need to, we can reuse the state instead.
    for(std::vector<State*>::iterator it = _markedForRemoval.begin() ; it != _markedForRemoval.end() ; ++it)
    {
        delete *it;
    }
    _markedForRemoval.clear();
}

State& StateManager::makePlayerControlState()
{
    return *(new PlayerControlState(_world, *this));
}

State& StateManager::makePlayerMoveState(const zf::Direction& direction)
{
    return *(new PlayerMoveState(_world, *this, direction));
}
