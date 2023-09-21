#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"

char *xmalloc(size_t size);

struct miolibro{
    char *titolo;
    char *editore;
    float prezzo;
    int anno;
};

libro newLibro(char *titolo, char* editore, float prezzo, int anno){
    libro l=malloc(sizeof(*l));
    if(!l){
        printf("Allocazione Fallita!\n");
        return NULL;
    }
    
    l->titolo=xmalloc(sizeof(char) * (strlen(titolo)+1));
    strcpy(l->titolo,titolo);
    l->editore=xmalloc(sizeof(char) * (strlen(editore)+1));
    strcpy(l->editore,editore);
    l->prezzo=prezzo;
    l->anno=anno;
    return l;
}

char* get_titolo(libro l){
    return l->titolo;    
}

char* get_editore(libro l){
    return l->editore;  
}

int get_anno(libro l){
    return l->anno;
}

float get_prezzo(libro l){
    return l->prezzo;      
}

float sconto(libro l, float percentuale){
    float p; //Prezzo scontato
    p = (l->prezzo) - ((l->prezzo)/100)*percentuale; 
    l->prezzo=p;
    return p;
}

void aggiorna (libro l, int anno){
	l->anno=anno;	
}

char *xmalloc(size_t size){
    char *p;
    p=malloc(size);
    if (!p){
        printf("allocazione fallita!\n");
        return NULL;
    }
    return p;
}