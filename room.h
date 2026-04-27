#ifndef ROOM_H
#define ROOM_H

#include <string>

using namespace std;

struct Room {
  int id;
  bool unlocked;
  string room_name;
  string desc;
  string key;
  int ans;
  int result;
  int item_pos;
  int item_num;
  int trap;
  int trap_pos;
};

void def(Room &r);
void create_rm(Room &r, int num, string name, string diff);
void discover(Room &r, int sel, bool &found_key);
void clue(Room &r, string diff);
void enter_rm(Room &r, string diff, int found_num);

#endif
