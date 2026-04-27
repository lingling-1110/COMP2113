#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

using namespace std;

class Player {
public:
    Player();
    void addItem(string item);
    bool hasItem(string item);
    void removeItem(string item);
    void showInv();
    bool hasKey();
    int getHp();
    void takeDamage(int dmg);
    void setDiff(int d);  // 0=easy,1=med,2=hard
    int getDiff();
    int getLevel();
    void nextLevel();

private:
    vector<string> inv;
    int hp;
    int diff;
    int level;
};

#endif
