#include "room.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// What it does: Sets up initial state of the room
// Inputs: 
// - Room& room: Reference to the Room structure to be modified
// - int level: The current game level
// - int difficulty: The chosen difficulty setting
// Outputs: None (due to void), but modifies the 'room' object directly
void initializeRoom(Room& room, int level, int difficulty) {
    room.map.resize(MAP_HEIGHT, string(MAP_WIDTH, ' '));
    room.hasKey = false;
    room.isCompleted = false;
    room.traps.clear();
    
    for (int i = 0; i < MAP_HEIGHT; i++) {
        room.map[i][0] = '#';
        room.map[i][MAP_WIDTH - 1] = '#';
    }
    for (int i = 0; i < MAP_WIDTH; i++) {
        room.map[0][i] = '#';
        room.map[MAP_HEIGHT - 1][i] = '#';
    }
    
    srand(time(0));
    room.keyX = rand() % (MAP_WIDTH - 2) + 1;
    room.keyY = rand() % (MAP_HEIGHT - 2) + 1;
    room.doorX = rand() % (MAP_WIDTH - 2) + 1;
    room.doorY = rand() % (MAP_HEIGHT - 2) + 1;
    
    if (level == LEVEL1) {
        if (difficulty == EASY) room.map[room.keyY][room.keyX] = 'K';
        room.map[room.doorY][room.doorX] = 'D';
    }
    else if (level == LEVEL2) {
        room.map[room.doorY][room.doorX] = 'D';
        room.map[rand()%(MAP_HEIGHT-2)+1][rand()%(MAP_WIDTH-2)+1] = 'M';
    }
//level 3
    else if (level == LEVEL3) {
        room.map[room.doorY][room.doorX] = 'D';
        
        int trapNum;
        if (difficulty == EASY) trapNum = 3;
        else if (difficulty == MEDIUM) trapNum = 15;   // 15 VISIBLE
        else trapNum = 25;                             // 25 INVISIBLE

        for (int i = 0; i < trapNum; i++) {
            int tx = rand() % (MAP_WIDTH - 2) + 1;
            int ty = rand() % (MAP_HEIGHT - 2) + 1;
            room.traps.push_back({tx, ty});
            // show the trap in medium & easy difficulty
            if (difficulty == EASY || difficulty == MEDIUM) {
                room.map[ty][tx] = 'B';
            }
        }
    }
// for the final level
    else if (level == FINAL_LEVEL) {
        if (difficulty == EASY) room.map[room.keyY][room.keyX] = 'K';
        room.map[room.doorY][room.doorX] = 'D';
        room.map[rand()%(MAP_HEIGHT-2)+1][rand()%(MAP_WIDTH-2)+1] = 'M';
        
        int trapNum;
        if (difficulty == EASY) trapNum = 3;
        else if (difficulty == MEDIUM) trapNum = 15;   // 15 VISIBLE
        else trapNum = 25;                             // 25 INVISIBLE   same as above 

        for (int i = 0; i < trapNum; i++) {
            int tx = rand() % (MAP_WIDTH - 2) + 1;
            int ty = rand() % (MAP_HEIGHT - 2) + 1;
            room.traps.push_back({tx, ty});
            
            
            if (difficulty == EASY || difficulty == MEDIUM) {
                room.map[ty][tx] = 'B';
            }
        }
    }
}

// What it does: Determines if the given coordinates hit the wall
// Inputs:
// - const Room& room: The current 'room' object
// - int x: The x-coordinate to check
// - int y: The y-coordinate to check
// Outputs: Returns true if the coordinate is a wall ('#'), false otherwise
bool isWall(const Room& room, int x, int y) {
    return room.map[y][x] == '#';
}

// What it does: Determines if the player has triggered a trap based on their (x,y) position
// Inputs:
// - const Room& room: The current room containing the trap vector
// - int x: Player's x-coordinate
// - int y: Player's y-coordinate
// Outputs: Returns true if a trap exists at (x,y), false otherwise
bool checkTrapCollision(const Room& room, int x, int y) {
    for (auto& trap : room.traps) {
        if (trap.first == x && trap.second == y) return true;
    }
    return false;
}

// What it does: Updates the game view to show the player's movement and any relevant level-specific hints
// Inputs:
// - const Room& room: The current room data
// - const Player& player: The player's current state
// Outputs: None (due to void), but outputs the map directly to the console
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
        cout << "💫 Hint: " << getDirectionHint(room.keyX, room.keyY, player.x, player.y) << endl;
    }
}

// What it does: Generate a directional hint (North, South, East, or West) based on the key's location relative to the player
// Inputs:
// - int keyX: x-coordinate of the key
// - int keyY: y-coordinate of the key
// - int playerX: Player's x-coordinate
// - int playerY: Player's y-coordinate
// Outputs: A message directing the player toward the key
string getDirectionHint(int keyX, int keyY, int playerX, int playerY) {
    if (keyY < playerY) return "Look north to find the key! 👀";
    if (keyY > playerY) return "Look south to find the key! 👀";
    if (keyX < playerX) return "Look west to find the key! 👀";
    if (keyX > playerX) return "Look east to find the key! 👀";
    return "Key is nearby!";
}
