/*
    This software uses The MIT License (MIT). See license agreement LICENSE for full details.
*/

// Uses a modified "small game engine or better state machine".
// https://github.com/eXpl0it3r/SmallGameEngine

#include "GameStates/MainMenuState.hpp"
#include "GameStateMachine/StateMachine.hpp"

#include <SFML/Graphics.hpp>
#include <Windows.h>


int main() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time deltaTime = sf::seconds(1.f / 60.f);

    sf::RenderWindow m_window;
    m_window.create(sf::VideoMode{1024, 768}, "Breakout");

    m_window.setVerticalSyncEnabled(true);

    // Initialize the Game State engine.
    StateMachine state_machine;
    state_machine.run(StateMachine::build<MainMenuState>(0, state_machine, m_window, true));

    // Main loop.
    while(state_machine.running())
    {
        // Fixed timestep
        timeSinceLastUpdate += clock.restart();
        // This loop is executed at a constant rate.
        while(timeSinceLastUpdate > deltaTime) {
            timeSinceLastUpdate -= deltaTime;


            state_machine.nextState();
            state_machine.processEvents();
            state_machine.update(deltaTime);
        }
        // If rendering is slow, the inner loop is called multiple times before one draw() call.
        state_machine.draw();
    }
    // Leaving the scope of 'state_machine' will cleanup the engine.
}