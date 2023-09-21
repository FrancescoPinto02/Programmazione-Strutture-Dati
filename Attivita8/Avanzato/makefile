main.exe:	item.o queue.o main.o
	gcc item.o queue.o main.o -o main.exe 
	
item.o:	item.c
	gcc -c item.c
	
queue.o: queue.c item.h
	gcc -c queue.c
	
main.o:	queue.h main.c
	gcc -c main.c

clean:
	rm .f *o *.exe