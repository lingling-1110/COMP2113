#ifndef SAVE_H
#define SAVE_H

#include <string>
#include "room.h"

using namespace std;

void save(const Player &p, const Room &r, const string &fname);
bool load(Player &p, Room &r, const string &fname);
void del(const string &fname);

#endif
