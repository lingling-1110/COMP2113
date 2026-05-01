#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "room.h"

using namespace std;

void def(Room &r) {
  r.id = 0;
  r.layout = nullptr;
  r.room_name = "";
  r.desc = "";
  r.unlocked = true;
  r.ans = 0;
  r.result = 0;
  r.item_pos = 0;
  r.trap = 0;
  r.trap_pos = 0;
  r.item_num = 0;
  r.trapX = 0;
  r.trapY = 0;
}

bool able(Room &r, int x, int y) {
  if (r.layout[y][x] == '#') {
    return false;
  } 
  return true;
}

void create_rm(Room &r, int num, string name, string diff) {
  free_rm(r);
  r.id = num;
  r.room_name = name;
  
  if (num == 1 || num == 4) {
    r.unlocked = false;
  } else {
    r.unlocked = true;
  }
  
  int multi = 0;
  if (diff == "EASY") {
    multi = 1;
  } else if (diff == "MEDIUM") {
    multi = 2;
  } else if (diff == "HARD") {
    multi = 3;
  }

  r.trap = multi * 10;
  
  if (num == 1) {
    r.item_pos = rand() % 3 + 1;
    r.desc = "Three mysterious cabinets surround you. A key is needed to open the door.";
  } else if (num == 2) {
    r.ans = rand() % 9000 + 1000;
    r.desc = "A door with a 4-digit keypad.";
  } else if (num == 3) {
    r.trapX = 5;
    r.trapY = 2;
    r.desc = "The floor tiles look suspicious...";
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
    r.desc = "The final exit. Solve this to escape: " + to_string(x) + " x " + to_string(y);
  }

  r.w = 12;
  r.h = 6;

  r.layout = new char*[r.h];
  for (int i = 0; i < r.h; i++) {
    r.layout[i] = new char[r.w];
  }
  
  for (int i = 0; i < r.h; i++) {
    for (int j = 0; j < r.w; j++) {
      if (i == 0 || i == r.h - 1 || j == 0 || j == r.w - 1) {
        r.layout[i][j] = '#';
      } else {
        r.layout[i][j] = '.';
      }
    }
  }

  r.layout[3][10] = 'E';
  
}

void visual_map(Room &r, int pX, int pY) {

  if (system("clear") != 0) {
    system("cls");
  }

  cout << " --- " << r.room_name << " --- " << endl;
  
  for (int i = 0; i < r.h; i++) {
    for (int j = 0; j < r.w; j++) {
      if (i == pY && j == pX) {
        cout << "P";
      } else {
        cout << r.layout[i][j];
      }
    }
    cout << endl;
  }
}

bool inTrap(Room &r, int pX, int pY) {
  if (r.id == 3 && pX == r.trapX && pY == r.trapY) {
    cout << "OH NO! YOU TRIGGERED A TRAP!" << endl;
    cout << "You lost " << r.trap << " HP!" << endl;
    return true;
  }

  return false;
}

void discover(Room &r, int sel, bool &found_key) {
  found_key = false;
  
  if (r.id == 1) {
    if (sel == r.item_pos) {
      cout << "You found the key!" << endl;
      r.unlocked = true;
      found_key = true;
    } else {
      cout << "Arghhh! So many dust! But nothing useful..." << endl;
    }
  } else if (r.id == 4) {
    found_key = true;
    string items[3] = {"An emergency flare", "A security bypass keycard", "A rusty crowbar"};
    cout << items[rand() % 3] << " is found among the trash!" << endl;
  }
}

void clue(Room &r, string diff) {
  if (diff == "EASY" || diff == "MEDIUM") {
    cout << "[It's time to get some hints!]" << endl;
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

  if (r.id == 1) {
    cout << "This room is locked! Find a key to escape!" << endl;
  } else if (r.id == 2) {
    cout << "There's a combination lock in front of you! Try to solve it!" << endl;
    clue(r, diff);
  } else if (r.id == 3 && diff == "EASY") {
    cout << "There are traps! Be careful!" << endl;
  } else if (r.id == 3 && diff == "MEDIUM") {
    cout << "There are some traps! Watch your steps!" << endl;
  } else if (r.id == 3 && diff == "HARD") {
    cout << "Danger! Traps everywhere! Mind your health!" << endl;
  } else if (r.id == 4) {
    int remain = r.item_num - found_num;
    if (remain > 0) {
      cout << "The exit is overthere! Find " << remain << " more items!" << endl;
    } else {
      cout << "You have everything! The door is opened!" << endl;
      r.unlocked = true;
    }
  }
}

void free_rm(Room &r) {
  if (r.layout != nullptr) {
    for (int i = 0; i < r.h; i++) {
      delete[] r.layout[i];
    }
    delete[] r.layout;
    r.layout = nullptr;
  }
}
