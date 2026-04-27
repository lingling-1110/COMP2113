#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
using namespace std;

class Player {
public:
    Player();
    void add(string item);
    bool has(string item);
    void remove(string item);
    void show();
    void hurt(int dmg);
    void setDiff(int d);
    int getDiff();
    int getHp();
    void nextLevel();
    int getLevel();

private:
    vector<string> inv;
    int hp, diff, level;
};

#endif
