#ifndef _GAME_SCREENS_GAMESCREEN_H_
#define _GAME_SCREENS_GAMESCREEN_H_
#include "Screen.hpp"
#include <SFML/Graphics.hpp>
class World;
class Game;
class GameScreen : public Screen
{
public:
    GameScreen(Game& game);
    virtual ~GameScreen();

    virtual void draw(sf::RenderWindow& window);
    virtual void update(sf::RenderWindow& window, const sf::Time& delta);
    virtual void inputs(sf::RenderWindow& window, const sf::Time& delta);
    virtual void textInput(char c);
private:

    World* _world;
};
#endif
