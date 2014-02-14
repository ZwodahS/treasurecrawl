#ifndef _GAME_WORLD_STATEMANAGER_H_
#define _GAME_WORLD_STATEMANAGER_H_
#include <vector>
#include <SFML/Graphics.hpp>
#include "../../z_framework/zf_common/Direction.hpp"
class State;
class World;
class StateManager
{
public:
    StateManager(World& world);
    ~StateManager();

    // call the draw method on the current state.
    void draw(sf::RenderWindow& window);
    // call the update method on the current state.
    void update(sf::RenderWindow& window, const sf::Time& delta);
    // call the hande input on the current state.
    void handleKeyInput(char inputChar);

    // push a state onto the stack.
    void pushState(State& state);
    // Note that all state pop will be clean up after the current "iteration"
    // pop a state from the stack.
    void popState();
    // clear all the state.
    void clearAllState();

    // Factory method for creating the different states.
    State& makePlayerControlState();
    State& makePlayerMoveState(const zf::Direction& direction); 

private:
    // the only reason to store the world is because that State requires it.
    World& _world;
    
    // The State stack.
    std::vector<State*> _stack;

    // all the states that has been marked for removal, remove them only after the iteration.
    std::vector<State*> _markedForRemoval;

    // the cleanup method for after all update and handlekeyinput
    void cleanup();
};
#endif
