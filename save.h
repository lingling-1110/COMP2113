#ifndef SAVE_H
#define SAVE_H

#include <string>
#include "room.h"

using namespace std;

void save(const Room &r, const string &fname);
bool load(Room &r, const string fname);
void del(const string fname);

#endif
