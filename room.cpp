#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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
  
  if (num == 4) {
    r.locked = true;
  } else {
    r.locked = false;
  }
  
  int multi = 0;
  if (diff == "EASY") {
    multi = 0;
  } else if (diff == "MEDIUM") {
    multi = 1;
  } else if (diff == "HARD") {
    multi = 2;
  }

  r.trap = multi * 10;

  if (num == 1) {
    r.item_pos = rand() % 3 + 1;
  } else if (num == 2) {
    r.ans = rand() % 9000 + 1000;
  } else if (num == 3) {
    r.trap_pos = rand() % 3 + 1;
  } else if (num == 4) {
    if (diff == "EASY") {
      r.item_num = 1;
    } else if (diff == "MEDIUM") {
      r.item_num = 2;
    } else if (diff == "HARD") {
      r.item_num = 3;
    }

    int x = rand() % 10 + 1;
    int y = rand() % 10 + 1;
    r.result = x * y;
    r.ans = r.result;
  }
}

void discover(Room &r, int sel){
  if (r.room_num == 1) {
    if (sel == r.item_pos) {
      cout << "You found the " << r.key << "!" << endl;
    } else {
      cout << "Arghhh! So many dust! But nothing useful..." << endl;
    }
  }
}

void clue(Room &r, string diff) {
  if (diff == "EASY" || diff == "MEDIUM") {
    cout << "[It's time for hints!]" << endl;
  }
  if (diff == "EASY") {
    cout << "The password is: " << r.ans << endl;
  } else if (diff == "MEDIUM") {
    cout << "The password starts with " << r.ans / 1000 << "." << endl;
  } else if (diff == "HARD") {
    cout << "Almost there! You can do it!" << endl;
  }
}

void enter_rm(Room &r, string diff, int found_num) {
  cout << "You are entering " << r.room_name << "." << endl;

  if (r.room_num == 1) {
    cout << "This room is locked! Find a key to escape!" << endl;
  } else if (r.room_num == 2) {
    cout << "There's a combination lock in front of you! Try to solve it!" << endl;
    clue(r, diff);
  } else if (r.room_num == 3 && diff == "EASY") {
    cout << "There are traps! Be careful!" << endl;
  } else if (r.room_num == 3 && diff == "MEDIUM") {
    cout << "There are some traps! Watch your steps!" << endl;
  } else if (r.room_num == 3 && diff == "HARD") {
    cout << "Danger! Traps everywhere! Mind your health!" << endl;
  } else if (r.room_num == 4) {
    if (r.item_num > 1) {
      cout << "The exit is overthere! Grab " << r.item_num << "items and let's go!" << endl;
    } else {
      cout << "The exit is overthere! Grab " << r.item_num << "item and let's go!" << endl;
    }

    int remain = r.item_num - found_num;

    if (remain > 0) {
      cout << "Almost done! " << remain << " more to go!" << endl;
    } else {
      cout << "You have everything you need!" << endl;
    }
  }
}
