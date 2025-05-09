all: main
main : main.o
			gcc main.o -o main
clean:
		rm -f *.o
%.o: %.c
		gcc -c -Wall -ansi $<
