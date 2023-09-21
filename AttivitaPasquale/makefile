main.exe:	item.o list.o main.o
	gcc item.o list.o main.o -o main.exe 
	
item.o:	item.c
	gcc -c item.c
	
list.o: list.c item.h
	gcc -c list.c
	
main.o:	list.h main.c
	gcc -c main.c

clean:
	rm .f *o *.exe