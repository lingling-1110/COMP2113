#include "utils.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;

static bool seeded = false;

void seed() { 
    if (!seeded) { 
        srand(time(0)); 
        seeded = true; 
    } 
}

int randNum(int min, int max) { 
    seed(); 
    return min + rand() % (max - min + 1); 
}

bool chance(int percent) { 
    seed(); 
    return (rand() % 100) < percent; 
}

string clue() {
    string c[] = {"Under desk", "Behind painting", "Under tile", "In bookshelf"};
    return c[randNum(0, 3)];
}

string riddle() {
    string r[] = {"What has keys but no locks?", "What gets wetter as it dries?"};
    return r[randNum(0, 1)];
}

string riddleAns(string q) {
    if (q.find("keys") != string::npos) 
        return "piano";
    return "towel";
}

string mathQ() {
    stringstream ss;
    ss << randNum(1, 10) << " + " << randNum(1, 10);
    return ss.str();
}

int mathA(string q) {    // ADD THIS FUNCTION
    int a, b;
    char op;
    stringstream ss(q);
    ss >> a >> op >> b;
    return a + b;
}

void pause() {           // ADD THIS FUNCTION
    cout << "Press Enter...";
    cin.ignore();
    cin.get();
}
