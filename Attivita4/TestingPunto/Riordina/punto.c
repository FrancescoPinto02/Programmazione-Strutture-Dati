#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "punto.h"

struct pto
{
    float x;
    float y;
};


punto creaPunto (float x, float y){
    //crea e alloca dinamicamento un nuovo punto
    punto p=calloc(1,sizeof(*p));
    //assegna x e y rispettivamente ai campi .x e .y 
    p->x=x; 
    p->y=y;
    //restituisce p (il passaggio avviene per valore)
    return p;
}

float ascissa (punto p){
    //restituisce il valore del campo p.x
    return p->x;
}

float ordinata (punto p){
    //restituisce il valore del campo p.y
    return p->y;
}

float distanza (punto p1, punto p2){
    float dx, dy, d;
    //calcola distanza ascissa e ordinata
    dx=p1->x-p2->x;
    dy=p1->y-p2->y;
    //calcola e restituisce distanza punti
    d=sqrt((dx*dx)+(dy*dy));
    return d;
}

void stampa (punto p){
    printf("X = %f\nY = %f\n", p->x, p->y);
}

void finput_array(char *file_name, punto arr[], int n)
{
	int i;
    float x, y;
	FILE *fd;

	fd=fopen(file_name, "r");
	if( fd==NULL )
		printf("Errore in apertura del file %s \n", file_name);
	else {
		for(i=0; i<n; i++){
			fscanf(fd, "%f%f", &x, &y);
            arr[i]=creaPunto(x,y);
        }
		fclose(fd);
		}
}

void foutput_array(char *file_name, punto arr[], int n) 
{  
	int i;  
	FILE *fd; 	

	fd=fopen(file_name, "w"); 		
	if( fd==NULL ) 
		printf("Errore in apertura del file %s \n", file_name);    
	else {
		for(i=0; i<n; i++){      
			fprintf(fd, "%f %f\n", ascissa(arr[i]), ordinata(arr[i]));
        }		
		fclose(fd); 
		}
}

int confronta_array(punto arr1[], punto arr2[], int n){
    int i;
    for(i=0; i<n; i++){
        if(ascissa(arr1[i])!=ascissa(arr2[i]) || ordinata(arr1[i])!=ordinata(arr2[i])){
            return 0;
        }
    }
    return 1;
}