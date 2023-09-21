#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "btree.h"
#include "queue.h"

struct node{
    btree value;
    struct node *next;
};

struct c_queue{
    struct node *head;
    struct node *tail;
    int numel;
};

queue newQueue(void){
    queue new;
    new=malloc(sizeof(*new));
    if(!new){
        printf("Allocazione Fallita!\n");
        return NULL;
    }

    new->head=NULL;
    new->tail=NULL;
    new->numel=0;
    return new;
}

int emptyQueue(queue q){
    if(!q){
        return -1;
    }

    if(q->numel==0){
        return 1;
    }
    else{
        return 0;
    }
}

int enQueue(queue q, btree val){
    if (!q){
        return -1;
    }
    
    struct node *new=malloc(sizeof(struct node));
    if(!new){
        printf("Allocazione fallita!\n");
        return 0;
    }

    new->value=val;
    new->next=NULL;

    if(emptyQueue(q)){
        q->head=new;
    }
    else{
        q->tail->next=new;
    }
    q->tail=new;
    (q->numel)++;
    return 1;
}

btree deQueue(queue q){
    if(!q){
        return newBtree();
    }

    if(emptyQueue(q)){
        return newBtree();
    }

    btree result = q->head->value;
    struct node *tmp=q->head;
    q->head = q->head->next;
    free(tmp);

    if(q->head == NULL){
        q->tail = NULL;
    }

    (q->numel)--;
    return result;
}