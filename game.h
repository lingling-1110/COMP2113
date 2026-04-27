#ifndef GAME_H
#define GAME_H

#include <string>
using namespace std;

// difficulty setting
enum Difficulty { EASY, MEDIUM, HARD };

// player struct
struct Player  { 
  int hp;
  int roomnum;
};
// room struct
struct Room {
  int num;
  bool islocked;
};

class Game {
private:
  Player player;
  Room* rooms;
  int totalRooms;
  Difficulty difficulty;
  bool isRunning;

public:
  Game();
  ~Game(); //free dynamic memory

  void start()

#endif
