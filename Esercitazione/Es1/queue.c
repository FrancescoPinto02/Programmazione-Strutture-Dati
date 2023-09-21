#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"

struct node{
    item value;
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

int enQueue(queue q, item val){
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

item deQueue(queue q){
    if(!q){
        return NULLITEM;
    }

    if(emptyQueue(q)){
        return NULLITEM;
    }

    item result = q->head->value;
    struct node *tmp=q->head;
    q->head = q->head->next;
    free(tmp);

    if(q->head == NULL){
        q->tail = NULL;
    }

    (q->numel)--;
    return result;
}

/* PROGETTAZIONE cancFinoItem

    ricevi una coda q, un item el come parametri

    Se q non esiste OR el non esiste OR el==NULLITEM{
        restituisci 0 (operazione fallita)
    }

    Crea una coda temporanea (tmp)
    Crea una variabile di appoggio item (val)
    Finchè q non è vuota{
        togli l`item in testa a q e assegnalo a val (deQueue)
        Se val==el{
            Inserisci val in tmp (enQueue)
            Finche q non è vuota{
                rimuovi l`item in testa a q e assegnalo a val (deQueue)
                inserisci val in tmp (enQueue)
            }
        }
    }

    Finchè tmp non è vuota{
        rimuovi l`item in testa a tmp e assegnalo a val (deQueue)
        inserisci val di nuovo in q (enQueue)
    }

    resituisci 1 (operazione andata a buon fine)
*/


int cancFinoItem (queue q, item el){
    if(!q || !el || el==NULLITEM){
        return 0;
    }

    queue tmp=newQueue();
    item val;
    while(!emptyQueue(q)){
        val=deQueue(q);
        if(eq(val, el)){
            enQueue(tmp, val);
            while(!emptyQueue(q)){
                val=deQueue(q);
                enQueue(tmp, val);
            }
        }
    }

    while(!emptyQueue(tmp)){
        val=deQueue(tmp);
        enQueue(q, val);
    }
    free(tmp);
    return 1;
}

/* PROGETTAZIONE fondiDaItem

    ricevi una coda Q1, una coda Q2, un item el come parametri

    Se Q1 non esiste OR Q2 non esiste OR el non esiste OR el==NULLITEM{
        restituisci NULL
    }

    Crea una nuova coda (newQ)
    Crea una copia di Q1 (C1)
    Crea una copia di Q2 (C2)
    
    Elimina tutti gli item che precedono el in C1 (cancFinoItem)
    Elimina tutti gli item che precedono el in C2 (cancFinoItem)
    
    Se C1 non è vuota AND C2 non è vuota{
        elimina l`elemento in testa a C1
        elimina l`elemento in testa a C2
    }
    
    Se C1 è vuota OR C2 è vuota{
        restituisci newQ
    }

    Crea una coda temporanea (tmp)
    Crea due variabili item di appoggio (val1, val2)
    Finchè C1 non è vuota{
        elimina l`elemento in testa a C1 ed assegnalo a val1
        
        Finchè C2 non è vuota{
            elimina l`elemento in testa a C2 ed assegnalo a val2
            se val1 == val2{
                inserisci val1 in newQ
            }
            Inserisci val2 in tmp
        }

        Finchè tmp non è vuota{
            elimina l`elemento in testa a tmp ed inseriscilo di nuovo in C2
        }
    }

    libera C1
    libera C2
    restituisci newQ
*/


queue fondiDaItem (queue Q1, queue Q2, item el){
    if(!Q1 || !Q2 || !el || el==NULLITEM){
        return NULL;
    }

    queue newQ=newQueue();
    queue C1=copyQueue(Q1);
    queue C2=copyQueue(Q2);
    cancFinoItem(C1, el);
    cancFinoItem(C2, el);

    if(!emptyQueue(C1) && !emptyQueue(C2)){
        deQueue(C1);
        deQueue(C2);
    }

    if(emptyQueue(C1) || emptyQueue(C2)){
        return newQ;
    }

    queue tmp = newQueue();
    item val1, val2;
    while(!emptyQueue(C1)){
        val1=deQueue(C1);
        while(!emptyQueue(C2)){
            val2=deQueue(C2);
            
            if(eq(val1, val2)){
                enQueue(newQ, val2);
                while(!emptyQueue(C2)){
                    enQueue(tmp, deQueue(C2));
                }
            }
            else{
                enQueue(tmp, val2);
            }
        }

        while(!emptyQueue(tmp)){
            enQueue(C2, deQueue(tmp));
        }
    }

    free(tmp);
    free(C1);
    free(C2);
    return newQ;
}

static queue copyQueue(queue q){
    if(!q){
        return NULL;
    }

    queue copy = newQueue();
    queue tmp = newQueue();
    item val;
    while(!emptyQueue(q)){
        val=deQueue(q);
        enQueue(copy, val);
        enQueue(tmp, val);
    }

    while(!emptyQueue(tmp)){
        val=deQueue(tmp);
        enQueue(q, val);
    }

    return copy;
}