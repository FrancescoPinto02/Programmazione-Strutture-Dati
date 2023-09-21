#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "btree.h"

struct node{
    item value;
    struct node *left;
    struct node *right;
};

static void setItem(struct node *N, item val);

btree newBetree(void){
    return NULL;
}

int emptyBtree(btree T){
    if(T == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

btree getRoot(btree T){
    return T;
}

btree figlioSX(btree T){
    if(!T){
        return NULL;
    }
    else{
        return T->left;
    }
}

btree figlioDX(btree T){
    if(!T){
        return NULL;
    }
    else{
        return T->right;
    }
}

btree consBtree(item val, btree sx, btree dx){
    struct node * new = malloc(sizeof(struct node));
    if(!new){
        printf("Allocazione fallita\n");
        return NULL;
    }

    setItem(new, val);
    new->left = sx;
    new->right = dx;
    return new;
}

static void setItem(struct node *N, item val){
    if(N != NULL){
        N->value = val;
    }
}

item getItem(btree T){
    if (!T){
        return NULLITEM;
    }
    else{
        return T->value;
    }
}