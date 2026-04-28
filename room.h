#ifndef ROOM_H
#define ROOM_H

#include <string>

using namespace std;

struct Room {
  int id;
  string room_name;
  string desc;
  bool unlocked;
  int ans;
  int result;
  int item_pos;
  int item_num;
  int trap;
  int trap_pos;
  int trapX;
  int trapY;
  int w;
  int h;
  char layout[6][12];
};

void def(Room &r);
bool able(Room &r, int x, int y);
void create_rm(Room &r, int num, string name, string diff);
void visual_map(Room &r, int pX, int pY);
bool inTrap(Room &r, int pX, int pY);
void discover(Room &r, int sel, bool &found_key);
void clue(Room &r, string diff);
void enter_rm(Room &r, string diff, int found_num);

#endif
