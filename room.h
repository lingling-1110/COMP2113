#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

using namespace std;

const int EASY = 0;
const int MEDIUM = 1;
const int HARD = 2;

struct Room {
  int room_num;
  string room_name;
  string desc;
  bool locked;
  string key;
  int ans;
  int trap;
};

void def(Room &r);
void create_rm(Room &r, int num, string name, int diff);
void clue(Room &r, int diff);
void enter_rm(Room &r, int diff);

#endif
