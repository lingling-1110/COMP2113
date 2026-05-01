#include <fstream>
#include <iostream>
#include <cstdio>

#include "save.h"
#include "player.h"

using namespace std;

void save(const Player &p, const Room &r, const string &fname) {
  ofstream fout;
  fout.open(fname);
  
  if (fout.fail()) {
    cout << "The file could not be opened for saving >_<" << endl;
  } else {
    fout << p.getHp() << endl;
    fout << p.getLevel() << endl;

    if (p.getDiff() == "EASY") {
      diffNum = 1;
    } else if (p.getDiff() == "MEDIUM") {
      diffNum = 2;
    } else if (p.getDiff() == "HARD") {
      diffNum = 3;
    }
    fout << diffNum << endl;
    
    fout << r.id << endl;
    fout << r.unlocked << endl;
    fout << r.ans << endl;
    fout << r.result << endl;
    fout << r.item_pos << endl;
    fout << r.item_num << endl;
    fout << r.trap << endl;
    fout << r.trapX << endl;
    fout << r.trapY << endl;
    fout << r.w << endl;
    fout << r.h << endl;

    fout.close();

    cout << "Progress saved to " << fname << endl;
  }
}

bool load(Player &p, Room &r, const string &fname) {
  ifstream fin;
  fin.open(fname);

  if (fin.fail()) {
    return false;
  }

  int currHp, currLev, currDiff;

  fin >> currHp >> currLev >> currDiff;

  p.setHp(currHp);
  p.setLevel(currLev);

  if (currDiff == 2) {
    p.setDiff("MEDIUM");
  } else if (currDiff == 3) {
    p.setDiff("HARD");
  } else {
    p.setDiff("EASY");
  }
  
  fin >> r.id;
  fin >> r.unlocked;
  fin >> r.ans;
  fin >> r.result;
  fin >> r.item_pos;
  fin >> r.item_num;
  fin >> r.trap;
  fin >> r.trapX;
  fin >> r.trapY;
  fin >> r.w;
  fin >> r.h;

  fin.close();

  free_rm(r);
  r.layout = new char*[r.h];
  for (int i = 0; i < r.h; i++) {
    r.layout[i] = new char[r.w];
    for (int j = 0; j < r.w; j++) {
      if (i == 0 || i == r.h - 1 || j == 0 || j == r.w - 1) {
        r.layout[i][j] = '#';
      } else {
        r.layout[i][j] = '.';
      }
    }
  }

  if (r.h > 3 && r.w > 10) {
    r.layout[3][10] = 'E';
  }
  
  return true;
}

void del(const string &fname) {
  if (remove(fname.c_str()) == 0) {
    cout << "Save file deleted." << endl;
  } else {
    cout << "No save file found to delete." << endl;
  }
}
