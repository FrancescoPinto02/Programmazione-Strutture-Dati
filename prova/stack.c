#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "item.h"

struct node{
    item value;
    struct node * next;
};

struct c_stack{
    struct node * top;
    int numel;
};

//Crea un nuovo stack
stack newStack(void){
    stack s=malloc(sizeof(*s));  //Crea e alloca un nuovo stack
    if(!s){  //Se l`allocazione è fallita restituisce NULL
        printf("Allocazione fallita\n");
        return NULL;
    }
    s->top=NULL;  //Se l`allocazione non è fallita assegna NULL a s->top
    s->numel=0;  //Assegna 0 a numel
    return s;  //Restituisce lo stack
}

//Controlla se lo stack è vuoto
int emptyStack(stack s){
    if(!s || s->numel<0){  //Restituisce -1 in caso di problemi con allocazione o con il numero di elementi
        return -1;
    }

    if(s->numel == 0){  //Se lo stack è vuoto restituisce 1
        return 1;
    }
    else {  //Altrimenti restituisce 0
        return 0;
    }
}

//Elimina l`elemento in cima allo stack
int pop(stack s){
    struct node * tmp;

    if(emptyStack(s)){  //Se lo stack è vuoto la pop fallisce e restituisce 0
        return 0;
    }
    else{  //Altrimenti se lo stack non è vuoto
        tmp=s->top;  //il primo nodo viene memorizzato in una variabile temporanea
        s->top=tmp->next;  //top punterà al nodo successivo che quindi diventerà il primo
        free(tmp);  //viene deallocato il nodo che era in cima
        (s->numel)--;  //numel viene decrementato
        return 1;  //Restituisce 1 perchè la pop è andata a buon fine
    }
}

//Aggiunge un elemento nello stack
int push(stack s, item val){
    struct node *new;  //Crea e alloca un nuovo nodo
    new=malloc(sizeof(struct node));
    if(!new){  //Se l`allocazione fallisce restituisce 0
        printf("Allocazione Fallita\n");
        return 0;
    }
    else{  //Altrimenti aggiunge il nuovo nodo in cima allo stack
        new->value=val;  
        new->next=s->top;
        s->top=new;
        (s->numel)++;  //incrementa numel
        return 1;  //Restituisce 1 perchè la push è andata a buon fine
    }
}

//Restituisce l`item in cima allo stack
item top(stack s){
    if(emptyStack(s)){  //Se lo stack è vuoto restituisce NULLITEM
        return NULLITEM;
    }
    else{  //Altrimenti restituisce l`item in cima allo stack
        return (s->top)->value;
    }
}