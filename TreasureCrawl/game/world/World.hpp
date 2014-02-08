#ifndef _GAME_WORLD_WORLD_H_
#define _GAME_WORLD_WORLD_H_
#include "../../z_framework/zf_common/Grid.hpp"
class Game;
class Floor;
class Unit;
class World
{
public:
    // Game object is treated as a place to get all the semi-constants.
    World(Game& game);
    ~World();
    
    // draw the terrains object that are on this floor.
    void drawFloor(sf::RenderWindow& window, int floor);

private:
    // store the game object to get the assets, and other semi constants value.
    Game& _game;

    // store the floors in this world.
    std::vector<Floor*> _floors;

    // store the hero unit.
    Unit* _hero;

    // internally common method for spawning unit onto a grid in a floor.
    // return true if it is possible to spawn, false otherwise.
    bool spawnUnitIn(Unit& unit, const zf::Grid& grid, const int& floor);
};
#endif
