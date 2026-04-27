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
  r.ans = 0;
  r.trap = 0;
}

void create_rm(Room &r, int num, string name, string diff) {
  r.room_num = num;
  r.room_name = name;
  r.locked = false;
  
  int multi;
  if (diff == "EASY") {
    multi = 0;
  } else if (diff == "MEDIUM") {
    multi = 1;
  } else if (diff == "HARD") {
    multi = 2;
  }

  r.trap = multi * 10;
  
  if (num == 2) {
    r.ans = 9999;
  } else {
    r.ans = 0;
  }
}

void clue(Room &r, string diff) {
  if (diff == "EASY") {
    cout << "[It's time for hints!]" << endl;
    cout << "The password is: " << r.ans << endl;
  } else if (diff == "MEDIUM") {
    cout << "[It's time for hints!]" << endl;
    cout << "The password starts with 9." << endl;
  } else if (diff == "HARD") {
    cout << "Almost there! You can do it!" << endl;
  }
}

void enter_rm(Room &r, string diff) {
  cout << "You are entering " << r.room_name << "." << endl;

  if (r.room_num == 1) {
    cout << "This room is locked! Find a key to escape!" << endl;
  } else if (r.room_num == 2) {
    cout << "There's a combination lock in front of you!" << endl;
    clue(r, diff);
  } else if (r.room_num == 3 && diff == "EASY") {
    cout << "There are traps! Be careful!" << endl;
  } else if (r.room_num == 3 && diff == "MEDIUM") {
    cout << "There are some traps! Watch your steps!" << endl;
  } else if (r.room_num == 3 && diff == "HARD") {
    cout << "Danger! There are so many traps! Mind your health!" << endl;
  } else if (r.room_num == 4) {
    cout << "The exit is overthere! Grab the last item and let's go!" << endl;
  }
}
