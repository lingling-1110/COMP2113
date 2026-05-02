#include "player.h"
#include <cstdlib>

using namespace std;
// Initialize player
void initializePlayer(Player& player, int difficulty) {
    player.x = MAP_WIDTH / 2;
    player.y = MAP_HEIGHT / 2;
    player.hp = MAX_HP;
    

    player.inventoryCapacity = 5;
    player.inventory = new :string[player.inventoryCapacity]; //dynamic memory
    player.inventorySize = 0;

    player.currentLevel = LEVEL1;
    player.difficulty = difficulty;
}

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
