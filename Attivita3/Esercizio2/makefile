test_ordina.exe:	utile.o vettore.o test_ordina.o
	gcc utile.o vettore.o test_ordina.o -o test_ordina.exe

utile.o:	utile.c
	gcc -c utile.c

vettore.o:	vettore.c utile.h
	gcc -c vettore.c

test_ordina.o:	vettore.h test_ordina.c
	gcc -c test_ordina.c