/*
    This software uses The MIT License (MIT). See license agreement LICENSE for full details.
*/


#ifndef GAMEOVERSTATE_HPP
#define GAMEOVERSTATE_HPP

#include "GameState.hpp"
#include "MainMenuState.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class StateMachine;

namespace sf {
    class RenderWindow;
}

class GameOverState : public GameState {
public:
    GameOverState(int levelNumber, StateMachine& machine, sf::RenderWindow& window, bool replace = true);
    void processEvents();
    void update(sf::Time deltaTime);
    void draw();
private:
    bool mouseOnMenuButton;
    bool mouseOnQuitButton;
    sf::Font font;
    sf::Text gameOverText;
    sf::Text mainMenuText;
    sf::Text quitText;
};
#endif