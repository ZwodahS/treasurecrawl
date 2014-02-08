#include "Floor.hpp"
#include "terrain/Terrain.hpp"
Floor::Floor(int row, int col)
    : _terrains(row, col, 0)
{
}

Floor::~Floor()
{
    // deconstruct all the terrains object.
    for(zf::TwoDSpace<Terrain*>::Iterator it = _terrains.iteratesRowCol(); !it.end() ; ++it)
    {
        if(it.get() == 0)
        {
            continue;
        }
        delete it.get();
        it.set(0);
    }
}

void Floor::draw(sf::RenderWindow& window)
{
    for(zf::TwoDSpace<Terrain*>::Iterator it = _terrains.iteratesRowCol(); !it.end() ; ++it)
    {
        if(it.get() == 0)
        {
            continue;
        }
        it.get()->draw(window);
    }
}

Terrain* Floor::setTerrain(Terrain& terrain)
{
    Terrain* oldTerrain = _terrains.get(terrain.getPosition().first);
    _terrains.set(terrain.getPosition().first, &terrain);
    return oldTerrain;
}

Terrain* Floor::getTerrain(const zf::Grid& grid) 
{
    return _terrains.get(grid);
}
