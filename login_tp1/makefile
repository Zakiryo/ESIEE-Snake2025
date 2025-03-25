all: main
main : main.o
			gcc main.o -o main -lMLV
clean:
		rm -f *.o
%.o: %.c
		gcc -c -Wall -ansi $<
