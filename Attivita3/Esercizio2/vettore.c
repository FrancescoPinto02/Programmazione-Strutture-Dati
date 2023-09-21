// FILE:   vettore.c
// restituisce 1 se i due vettori di ingresso sono uguali, 0 altrimenti

#include "vettore.h"
#include <stdio.h>
#include <stdlib.h>

int confronta_array(int a[], int b[], int n) 
{  
	int i;
    for(i=0; i<n; i++){
        if(a[i]!=b[i]){
            return 0; //array diversi
        }
    }
    return 1; //array uguali
}

void foutput_array(char *file_name, int a[], int n) 
{  
	int i;  
	FILE *fd; 	

    fd=fopen(file_name, "w");
    if(!fd){
        printf("Errore apertura file!\n");
    }
    for(i=0; i<n; i++){
        fprintf(fd,"%d\n",a[i]);
    }
    fclose(fd);
    //controllare che il file sia stato aperto correttamente
    //e scrivere il contenuto (fprintf()) di a in fd
	
	// chiudere il file
}

void finput_array(char *file_name, int a[], int n)
{
	int i;
	FILE *fd;

    //apertura file in lettura
	fd=fopen(file_name, "r");
    if(!fd){
        printf("Errore apertura file!\n");
    }
	//Controllare se il file esiste e
	//leggere il contenuto (fscanf()) da scrivere in array a
	for(i=0; i<n; i++){
        fscanf(fd,"%d\n",&a[i]);
    }
	
	//chiudere il file
	fclose(fd);
}

void ordina(int a[], int n)
{
    int i, j;
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(a[j]<a[i]){
                scambia(&a[j], &a[i]);
            }
        }
    }
}