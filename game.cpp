
#include <iostream>
#include <cstdlib>
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
  cout << "Please choose your difficulty preference (0=Easy, 1=Medium, 2=Hard): ";

  int n;
  cin >> d;
  difficulty = static_cast<Difficulty>(n);

  player.hp = 3;
  player.roomnum = 0;

  Roomssetup();

}

// set up the room
void Game:Romssetup(){
  rooms = new Room[totalRooms];

  for (int i = 0; i < totalRooms; i++) {
    room[i].id = i;
    room[i].unlocked = false;
  }
}

// Display status
void Game::displayStatus() {
  cout << "\n--- Current Status ---" << endl;
  cout << "Your HP: " << player.hp << endl;
  cout << "Room: " << player.roomIndex + 1 << endl;
}

// process player input
void Game::processInput() {
  cout << "Choose action: (0=search, 1=move, 2=quit): ";

  int choice;
  cin >> choice;

  if (choice == 0) {
    solveRoomEvent();
  }
  elif (choice == 2) {
    if (rooms[player.roomnum].unlocked){
      nextRoom();
    } else {
      cout << "You must unlocked this room first." << endl;
    }
  }
  else if (choice == 3) {
    gameOver = true
  }
}

// moving to next room
void Game::nextRoom() {
  player.roomnum++;

  if (player.roomnum >= totalRooms) {
    cout << "You escaped all the Rooms successfully!" << endl;
    gameOver = true;
  }
}

// Handle random event (draft) not finished
void Game::handleRoomEvent() {
    int event = rand() % 3;

    if (event == 0) {
        cout << "You found a key! Room cleared." << endl;
        rooms[player.roomIndex].cleared = true;
    } 
    else if (event == 1) {
        cout << "Trap triggered! You lose 1 HP." << endl;
        player.hp--;

        if (player.hp <= 0) {
            cout << "You died!" << endl;
            gameOver = true;
        }
    } 
    else {
        cout << "Nothing found..." << endl;
    }
}

// Check game over
bool Game::isGameOver() {
    return gameOver;
}















