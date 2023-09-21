main.exe:	punto.o main.o
	gcc punto.o main.o -o main.exe

punto.o:	punto.c
	gcc -c punto.c

main.o:	punto.h main.c
	gcc -c main.c