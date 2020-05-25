CC=c99
CFLAGS=-Wall -Wextra -pedantic -O0 -g -lm -Wno-unused-variable -Wno-unused-parameter -no-pie
AS=as

all: main

main: main.o funcion.o	
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

funcion.o: funcion.asm 
	$(AS) -o $@ $<
clean:
	rm -f *.o
	rm -f main
