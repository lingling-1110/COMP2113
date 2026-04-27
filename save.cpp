#include <fstream>
#include <iostream>

#include "save.h"

using namespace std;

void save(const Room &r, const string &fname) {
  ofstream fout;
  fout.open(fname);

  if (fout.fail()) {
    cout << "The file could not be opened for saving >_<" << endl;
  } else {
    fout << r.id << endl;
    fout << r.room_name << endl;
    fout << r.desc << endl;
    fout << r.locked << endl;
    fout << r.ans << endl;
    fout << r.trap << endl;

    fout.close();
  }
}

bool load(Room &r, const string &fname) {
  ifstream fin;
  fin.open(fname);

  if (!fin.fail()) {
    fin >> r.id;
    fin.ignore();
    getline(fin, r.room_name);
    getline(fin, r.desc);
    fin >> r.unlocked;
    fin >> r.ans;
    fin >> r.trap;

    fin.close();
    return true;
  }

  return false;
  
}

void del(const string &fname) {
  ofstream ofs(fname);
  ofs.close();
  cout << "Save file cleared." << endl;
}
