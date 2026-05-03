#include "save.h"
#include <fstream>
#include <iostream>

using namespace std;

// What it does: Saves the player's current status to an external file to preserve the game session
// Inputs:
// - const Player& player: The player object containing the data to be stored
// Outputs: None (due to void), but notifies the user via console once the save is successful
void saveGame(const Player& player) {
    ofstream file("savegame.txt");
    if (file.is_open()) {
        file << player.x << endl;
        file << player.y << endl;
        file << player.hp << endl;
        file << player.currentLevel << endl;
        file << player.difficulty << endl;
        file.close();
        cout << "Game saved!" << endl;
        cout << "(Press Enter to continue...)" << endl;
        cin.ignore();
        cin.get();
    }
}

// What it does: Loads saved progress from an external file into the player structure to resume gameplay
// Inputs:
// - Player& player: A reference to the 'Player' instance that will be updated with the retrieved file data
// Outputs: Returns true if the save file was found and loaded successfully, returns false if the file could not be opened
bool loadGame(Player& player) {
    ifstream file("savegame.txt");
    if (file.is_open()) {
        file >> player.x;
        file >> player.y;
        file >> player.hp;
        file >> player.currentLevel;
        file >> player.difficulty;
        file.close();
        return true;
    }
    return false;
}
