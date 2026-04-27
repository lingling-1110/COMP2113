#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

using namespace std;

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
void create_rm(Room &r, int num, string name, string diff);
void clue(Room &r, string diff);
void enter_rm(Room &r, string diff);

#endif
