#include "GameScreen.hpp"
#include "../world/World.hpp"
GameScreen::GameScreen(Game& game)
    : Screen(game)
{
    _world = new World(game);
}

GameScreen::~GameScreen()
{
}

void GameScreen::draw(sf::RenderWindow& window)
{
    if(_world != 0)
    {
        _world->drawFloor(window, 0);
    }
}

void GameScreen::update(sf::RenderWindow& window, const sf::Time& delta)
{
}

void GameScreen::inputs(sf::RenderWindow& window, const sf::Time& delta)
{
}

void GameScreen::textInput(char c)
{
}
