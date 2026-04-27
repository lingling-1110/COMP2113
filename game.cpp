
#include <iostream>
#include <cstdlib>
#include <ctime> 
#include "game.h"

using namespace std;


Game::Game() {
  totalRooms = 4;
  rooms = nullptr;
  isRunning = true;
}

Game::~Game() {
  delete[] rooms;
}

// to start the game
void Game::start() {

  cout << "Welcome to Escape the Room!" << endl;

}
