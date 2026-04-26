#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include "player.h"

using namespace std;

class Room {
public:
  Room();
  Room(int t, int lev, string n);

  int getType();
  string getName();
  bool getDone();
  void setDone(bool lev);

private:
  int room_type;
  string room_name;
  int level;
  bool done;
};
