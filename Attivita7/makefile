main.exe:	item.o stack.o main.o
	gcc item.o stack.o main.o -o main.exe 
	
item.o:	item.c
	gcc -c item.c
	
stack.o: stack.c item.h
	gcc -c stack.c
	
main.o:	stack.h main.c
	gcc -c main.c

clean:
	rm .f *o *.exe