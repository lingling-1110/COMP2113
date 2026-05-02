#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <string>
#include "constants.h"
#include "player.h"
using namespace std;

struct Room {
    vector<string> map;
    int keyX, keyY;
    int doorX, doorY;
    vector<pair<int, int>> traps;
    bool hasKey;
    bool isCompleted;
};

// Room functions
void initializeRoom(Room& room, int level, int difficulty);
bool isWall(const Room& room, int x, int y);
bool checkTrapCollision(const Room& room, int x, int y);
void printMap(const Room& room, const Player& player);
string getDirectionHint(int keyX, int keyY, int playerX, int playerY);

#endif
