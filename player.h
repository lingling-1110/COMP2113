#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
private:
    int currentLevel;
    vector<string> inventory;
    int health;
    Difficulty difficulty;

public:
    Player();
    void setLevel(int level);
    int getLevel() const;
    void addItem(const string& item);
    bool hasItem(const string& item) const;
    void removeItem(const string& item);
    void showInventory() const;
    bool hasKey() const;
    int getHealth() const;
    void setHealth(int h);
    void reduceHealth(int amount);
    void setDifficulty(Difficulty diff);
    Difficulty getDifficulty() const;
};

#endif
