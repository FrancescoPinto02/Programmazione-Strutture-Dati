#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"

#define STARTSIZE 50
#define ADDSIZE 20

struct c_stack{
    item *arr;  //Array di Item
    int size;  //dimensione corrente array
    int top;  //indice primo spazio libero
};

//Crea un nuovo stack 
stack newStack(void){
    stack s = malloc(sizeof(*s)); //Allocazione spazio per stack e controllo
    if(!s){
        printf("Allocazione fallita!\n");
        return NULL;  //restituisce NULL se l`allocazione fallisce
    }

    s->arr=calloc(STARTSIZE, sizeof(item)); //Allocazione array di item e controllo
    if(!(s->arr)){
        printf("Allocazione fallita!\n"); 
        return NULL;  //Restituisce NULL se l`allocazione fallisce
    }

    s->size=STARTSIZE;  //Inizializza s->size a STARTSIZE (50)
    s->top=0;  //Inizializza top a 0
    return s;  //Restituisce lo stack
}

//Controlla se lo stack è vuoto
int emptyStack(stack s){
    if(s->top==0){ //Se lo stack è vuoto restituisce 1
        return 1;
    }
    else{  //Se non è vuoto restituisce 0
        return 0;
    }
}

//Elimina l`ultimo elemento inserito nello stack
int pop(stack s){
    if(s->top==0){  //Se lo stack è vuoto la pop fallisce
        return 0;  //Restituisce 0
    }
    else{  //Altrimenti viene cancellato l`elemento in cima allo stack decrementando top
        s->top--;
        return 1;  //La pop è andata a buon fine e restituisce 1
    }
}

//Inserisce un nuovo item dalla cima dello stack
int push(stack s, item val){
    if (s->top == s->size){  //Se l`array di Item è pieno deve essere ridimensionato
        item * tmp=realloc(s->arr, (s->size+ADDSIZE) * sizeof(item));  //viene effettuata una realloc che aggiunge altre ADDSIZE(20) celle 
        if(!tmp){  //Se l`allocazione fallisce non vengono apportate modifiche all`array originale perchè è stata usata una variabile temporanea (tmp)
            printf("realloc fallita!\n"); 
            return 0;  //Restituisce 0 perchè la push è fallita
        }
        else{  //Se l`allocazione è andata a buon fine 
            s->arr=tmp;  //Assegna all`array il nuovo indirizzo contenuto in tmp
            s->size = s->size + ADDSIZE;  //aumenta s->size di ADDSIZE(20)
        }
    }

    s->arr[s->top]=val;  //aggiunge l`item all`array
    (s->top)++;  //incrementa l`indice top
    return 1;  //Restituisce 1 perchè la push è andata a buon fine
}

//Restituisce l`item in cima allo stack
item top(stack s){
    if((s->top) <= 0){  //Se lo stack è vuoto restituisce NULLITEM
        return NULLITEM;
    }
    else{  //Altrimenti restituisce l`item in cima allo stack
        return s->arr[(s->top)-1];
    }
}

stack cloneStack(stack s){
    stack clone=newStack();
    clone->size=s->size;
    clone->top=s->top;
    clone->arr=calloc(clone->size, sizeof(item));
    if(!clone->arr){
        printf("Errore di allocazione\n");
        return NULL;
    }
    for(int i=0; i<clone->top; i++){
        clone->arr[i]=s->arr[i];
    }
    return clone;
}

void freeStack(stack s){
    free(s->arr);
    free(s);
}

void clearStack(stack s){
    while(!emptyStack(s)){
        pop(s);
    }
}