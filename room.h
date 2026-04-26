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
  
  string getName();
  int getDiff();
  bool checkDone();
  void setDone(bool val);
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
