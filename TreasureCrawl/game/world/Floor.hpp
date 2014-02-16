#ifndef _GAME_WORLD_FLOOR_H_
#define _GAME_WORLD_FLOOR_H_
#include <SFML/Graphics.hpp>
#include "../../z_framework/zf_common/TwoDSpace.hpp"
/**
 * We treat floor as just a container for terrains. 
 * It is created in case we need to add methods to it.
 */
class Terrain;
class Floor
{
public:
    Floor(int row, int col);
    ~Floor();
    
    // draw the floor.
    void draw(sf::RenderWindow& window);
    
    // set the terrain, using the terrain information provided.
    // return the old terrain that this terrain replace.
    Terrain* setTerrain(Terrain& terrain);
    // get the terrain at this position.
    Terrain* getTerrain(const zf::Grid& grid);

    zf::Grid getMaxSize();
private:

    zf::TwoDSpace<Terrain*> _terrains;
};
#endif
