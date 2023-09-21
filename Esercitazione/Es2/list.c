#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"

struct c_list{
    struct node * first;
    int size;
};


struct node{
    item value;
    struct node *next;
};

list newList(void){
    list new;
    new=malloc(sizeof(*new));
    if(!new){
        printf("Allocazione fallita!\n");
        return NULL;
    }
    
    new->first=NULL;
    new->size=0;
    return new;
}

int emptyList(list l){
    if(l->size==0){
        return 1;
    }
    else{
        return 0;
    }
}

int sizeList(list l){
    return l->size;
}

int consList(list l, item val){
    struct node * new;
    new=malloc(sizeof(struct node));
    if(!new){
        printf("Allocazione fallita!\n");
        return 0;
    }

    new->value=val;
    new->next=l->first;
    l->first=new;
    (l->size)++;
    return 1;
}

int tailList(list l){
    if (emptyList(l)){
        printf("Lista Vuota!\n");
        return 0;
    }

    l->first=l->first->next;
    (l->size)--;
    return 1;
}

item getFisrt(list l){
    if(!emptyList(l)){
        return l->first->value;
    }
    else{
        return NULLITEM;
    }
}

item getItem(list l, int pos){
    if (!l || pos<0 || pos>=sizeList(l)){
        return NULLITEM;
    }

    list tmp =  newList();
    tmp->first = l->first;
    tmp->size = l->size;

    for (int i=0; i!=pos; i++){
        tailList(tmp);
    }

    item val=getFisrt(tmp);
    free(tmp);
    return val;
}

int insertList(list l, int pos, item val){
    if(pos<0 || pos>(l->size)){
        printf("Posizione non valida\n");
        return 0;
    }

    if(pos==0){
        return consList(l, val);
    }

    struct node * new;
    new=malloc(sizeof(*new));
    if(!new){
        printf("Allocazione Fallita!\n");
        return 0;
    }
    new->value=val;

    struct node *prec;
    prec=l->first;
    for(int i=0; i<pos-1; i++){
        prec=prec->next;
    }
    new->next=prec->next;
    prec->next=new;
    (l->size)++;
    return 1;
}

int removeList(list l, int pos){
    if(pos<0 || pos>(l->size)){
        printf("Posizione non valida\n");
        return 0;
    }

    struct node * tmp;
    if(pos==0){
        tmp=l->first;
        tailList(l);
    }

}

int outputList(list l){
    if(!l || emptyList(l)){
        return 0;
    }

    int n = sizeList(l);
    for(int i=0; i<n; i++){
        outputItem(getItem(l,i));
    }
    return 1;
}