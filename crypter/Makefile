.PHONY: all clean
all: encrypt decrypt test

clean:
	rm.exe -f main.o crypto.o test.o encrypt.exe decrypt.exe test.exe

main.o: main.c
	gcc.exe -Wall -c main.c

crypto.o: crypto.c
	gcc.exe -Wall -c crypto.c

test.o: test.c
	gcc.exe -Wall -c test.c

encrypt: main.o crypto.o
	gcc.exe -o encrypt main.o crypto.o

decrypt: main.o crypto.o
	gcc.exe -o decrypt main.o crypto.o

test: test.o crypto.o
	gcc.exe -o test test.o crypto.o
	.\test.exe