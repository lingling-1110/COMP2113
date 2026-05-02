#include "room.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void initializeRoom(Room& room, int level, int difficulty) {
    // create empty map
    room.map.resize(MAP_HEIGHT, string(MAP_WIDTH, ' '));
    room.hasKey = false;
    room.isCompleted = false;
    room.traps.clear();
    
    // add walls
    for (int i = 0; i < MAP_HEIGHT; i++) {
        room.map[i][0] = '#';
        room.map[i][MAP_WIDTH - 1] = '#';
    }
    for (int i = 0; i < MAP_WIDTH; i++) {
        room.map[0][i] = '#';
        room.map[MAP_HEIGHT - 1][i] = '#';
    }
    
    // random positions
    srand(time(0));
    room.keyX = rand() % (MAP_WIDTH - 2) + 1;
    room.keyY = rand() % (MAP_HEIGHT - 2) + 1;
    room.doorX = rand() % (MAP_WIDTH - 2) + 1;
    room.doorY = rand() % (MAP_HEIGHT - 2) + 1;
    
    // level setup
    if (level == LEVEL1) {
        if (difficulty == EASY) room.map[room.keyY][room.keyX] = 'K';
        room.map[room.doorY][room.doorX] = 'D';
    }
    else if (level == LEVEL2) {
        room.map[room.doorY][room.doorX] = 'D';
        room.map[rand()%(MAP_HEIGHT-2)+1][rand()%(MAP_WIDTH-2)+1] = 'M';
    }
    else if (level == LEVEL3) {
        room.map[room.doorY][room.doorX] = 'D';
        int trapNum = (difficulty == HARD) ? 6 : 4;
        for (int i = 0; i < trapNum; i++) {
            int tx = rand() % (MAP_WIDTH - 2) + 1;
            int ty = rand() % (MAP_HEIGHT - 2) + 1;
            room.traps.push_back({tx, ty});
            if (difficulty == EASY) room.map[ty][tx] = 'B';
        }
    }
    else if (level == FINAL_LEVEL) {
        if (difficulty == EASY) room.map[room.keyY][room.keyX] = 'K';
        room.map[room.doorY][room.doorX] = 'D';
        room.map[rand()%(MAP_HEIGHT-2)+1][rand()%(MAP_WIDTH-2)+1] = 'M';
        
        int trapNum = (difficulty == HARD) ? 6 : 4;
        for (int i = 0; i < trapNum; i++) {
            int tx = rand() % (MAP_WIDTH - 2) + 1;
            int ty = rand() % (MAP_HEIGHT - 2) + 1;
            room.traps.push_back({tx, ty});
            if (difficulty == EASY) room.map[ty][tx] = 'B';
        }
    }
}

bool isWall(const Room& room, int x, int y) {
    return room.map[y][x] == '#';
}

bool checkTrapCollision(const Room& room, int x, int y) {
    for (auto& trap : room.traps) {
        if (trap.first == x && trap.second == y) return true;
    }
    return false;
}

void printMap(const Room& room, const Player& player) {
    system("clear");
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (x == player.x && y == player.y) cout << "P";
            else cout << room.map[y][x];
        }
        cout << endl;
    }
    if (player.currentLevel == LEVEL1 && player.difficulty == MEDIUM && !room.hasKey) {
        cout << "Hint: " << getDirectionHint(room.keyX, room.keyY, player.x, player.y) << endl;
    }
}
//the hints function
string getDirectionHint(int keyX, int keyY, int playerX, int playerY) {
    if (keyY < playerY) return "Look north to find the key!";
    if (keyY > playerY) return "Look south to find the key!";
    if (keyX < playerX) return "Look west to find the key!";
    if (keyX > playerX) return "Look east to find the key!";
    return "Key is nearby!";
}
