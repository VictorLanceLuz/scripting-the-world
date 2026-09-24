#include <iostream>
#include <sstream>
#include "GameObject.hpp"
#include "ScriptEngine.hpp"
#include "Position.hpp"

int main() {
    GameObject player1("Hero", 100, 0.0f, 0.0f, 1);
    GameObject player2("Hero", 100, 0.0f, 0.0f, 1);
    Position posCheck(0.0f, 0.0f);
    
    // comparing posCheck with player1 using == operator.
    if (posCheck == player1) {
        std::cout << "Position matches player1's position.\n";
    } else {
        std::cout << "Position does NOT match player1's position.\n"; 
    }

    // simulate ScriptEngine using teleport on player1.
    ScriptEngine::teleport(player1, 10.0f, 5.0f); 

    // simulate ScriptEngine using heal on player1.
    ScriptEngine::heal(player1, 25);

    // simulate Script Engine using advanceAnimation on player1.
    ScriptEngine::advanceAnimation(player1);
    
    // player2 simulations.
    ScriptEngine::teleport(player2, 5.0f, 7.5f);
    ScriptEngine::heal(player2, 20);
    ScriptEngine::advanceAnimation(player2);

    std::cout << stringify(player1) << std::endl;
    std::cout << player1 << std::endl; 
    
    return 0;
}