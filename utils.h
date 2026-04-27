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
int mathA(string q);
void pause();

#endif
