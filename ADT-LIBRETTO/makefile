main.exe:	item.o list.o libretto.o main.o
	gcc item.o list.o libretto.o main.o -o main.exe 
	
item.o:	item.c
	gcc -c item.c
	
list.o: list.c item.h
	gcc -c list.c
	
libretto.o:	libretto.c list.c
	gcc -c libretto.c

main.o: main.c libretto.c
	gcc -c main.c

clean:
	rm .f *o *.exe