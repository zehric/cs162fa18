all: main

# Link main, dependent on *.o files
main: violet.o main.o
	gcc violet.o main.o -o main

# Compile violet.o, dependent on source and header files
violet.o: violet.c violet.h
	gcc -c violet.c -o violet.o

# Compile main.o, dependent on source and header files
main.o: main.c violet.h
	gcc -c main.c -o main.o

clean:
	rm *.o main
