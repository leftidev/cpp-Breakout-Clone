/*
    This software uses The MIT License (MIT). See license agreement LICENSE for full details.
*/


#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include "../GameStates/GameState.hpp"

#include <SFML/System.hpp>

#include <iostream>
#include <memory>
#include <stack>


class GameState;

namespace sf {
    class RenderWindow;
}

class StateMachine {
public:
    StateMachine();
    void run(std::unique_ptr<GameState> state);
    void nextState();
    void lastState();
    void processEvents();
    void update(sf::Time deltaTime);
    void draw();
    bool running() { return m_running; }
    void quit() { m_running = false; }
    template <typename T>
    static std::unique_ptr<T> build(int levelNumber, StateMachine& machine, sf::RenderWindow& window, bool replace = true);
private:
    // The stack of states
    std::stack<std::unique_ptr<GameState>> m_states;
    bool m_running;
};

template <typename T>
std::unique_ptr<T> StateMachine::build(int levelNumber, StateMachine& machine, sf::RenderWindow& window, bool replace) {
    return std::move(std::unique_ptr<T>(new T(levelNumber, machine, window, replace)));
}
#endif