test_somma_array.exe:	vettore.o test_somma_array.o
	gcc vettore.o test_somma_array.o -o test_somma_array.exe

vettore.o:	vettore.c
	gcc -c vettore.c

test_inserisci.o:	vettore.h test_somma_array.c
	gcc -c test_somma_array.c