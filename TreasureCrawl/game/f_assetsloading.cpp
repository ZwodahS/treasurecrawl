#include "Game.hpp"
#ifdef APPBUNDLE
#include "../ResourcePath.hpp"
#endif
void Game::loadAssets()
{
    /**
     * This is used for osx XCode to find the resource location.
     * When compiling with XCode, define APPBUNDLE as a preprocessor macro.
     */
    std::string path = "";
    #ifdef APPBUNDLE
    path = resourcePath();
    #endif
    
    // create the master texture.
    assets.master1.create(1280, 1280);

    // create the master spritesheet.
    assets.masterS1.create(&assets.master1, sf::IntRect(0, 0, 1280, 1280));

    // create the icons spritesheet. Each of them will be 24 by 24.
    assets.icons24S = assets.masterS1.createSubSheet(sf::Vector2i(0, 0), sf::IntRect(0, 0, 24, 24), 10, 10);

    // load the font.
    assets.mainFont.loadFromFile(path + "data/font/neuropolitical rg.ttf");

    sf::Image image;

    image.loadFromFile(path + "data/graphics_font/special/at.png");
    assets.icons24.hero = assets.icons24S.createRegion(image);

    image.loadFromFile(path + "data/graphics_font/special/fill.png");
    assets.icons24.wall = assets.icons24S.createRegion(image);
    assets.icons24.wall.defaultColor = sf::Color(100, 60, 0);

    assets.icons24.floor = assets.icons24S.createRegion(image); 
    assets.icons24.floor.defaultColor = sf::Color(230, 195, 145);    
}
