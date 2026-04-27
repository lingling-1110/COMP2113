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

void clue(Room &r, string dif) {
  cout << "[It's time for hints!]" << endl;
  if (dif == "EASY") {
    cout << "The password is: " << r.ans << endl;
  }
  else if (dif == "MEDIUM") {
    cout << "The password starts with 9." << endl;
  else if (dif == "HARD") {
    cout << "You can do it!" << endl;
  }
  }

void enter_rm(Room &r, int diff) {
  cout << "You are entering " << r.name << endl;

  if (r.num == 1) {
    cout << "This room is locked! Find a key to escape!" << endl;
  } else if (r.num == 2) {
    cout << "There's a combination lock in front of you!" << endl;
    clue(r, dif);
  } else if (r.num == 3) {
    cout << "There are traps! Mind your health!" << endl;
    if (dif == HARD) {
      cout << "Oh no! More traps than expected! Be careful!" << endl;
    }
  } else if (r.num == 4) {
    cout << "The exit is overthere! Grab the last item and let's go!" << endl;
  }
}
