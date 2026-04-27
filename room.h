#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include "player.h"

using namespace std;

class Room {
public:

  // Construct empty room
  Room();
  // Define what will be contain in the created room
  Room(int t, int diff, string n);

  // Get the name of the room
  string getName();
  // Get the difficulty
  int getDiff();
  // Check if the room is already done
  bool checkDone();
  // Set val to be true if the room is already done
  void setDone(bool val);
  // Initiate the room's event
  void start(Player &p);
  // Provide some clue to the player
  void clue();
  
private:
  int type;
  string name;
  int diff;
  bool done;
  string key;
};

#endif
