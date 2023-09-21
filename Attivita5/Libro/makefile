main.exe:	libro.o main.o
	gcc libro.o main.o -o main.exe

libro.o:	libro.c
	gcc -c libro.c

main.o:	libro.h main.c
	gcc -c main.c