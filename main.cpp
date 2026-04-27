#include <iostream>
#include "game.h"

using namespace std;

int main() {
    // Create game object
    Game game;
    game.start();
    
    while (!game.isOver()) {
        game.displayStatus();
        game.processInput();
    }

    cout << "Game Over. Thanks for playing!" << endl;
    return 0;
}
