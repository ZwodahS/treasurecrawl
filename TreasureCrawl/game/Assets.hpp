#ifndef _GAME_ASSETS_
#define _GAME_ASSETS_
#include <SFML/Graphics.hpp>
#include "../z_framework/zf_sfml/SpriteSheet.hpp"
#include "../z_framework/zf_sfml/TextureRegion.hpp"

struct Icons24Assets
{
    zf::TextureRegion hero;
    zf::TextureRegion wall_symbol;
    zf::TextureRegion floor_background;
};

struct Assets
{
    sf::Texture master1;
    zf::SpriteSheet masterS1;
    zf::SpriteSheet icons24S;

    Icons24Assets icons24;

    sf::Font mainFont;
};
#endif
