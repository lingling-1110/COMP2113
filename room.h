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
  int key_pos;
  int trap;
  int hp;
};

void Room1(Room &r, int diff);
void Room2(Room &r, int diff);
void Room3(Room &r, int diff);
void Room4(Room &r, int diff);

void roomInfo(Room &r);

#endif
