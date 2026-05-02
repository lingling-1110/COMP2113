#include "save.h"
#include <fstream>
#include <iostream>

using namespace std;

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
