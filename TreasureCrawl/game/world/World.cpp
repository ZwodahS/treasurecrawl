#include "../Game.hpp"
#include "states/PlayerControlState.hpp"
#include "terrain/Terrain.hpp"
#include "entity/TerrainObject.hpp"
#include "entity/Unit.hpp"
#include "World.hpp"
#include "Floor.hpp"

Terrain& makeRandomTerrain(Game& game)
{
    int r = rand() % 4; // 25% is wall
    Terrain* terrain = new Terrain(game.assets.icons24.floor_background.createSprite());
    if(r == 0)
    {
        TerrainObject* object = new TerrainObject(game.assets.icons24.wall_symbol.createSprite());
        if(!terrain->putTerrainObjectIntoTerrain(*object))
        {
            delete object;
        }
    }
    return *terrain;
}

World::World(Game& game)
    : _game(game), _hero(0), _stateManager(*this)
{
    // const value to be replace with actual code later.
    const zf::Grid heroPosition(0, 0);
    const zf::Grid floorSize(20, 40);
    
    // create the floor.
    Floor* floor = new Floor(floorSize.row, floorSize.col);
    _floors.push_back(floor);

    sf::Vector2i cellSize = _game.getCellSize();

    // create all the terrains.
    for(int r = 0 ; r < floorSize.row ; r++)
    {
        for(int c = 0 ; c < floorSize.col ; c++)
        {
            Terrain& terrain = makeRandomTerrain(_game);
            terrain.setPosition(zf::Grid(r, c), sf::Vector2f(c * cellSize.x, r * cellSize.y));
            floor->setTerrain(terrain);
        }
    }

    // create the hero.
    _hero = new Unit(_game.assets.icons24.hero.createSprite());

    // get the terrain that the hero is going to be spawn on 
    // and remove the terrain object from there.
    Terrain* terrain = floor->getTerrain(heroPosition);
    TerrainObject* object = terrain->removeTerrainObjectFromTerrain();
    if(object != 0)
    {
        delete object;
    }

    // spawn the unit onto the terrain.
    spawnUnitIn(*_hero, zf::Grid(heroPosition), 0);

    _stateManager.pushState(_stateManager.makePlayerControlState());
}

World::~World()
{
}

void World::draw(sf::RenderWindow& window)
{
    _stateManager.draw(window);
}

void World::update(sf::RenderWindow& window, const sf::Time& delta)
{
    _stateManager.update(window, delta);
}

void World::handleKeyInput(char c)
{
    _stateManager.handleKeyInput(c);
}

void World::drawFloor(sf::RenderWindow& window, int floor)
{
    if(_floors.size() > floor && floor >= 0)
    {
        _floors[floor]->draw(window);
    }
}

Unit* World::getActiveUnit()
{
    return _hero;
}

bool World::canMoveUnitTo(Unit& unit, const zf::Grid& targetPosition, const int& floorNum)
{
    // get the floor, make sure that it is a valid floor.
    Floor* floor = getFloor(floorNum);
    if(floor == 0)
    {
        return false;
    }

    // make sure that the terrain exists.
    Terrain* terrain = floor->getTerrain(targetPosition);
    if(terrain == 0)
    {
        return false;
    }
    
    // check if we can put this unit into the terrain.
    if(!terrain->canPutUnitIntoTerrain(unit))
    {
        return false;
    }

    // return true if all pass.
    return true;
}

bool World::moveUnitTo(Unit& unit, const zf::Grid& targetPosition, const int& floorNum)
{
    // check if we can move there
    if(!canMoveUnitTo(unit, targetPosition, floorNum))
    {
        return false;
    }
    // remoe the unit from the old terrain if there is any.
    Floor* oldFloor = getFloor(unit.getZPosition());
    Terrain* oldTerrain = 0;
    if(oldFloor != 0)
    {
        oldTerrain = oldFloor->getTerrain(unit.getGridPosition());
    }
    if(oldTerrain != 0)
    {
        // if the unit was in another terrain, remove it from there.
        oldTerrain->removeUnitFromTerrain();
    }
    // we are sure that the floor and terrain is okay.
    Floor& floor = *getFloor(floorNum);
    Terrain& terrain = *floor.getTerrain(targetPosition);

    // put the unit into the terrain.
    terrain.putUnitIntoTerrain(unit); 

    // get the cell size
    sf::Vector2i cellSize = _game.getCellSize();
    // set the position.
    unit.setPosition(targetPosition, sf::Vector2f(cellSize.x * targetPosition.col, cellSize.y * targetPosition.row));
    // set the z position
    unit.setZPosition(floorNum);
    return true;
}

bool World::spawnUnitIn(Unit& unit, const zf::Grid& grid, const int& floor)
{
    // if floor do not exist, 
    if(_floors.size() <= floor || floor < 0)
    {
        return false;
    }
    // get the terrain
    Terrain* terrain = _floors[floor]->getTerrain(grid);

    // if no terrain or cannot put unit into the terrain, return false
    if(terrain == 0 || !terrain->canPutUnitIntoTerrain(unit))
    {
        return false;
    }

    // get the cellsize.
    sf::Vector2i cellSize = _game.getCellSize();

    // put unit into the terrain
    if(terrain->putUnitIntoTerrain(unit))
    {
        unit.setPosition(grid, sf::Vector2f(cellSize.x * grid.col , cellSize.y * grid.row));
        unit.setZPosition(floor);
        return true;
    }
    return false;
}

Floor* World::getFloor(const int& floor)
{
    return (_floors.size() <= floor || floor < 0 ) ? 0 : _floors[floor];
}
