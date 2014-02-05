#include "MainScreen.hpp"
#include "../Game.hpp"

MainScreen::MainScreen(Game& game)
    : Screen(game)
{

    hero = _game.assets.icons24.hero.createSprite();
    hero.setPosition(0, 0);
    wall = _game.assets.icons24.wall.createSprite();
    wall.setPosition(24, 0);
    floor = _game.assets.icons24.floor.createSprite();
    floor.setPosition(48, 0);
}

MainScreen::~MainScreen()
{
}

void MainScreen::draw(sf::RenderWindow& window)
{
    window.draw(hero);
    window.draw(wall);
    window.draw(floor);
}

void MainScreen::update(sf::RenderWindow& window, const sf::Time& delta)
{
}

void MainScreen::inputs(sf::RenderWindow& window, const sf::Time& delta)
{
}

void MainScreen::textInput(char c)
{
}
