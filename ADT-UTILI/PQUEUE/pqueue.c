#include <stdio.h>
#include <stdlib.h>
#include "pqueue.h"
#include "item.h"
#define MAXPQ 50


struct c_PQ{
    item vet[MAXPQ];
    int numel;
};

static void scendi (PQueue q);
static void sali (PQueue q);


PQueue newPQ(void){
    PQueue new = malloc(sizeof(struct c_PQ));
    if(!new){
        printf("Allocazione Fallita!\n");
        return NULL;
    }

    new->numel = 0;
    return new;
}

int emptyPQ(PQueue q){
    if(q->numel == 0){
        return 1;
    }
    else{
        return 0;
    }
}

item getMax(PQueue q){
    if(emptyPQ(q)){
        return NULLITEM;
    }
    else{
        return q->vet[1];
    }
}

int deleteMax(PQueue q){
    //CODA VUOTA
    if(!q || emptyPQ(q)){
        return 0;
    }

    //SPOSTO L`ULTIMO ELEMENTO IN PRIMA POSIZIONE
    q->vet[1] = q->vet[q->numel];
    (q->numel)--;

    scendi(q); //RIORDINO HEAP

    return 1;
}

static void scendi (PQueue q)
{
    int temp, n=q->numel, i=1, pos;

    while (1){

        // IL NODO CORRENTE HA 2 FIGLI
        if (2*i+1 <= n){
            pos =  (maggiore(q->vet[i*2], q->vet[i*2+1]))  ?   i*2  :   i*2+1;
        }               

        // IL NODO CORRENTE HA 1 FIGLIO
        else  if (2*i <= n){
            pos = 2*i;
        }                
        
        // IL NODO CORRENTE NON HA FIGLI
        else  break;                  

        // SCAMBIO LE CHIAVI E PROSEGUO 
        if (maggiore(q->vet[pos] , q->vet[i])){
            temp = q->vet[i];
            q->vet[i] = q->vet[pos];
            q->vet[pos] = temp;
            i = pos;
        }
        else{
            break; // NON CI SONO PIU’ SCAMBI DA FARE, MI FERMO
        }
    }
}

int insert (PQueue q, item entry){
    // CODA PIENA 
    if (!q || q->numel==MAXPQ) return 0; 

    // INSERISCI IN ULTIMA POSIZIONE
    q->numel++;
    q->vet[q->numel] = entry;   
    
    // AGGIUSTA LO HEAP RISALENDO
    sali(q);     

    return 1;
} 


static void sali (PQueue q){
    item temp; 
    int pos=q->numel, i=pos/2;

    while (pos>1)
    {         
        if (maggiore(q->vet[pos] , q->vet[i])){
            temp = q->vet[i];
            q->vet[i] = q->vet[pos];
            q->vet[pos] = temp;
            pos = i;
            i = pos/2;
        }
        else{
            break;
        }
    }
}
