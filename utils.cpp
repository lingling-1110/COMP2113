#include "utils.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


bool randSeeded = false;

void handleTrapDamage(int& hp, int difficulty) {
    hp -= 10;
    cout << "\n💣 BOMB TRAP! You HP -10 !" << endl;
    cout << "HP LEFT: " << hp << endl;
    cout << "(Press Enter to continue...)" << endl;
    cin.ignore();
    cin.get();
}

bool solveMathPuzzle(int difficulty) {
    // Seed random once
    if (!randSeeded) {
        srand(time(0));
        randSeeded = true;
    }

    int a, b, ans, userAns;
    char op;

// there will only be + or - in difficulty 0
    if (difficulty == 0) {
        a = rand() % 15 + 1;
        b = rand() % 15 + 1;
        if (rand() % 2 == 0) {
            op = '+';
            ans = a + b;
        } else {
            op = '-';
            // Ensure no negative answer
            if (a < b) swap(a, b);
            ans = a - b;
        }
    }
//there will only be +/ in difficulty 1
    else if (difficulty == 1) {
        if (rand() % 2 == 0) {
            a = rand() % 12 + 1;
            b = rand() % 12 + 1;
            op = '*';
            ans = a * b;
        } else {
            b = rand() % 10 + 1;
            ans = rand() % 10 + 1;
            a = b * ans;
            op = '/';
        }
    }

    else {
        int type = rand() % 4;
        if (type == 0) {
            a = rand() % 20 + 1;
            b = rand() % 20 + 1;
            op = '+';
            ans = a + b;
        } else if (type == 1) {
            a = rand() % 20 + 1;
            b = rand() % 20 + 1;
            if (a < b) swap(a, b);
            op = '-';
            ans = a - b;
        } else if (type == 2) {
            a = rand() % 15 + 1;
            b = rand() % 15 + 1;
            op = '*';
            ans = a * b;
        } else {
            b = rand() % 12 + 1;
            ans = rand() % 12 + 1;
            a = b * ans;
            op = '/';
        }
    }

    // Show question
    cout << "\nSolve: " << a << " " << op << " " << b << " = ";
    cin >> userAns;

    if (userAns == ans) {
        return true;
    } else {
        return false;
    }
}
