#include "game.h"
#include "player.h"
#include "room.h"
#include "utils.h"
#include "save.h"

#include <iostream>
using namespace std;



bool runLevel(Player& player) {
    Room room;
    initializeRoom(room, player.currentLevel, player.difficulty);

    bool mathSolved = false;
    

    while (player.hp > 0) {
        printMap(room, player);

        // description for each level
        string levelDesc;
        switch(player.currentLevel) {
            case LEVEL1: levelDesc = "Find the Key! (Get your key to unlock the room!)"; break;
            case LEVEL2: levelDesc = "Math time!"; break;
            case LEVEL3: levelDesc = "Trap Room! (Please aviod stepping on any BOMP!"; break;
            case FINAL_LEVEL: levelDesc = "Final Escape! (Try to discover by yourself!)"; break;
            default: levelDesc = "Unknown";
        }
        
        cout << "HP: " << player.hp  << " | Level: " << player.currentLevel << " - " << levelDesc << endl;
        
        
        cout << "Choose your action: | w/a/s/d = move | l = save | q = quit" << endl;
        char cmd;
        cin >> cmd;

        if (cmd == 'q') return false;
        if (cmd == 'l') {
            saveGame(player);
            continue;
        }

        int oldX = player.x;
        int oldY = player.y;
        movePlayer(player, cmd);

        if (isWall(room, player.x, player.y)) {
            player.x = oldX;
            player.y = oldY;
        }

        // level 1 - key
        if (player.x == room.keyX && player.y == room.keyY && !room.hasKey) {
            room.hasKey = true;
            cout << "\nYou picked up the hidden KEY! Please take your key to open the door" << endl;
            cout << "(Press Enter to continue...)" << endl;
            cin.ignore();
            cin.get();
        }
      
    
        // LEVEL 2 and final level of   Math Question 
        if (player.currentLevel == LEVEL2 || player.currentLevel == FINAL_LEVEL) && !mathSolved) {
            // Check if player steps on M position
            if (room.map[player.y][player.x] == 'M') {
                cout << "\n 🧮 MATH PUZZLE (M)" << endl;
                cout << "=====================================" << endl;
                // SHOW QUESTION 
                mathSolved = solveMathPuzzle(player.difficulty);

                if (mathSolved) {
                    cout << "\n✅ Correct! Now go to DOOR (D) to continue your adventure." << endl;
                } else {
                    cout << "\n❌ Wrong answer! Try again at M position." << endl;
                }

                cout << "(Press Enter to continue...)" << endl;
                cin.ignore();
                cin.get();
            }
        }

        // Trap collision
        if (checkTrapCollision(room, player.x, player.y)) {
            handleTrapDamage(player.hp, player.difficulty);
        }

        // Door interaction
        if (player.x == room.doorX && player.y == room.doorY) {
            bool pass = false;

            if (player.currentLevel == LEVEL1)
                pass = room.hasKey;

            // LEVEL 2: door open when the math solved
            else if (player.currentLevel == LEVEL2)
                pass = mathSolved;

            else if (player.currentLevel == LEVEL3)
                pass = true;
            else if (player.currentLevel == FINAL_LEVEL)
                pass = room.hasKey && mathSolved;

            if (pass) {
                cout << "\n=====================================" << endl;
                cout << " You successfully open the door! 🚪✅" << endl;
                cout << " Moving to the next room... " << endl;
                cout << "(Press Enter to continue...)" << endl;
                cin.ignore();
                cin.get();

                player.currentLevel++;
                return true;
            } else {
                if (player.currentLevel == LEVEL1) {
                    cout << "\n❌ You must get the Key at K first!" << endl;
                }
                // Message if player can't open door yet
                if (player.currentLevel == LEVEL2) {
                    cout << "\n❌ You must check the MATH PUZZLE at M first!" << endl;
                }
                if (player.currentLevel == FINAL_LEVEL) {
                    cout << "\n❌ You must get the Key at K first, followed by the math puzzle!" << endl;
                }
                cout << "(Press Enter to continue...)" << endl;
                cin.ignore();
                cin.get();
            }
        }
    }
    return false;
}

void startGame() {
    cout << "==== ESCAPE THE Room ====" << endl;
    cout << "1. New Game" << endl;
    cout << "2. Load Game" << endl;
    int c;
    cin >> c;

    Player p;
    p.hp = 100; // Default HP
    p.currentLevel = LEVEL1; // Start at level 1
    p.inventory = new string[5]; 
    p.inventorySize = 0;
    p.inventoryCapacity = 5;
    p.x = 1; // Default starting X
    p.y = 1; // Default starting Y

    if (c == 2 && loadGame(p)) {
        cout << "Loaded successfully!" << endl;
    } else {
        cout << "Difficulty (0=Easy, 1=Medium, 2=Hard): ";
        int d;
        cin >> d;
        p.difficulty = d; // Set difficulty for the player
        Room tempRoom;
        initializeRoom(tempRoom, p.currentLevel, p.difficulty);
    }

    bool playing = true;
    while (playing && p.hp > 0 && p.currentLevel <= FINAL_LEVEL) {
        playing = runLevel(p);
    }

    if (p.hp <= 0){
        cout << "YOU DIED. GAME OVER." << endl;
        cin.ignore();
        cin.get();
    }
    if (p.currentLevel > FINAL_LEVEL){
        cout << "YOU ESCAPED! WIN!" << endl;
        cin.ignore();
        cin.get();
    }
    // Clean up dynamic memory
    cleanupPlayer(p);
}














