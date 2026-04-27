#include <iostream>
#include <string>
#include "room.h"

using namespace std;

void def(Room &r) {
  r.room_num = 1;
  r.room_name = "";
  r.desc = "";
  r.locked = false;
  r.key = "";
  r.ans = INT_MAX;
  r.trap = 0;
}

void create_rm(Room &r, int num, string name, int diff) {
  r.room_num = num;
  r.room_name = name;
  r.locked = false;
  r.trap = diff * 10;

  if (num == 2) {
    r.ans = 9999;
  } else {
    r.ans = 0;
  }
  }

void clue(Room &r, string diff) {
  cout << "[It's time for hints!]" << endl;
  if (diff == "EASY") {
    cout << "The password is: " << r.ans << endl;
  }
  else if (diff == "MEDIUM") {
    cout << "The password starts with 9." << endl;
  else if (diff == "HARD") {
    cout << "You can do it!" << endl;
  }
  }

