#include <iostream>
#include <string>
#include "room.h"

using namespace std;

void def(Room &r) {
  r.id = 1;
  r.room_name = "";
  r.desc = "";
  r.locked = false;
  r.key = "";
  r.ans = INT_MAX;
  r.trap = 0;
}
