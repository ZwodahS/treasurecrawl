#include "../Game.hpp"
#include "../f_helper.hpp"
#include "items/g_all.hpp"
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

void print(ItemInstance* instance)
{
    if(instance == 0)
    {
        std::cout << "Null instance" << std::endl;
    }
    else 
    {
        // print the name
        ItemTypeComponent* comp = instance->type.getComponent(ItemTypeComponent::NameItemTypeComponent);
        if(comp == 0)
        {
            std::cout << "Name component not found !" << std::endl;
        }
        else
        {
            for(int i = 0 ; i < 6 ; i++)
            {
                ItemTypeComponent* varyQualityComp = instance->type.getComponent(ItemTypeComponent::VaryQualityItemTypeComponent);
                if(varyQualityComp == 0)
                {
                    std::cout << "No Vary Quality Comp" << std::endl;
                    break;
                }
                else
                {
                    if(static_cast<VaryQualityItemTypeComponent*>(varyQualityComp)->setQualityValue(*instance, i))
                    {
                        std::cout << "Name for quality " << i << " is : " << static_cast<NameItemTypeComponent*>(comp)->getName(*instance) << std::endl;
                    }
                    else
                    {
                        std::cout << "Cannot set the component quality value to " << i << ". Value out range" << std::endl;
                    }
                }
            }
        }
    }
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

    _itemTypeManager.load();
    // spawn the unit onto the terrain.
    spawnUnitIn(*_hero, zf::Grid(heroPosition), 0);

    _stateManager.pushState(_stateManager.makePlayerControlState());
    
    { 
        // temporary debugging used to test the loading of the ItemType and creation of ItemInstance.
        ItemInstance* ruby = _itemTypeManager.makeItemInstance("item_gem_ruby");
        print(ruby);
        ItemInstance* emerald = _itemTypeManager.makeItemInstance("item_gem_emerald");
        print(emerald);
        ItemInstance* sapphire = _itemTypeManager.makeItemInstance("item_gem_sapphire");
        print(sapphire);

        std::cout << "Done debug" << std::endl;
    }

    updateVision();
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
    // remove the unit from the old terrain if there is any.
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
    updateVision();
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

std::set<zf::Grid> World::getVisions(Unit& unit)
{
    std::set<zf::Grid> visibleGrids;

    // get the floor that the unit is in.
    Floor* floor = getFloor(unit.getZPosition());
    if(floor == 0)
    {
        return visibleGrids;
    }
    
    // get the square vision boundary.
    std::vector<zf::Grid> visionBoundary = getSquareVisionBoundary(unit.getVisionRange(), unit.getGridPosition(), floor->getMaxSize());
 
    // for every grid in the boundary, we draw a line to it.
    for(std::vector<zf::Grid>::iterator it = visionBoundary.begin() ; it != visionBoundary.end() ; ++it)
    {
        std::vector<zf::Grid> los = getLine(_hero->getGridPosition(), *it);

        // iterate through the list identify all the grid that we can see.
        for(std::vector<zf::Grid>::iterator it2 = los.begin() ; it2 != los.end() ; ++it2)
        {
            Terrain* terrain = floor->getTerrain(*it2);
            // safety mechanism.
            if(terrain != 0)
            {   
                // check if the unit can see the terrain.
                // Normal unit will check if the terran is lit,
                // Some unit can see in the dark, so they can also see unlit tiles.
                if(unit.canSee(*terrain))
                {
                    visibleGrids.insert(*it2);
                }
                // if the unit cannot see through the terrain, then we stop the line
                if(!unit.canSeeThrough(*terrain))
                {
                    break;
                }
            }
        }
    }

    // return the vision set.
    return visibleGrids;
}



void World::updateVision()
{
    // clear the cache.
    for(std::vector<Terrain*>::iterator it = _visibleTerrains.begin() ; it != _visibleTerrains.end() ; ++it)
    {
        (**it).setVisible(false);
    }
    _visibleTerrains.clear();

    // get the visible grids using the get visions method.
    std::set<zf::Grid> visibleGrid = getVisions(*_hero);

    // get the floor that the hero is on.
    Floor* floor = getFloor(_hero->getZPosition());

    // iterate through the list of visible terrains and update their value.
    for(std::set<zf::Grid>::iterator it = visibleGrid.begin() ; it != visibleGrid.end() ; ++it)
    {
        Terrain* terrain = floor->getTerrain(*it);
        if(terrain != 0)
        {
            terrain->setVisible(true);
            terrain->setExplored(true);
            _visibleTerrains.push_back(terrain);
        }
    }

}
