#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "constants.h"
using namespace std;

struct Player {
    int x, y;
    int hp;

    string* inventory;   // DYNAMIC ARRAY 
    int inventorySize;       
    int inventoryCapacity;   
    int currentLevel;
    int difficulty;
};
void movePlayer(Player& player, char cmd);
void cleanupPlayer(Player& player);

#endif
