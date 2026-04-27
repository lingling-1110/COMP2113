#include "player.h"
#include <iostream>
using namespace std;

Player::Player() : hp(100), diff(1), level(0) {}

void Player::add(string item) { inv.push_back(item); }

bool Player::has(string item) {
    for (string i : inv) if (i == item) return true;
    return false;
}

void Player::remove(string item) {
    for (int i = 0; i < inv.size(); i++)
        if (inv[i] == item) { inv.erase(inv.begin() + i); return; }
}

void Player::show() {
    if (inv.empty()) { cout << "Empty\n"; return; }
    for (string i : inv) cout << i << " ";
    cout << endl;
}

void Player::hurt(int dmg) {
    if (diff == 0) dmg /= 2;
    if (diff == 2) dmg *= 2;
    hp -= dmg;
    if (hp < 0) hp = 0;
    cout << "HP: " << hp << endl;
}

void Player::setDiff(int d) { diff = d; }
int Player::getDiff() { return diff; }
int Player::getHp() { return hp; }
void Player::nextLevel() { level++; }
int Player::getLevel() { return level; }
