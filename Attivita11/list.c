#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"


static struct node *removeNode(struct node *l, int pos);

static struct node *insertNode(struct node *l, int pos, item val);

static int sizeRec(struct node *first);

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

item getFisrt(list l){
    if(!emptyList(l)){
        return l->first->value;
    }
    else{
        return NULLITEM;
    }
}

item getItem(list l, int pos){
    if(!l || l->size==0){
        return newItem(NULLITEM);
    }

    if(pos<0 || pos>=sizeList(l)){
        return newItem(NULLITEM);
    }

    struct node *tmp = l->first;
    int i=0;
    while(i<pos && tmp!=NULL){
        tmp = tmp->next;
        i++;
    }
    return tmp->value;
}

int posItem(list l, item val){
    if(!l || emptyList(l)){
        return -1;
    }

    int i=0, found=0, pos=0;
    int n=sizeList(l);
    while(i<n && !found){
        if(eq(getItem(l, i) , val)){
            pos=i;
            found=1;
        }
    }

    if(!found){
        return -1;
    }
    else{
        return pos;
    }
}

int insertList(list l, int pos, item val){
    struct node* tmp;
    tmp = insertNode(l->first, pos, val);
    if(tmp==NULL){
        return 0;
    }
    else{
        l->first = tmp;        
        l->size++;
        return 1;                  
    }
}

static struct node *insertNode(struct node *l, int pos, item val){
    struct node *new;
    new=malloc(sizeof(*new));
    if(!new){
        return NULL;
    }
    new->value=val;
    
    if(pos==0){
        new->next=l;
        return new;
    }

    int i=0;
    struct node *prec = l;
    while(i<pos-1 && prec!=NULL){
        prec=prec->next;
    }

    if(prec==NULL){
        free(new);
        return NULL;
    }

    new->next=prec->next;
    prec->next=new;
    return l;
}

int removeList(list l, int pos){
    if (!l || l->first==NULL || l->size==0){
        return 0;
    }

    l->first = removeNode(l->first, pos);
    (l->size)--;
    return 1;
}

static struct node *removeNode(struct node *l, int pos){
    struct node *tmp;

    if(pos==0 && l!=NULL){
        tmp=l;
        l=l->next;
        free(tmp);
    }
    else{
        int i=0;
        struct node *prec = l;
        while(i<pos-1 && prec!=NULL){
            prec=prec->next;
            i++;
        }
        tmp=prec->next;
        prec->next=tmp->next;
        free(tmp);
    }
    return l;
}

int outputList(list l){
    if(!l || emptyList(l)){
        return 0;
    }

    struct node *tmp = l->first;
    while(tmp != NULL){
        outputItem(tmp->value);
        tmp = tmp->next;
    }
}

list cloneList(list l){
    if(!l){
        return NULL;
    }
    
    list clone = newList();
    int n = sizeList(l);
    item val;
    
    for(int i=0; i<n; i++){
        val = getItem(l, i);
        insertList(clone, i, val);
    }

    return clone;
}


//-----------------------------------------------------------------------------------


//SIZELIST ITERATIVA
int sizeListIt(list l){
    if(!l){
        return -1;
    }

    struct node *tmp = l->first;
    int size = 0;

    while(tmp!=NULL){
        size++;
        tmp=tmp->next;
    }
    
    return size;
}

//SIZELIST RICORSIVA

int sizeListRec(list l){
    return sizeRec(l->first);
}

static int sizeRec(struct node *first){
    if(first==NULL){
        return 0;
    }
    else{
        return 1 + sizeRec(first->next);
    }
}