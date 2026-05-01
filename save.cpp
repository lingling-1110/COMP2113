#include <fstream>
#include <iostream>

#include "save.h"
#include "player.h"

using namespace std;

void save(const Room &r, const string &fname) {
  ofstream fout;
  fout.open(fname);
  
  if (fout.fail()) {
    cout << "The file could not be opened for saving >_<" << endl;
  } else {
    fout << p.getHp() << endl;
    fout << p.getLevel() << endl;
    fout << p.getDiff() << endl;
    
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

bool load(Room &r, const string &fname) {
  ifstream fin;
  fin.open(fname);

  if (fin.fail()) {
    return false;
  }

  int currHp, currLev, currDiff;

  fin >> currHp >> currLev >> currDiff;

  p.setHp(currHp);
  p.setLevel(currLev);
  p.setDiff(currDiff);
  
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
  return true;

  r.layout = new char*[r.h];
  for (int i = 0; i < r.h; i++) {
    r.layout[i] = new char[r.w];
  }
}

void del(const string &fname) {
  ofstream ofs(fname);
  ofs.close();
  cout << "Save file cleared." << endl;
}
