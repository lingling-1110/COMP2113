#ifndef UTILS_H
#define UTILS_H

#include <string>
using namespace std;

int randNum(int min, int max);
bool chance(int percent);
string clue();
string riddle();
string riddleAns(string q);
string mathQ();
int mathA(string q);      // ADD THIS
void pause();              // ADD THIS
void seed();               // ADD THIS (if used elsewhere)

#endif
