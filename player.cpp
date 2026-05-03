#include "player.h"
#include <cstdlib>

using namespace std;

// Initialize player
// What it does: Initializes the player's starting state and allocates dynamic memory for the inventory system
// Inputs:
// - Player& player: The specific player object to be modified and initialized
// - int difficulty: The chosen game difficulty level
// Outputs: None (due to void), but initializes the members of the player object directly
void initializePlayer(Player& player, int difficulty) {
    player.x = MAP_WIDTH / 2;
    player.y = MAP_HEIGHT / 2;
    player.hp = MAX_HP;
    

    player.inventoryCapacity = 5;
    player.inventory = new string[player.inventoryCapacity]; 
    player.inventorySize = 0;

    player.currentLevel = LEVEL1;
    player.difficulty = difficulty;
}

// What it does: Updates the player's grid coordinates based on directional input
// Inputs:
// - Player& player: 
// - char direction: 
void movePlayer(Player& player, char direction) {
    switch(direction) {
        case 'w': player.y--; break;
        case 's': player.y++; break;
        case 'a': player.x--; break;
        case 'd': player.x++; break;
        default: break;
    }
}


// dynamic memory clean up

void cleanupPlayer(Player& player) {
    delete[] player.inventory;
    player.inventory = nullptr;
    player.inventorySize = 0;
    player.inventoryCapacity = 0;
}
