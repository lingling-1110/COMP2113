#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include "player.h"

using namespace std;

class Room {
public:
  Room();
  Room(int t, int diff, string n);

  int getType();
  string getName();
  bool checkDone();
  void setDone(bool b);
  void start(Player &p);
  void clue();
  
private:
  int type;
  string name;
  int diff;
  bool done;
  string key;
};

#endif
