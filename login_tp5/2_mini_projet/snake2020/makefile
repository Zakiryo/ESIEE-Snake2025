CC = gcc
CFLAGS = -Wall -pedantic

all: snake2025

snake2025: game.o grid.o snake.o
	$(CC) $(CFLAGS) -o snake2025 game.o grid.o snake.o -lMLV

game.o: game.c grid.h
	$(CC) $(CFLAGS) -c game.c

snake.o: snake.c snake.h
	$(CC) $(CFLAGS) -c snake.c

grid.o: grid.c grid.h snake.h
	$(CC) $(CFLAGS) -c grid.c

clean:
	rm -f *.o
