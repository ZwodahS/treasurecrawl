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
        _world->draw(window);
    }
}

void GameScreen::update(sf::RenderWindow& window, const sf::Time& delta)
{
    if(_world != 0)
    {
        _world->update(window, delta);
    }
}

void GameScreen::inputs(sf::RenderWindow& window, const sf::Time& delta)
{
}

void GameScreen::textInput(char c)
{
    if(_world != 0)
    {
        _world->handleKeyInput(c);
    }
}
