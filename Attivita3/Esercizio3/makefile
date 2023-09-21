test_inserisci.exe:	vettore.o test_inserisci.o
	gcc vettore.o test_inserisci.o -o test_inserisci.exe

vettore.o:	vettore.c
	gcc -c vettore.c

test_inserisci.o:	vettore.h test_inserisci.c
	gcc -c test_inserisci.c