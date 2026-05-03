Escape the Room
COMP2113 Group Project - Semester 2, 2025-2026

## Escape the Room!  - Game Description 🎮
A text-based game built in C++. Players are asked to solve puzzles, avoid traps, collects items and find their way to escape the room.
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
| Dynamic memory                  | Dynamic array for inventory          |
| File I/O                        | Save/load game                 |
| Program codes in multiple files  |  Main, game, player, room, utils, save (separate .h / .cpp)      |
| Difficulty levels               | Easy / Medium / Hard — different clues, trap damage, puzzle difficulty|

## Non-standard libraries🗂️
Not used, standard libraries only.
## How to run
```bash
make
```
```bash
./game
```
## How to Play 🤪
1. Launch the game, choose 1 = New Game or 2 = Load Saved Game.
2. If you choose new game, select the difficulty.
3. Use W A S D to move your player around the map.
4. There are total 4 rooms for you to escape.
5. Press L anytime to save your game progress, and press Q to quit the game.
6. If your HP drops to 0 → Game Over.
7. If you pass the Final Level → You Win & Escape the building.

## Description for each level
Level 1 Rules:

Find and pick up the Key on the map.

Bring the key to the Door (D) to unlock and go to next room.

Level 2 Rules:

Walk to the M spot first to answer a math puzzle.

After solving correctly, go to Door (D) to proceed.

You cannot open the door before solving the puzzle at M.

Level 3 Rules:

No key or puzzle required — just walk to the Door to advance. However, you need to advoid any bump.

Final Level Rules:

Need both collect Key + solve Math puzzle to escape.


### File Overview
| File           | Author         | Purpose                                                                 |
|----------------|----------------|-------------------------------------------------------------------------|
| main.cpp       | Ip Hoi Ling    | Program entry point, initializes the game and starts the main loop.     |
| constants.h    | Ip Hoi Ling    | Defines global constants such as map dimensions, level IDs, and difficulty values. |
| Makefile       | Ip Hoi Ling    | Automates the build process. |
| game.h         | Ip Hoi Ling    | Declares core game logic, level progression, and state management functions. |
| game.cpp       | Ip Hoi Ling    | Implements game flow, level transitions, player actions, door/puzzle checks, and save/load integration. |
| room.h         | Chiu Wing Tung | Defines the `Room` structure, map setup, trap handling, and helper functions for room logic. |
| room.cpp       | Chiu Wing Tung | Implements room initialization, dynamic trap placement, map printing, and key position hints. |
| save.h         | Chiu Wing Tung | Declares the save/load system interface for storing and restoring player progress. |
| save.cpp       | Chiu Wing Tung | Implements file handling for saving and loading player data to/from a file. |
| player.h       | Wang You       | Defines the `Player` structure, including stats (HP, position, inventory) and related constants. |
| player.cpp     | Wang You       | Implements player movement, inventory management, and cleanup for dynamically allocated inventory arrays. |
| utils.h        | Wang You       | Declares utility functions such as trap damage handling and math puzzle generation. |
| utils.cpp      | Wang You       | Implements math puzzles (with difficulty scaling) and trap effects. |
## Team members 😏
1. Ip Hoi Ling 3036665753
2. Chiu Wing Tung 3036216667
3. Wang You 3036478459
