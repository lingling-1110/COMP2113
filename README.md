Excape the Building
COMP2113 Group Project - Semester 2, 2025-2026

## Game Description
A text-based escape room game built in C++. Players are asked to solve puzzles, avoid traps, collects items and find their way to escape the building.
## Game Features
- 4 Unique Room in each difficulty level: From the entrance to the final escape room, each room has its own theme and challenge.
- Inventory System: Collect keys, clues, and puzzle pieces to unlock new areas.
- Trap & Hazard System: Avoid random traps that can cost you HP or items.
Password & Riddle Puzzles: Solve math/logic riddles to unlock doors.
Save & Load: Pause your game and resume later with full progress saved.
Adjustable Difficulty: Players can choose difficulty preferences at the beginning of game.

| Requirement              | How we implement               |
|---------------------------------|--------------------------------|
| Random events                   | Random key/item spawns, random clue text, random trap placement      |
| Data structures                 | Structs for Player, Room, InventoryItem, and puzzles; linked list/array for inventory     |
| Dynamic memory                  | Dynamic array for all rooms           |
| File I/O                        | Save/load game                 |
| Program codes in multiple files  |  Main, game, player, room, utils, save (separate .h / .cpp)      |
| Difficulty levels               | Easy / Medium / Hard — different clues, trap damage, puzzle difficulty|

## Non-standard libraries
Not used, standard libraries only.
## How to run
Make sure you have C++ compiler , then:
Compile
```bash
g++ main.cpp game.cpp player.cpp room.cpp utils.cpp save.cpp -o escape_game
```
```bash
./escape_game
```
## How to Play
1.Run the executable and select New Game or Load Game from the main menu.
2.Choose your difficulty level: 
Easy: More clues, weaker traps, simple puzzles
Medium: Balanced challenge with limited hints
Hard: No hints, deadly traps, and complex riddles
3.Use text commands to move, interact with objects, and collect items.
4.Solve puzzles, avoid traps, and progress through all rooms to escape!
5.Use the save command at any time to save your progress.

### File Overview
| File                        | Author                      | Purpose                 |
|-----------------------------|-----------------------------|-------------------------|
| main.cpp                    | Hayley Ip                   |                         |
| game.h                      | Hayley Ip                   |  game logic, level progression, state managemen   |
| game.cpp                    | Hayley Ip                   |                         |
| room.h                      | Toby Chiu                   |                         |
| room.cpp                    | Toby Chiu                   |                         |
| (more files TBA as groupmates complete their parts)                   | Hayley Ip                   |                         |

## Team members
1. Ip Hoi Ling 3036665753
2. Chiu Wing Tung 3036216667
3. Wang You 3036478459
