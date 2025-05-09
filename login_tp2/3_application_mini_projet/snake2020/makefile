CC = gcc
CFLAGS = -Wall -ansi

all: snake

snake: game.o grid.o
	$(CC) $(CFLAGS) -o snake game.o grid.o -lMLV

game: game.c grid.h
	$(CC) $(CFLAGS) -c game.c -lMLV

grid: grid.c grid.h
	$(CC) $(CFLAGS) -c grid.c -lMLV

clean:
	rm -f *.o
