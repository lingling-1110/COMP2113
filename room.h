#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

using namespace std;

struct Room {
  int room_id;
  string room_name;
  string desc;
  bool locked;
  string key;
  int ans;
  int location;
  int dan_path;
  int hp;
};


#endif
