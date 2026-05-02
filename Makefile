CC = g++

FLAGS = -Wall -std=c++11

OBJS = main.o game.o player.o room.o utils.o save.o

game: $(OBJS)
	$(CC) $(OBJS) -o game

main.o: main.cpp game.h
	$(CC) $(FLAGS) -c main.cpp

game.o: game.cpp game.h player.h room.h utils.h save.h
	$(CC) $(FLAGS) -c game.cpp

player.o: player.cpp player.h constants.h
	$(CC) $(FLAGS) -c player.cpp

room.o: room.cpp room.h player.h constants.h
	$(CC) $(FLAGS) -c room.cpp

utils.o: utils.cpp utils.h constants.h
	$(CC) $(FLAGS) -c utils.cpp

save.o: save.cpp save.h player.h
	$(CC) $(FLAGS) -c save.cpp

.PHONY: clean
clean:
	rm -f *.o game
