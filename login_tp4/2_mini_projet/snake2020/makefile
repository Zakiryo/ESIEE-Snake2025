CC = gcc
CFLAGS = -Wall -ansi

all: snake2025

snake2025: game.o grid.o snake.o
	$(CC) $(CFLAGS) -o snake2025 game.o grid.o snake.o -lMLV

game.o: game.c grid.h
	$(CC) $(CFLAGS) -c game.c

grid.o: grid.c grid.h snake.h
	$(CC) $(CFLAGS) -c grid.c

snake.o: snake.c snake.h
	$(CC) $(CFLAGS) -c snake.c

clean:
	rm -f *.o snake2025
