#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "btree.h"

struct node{
    item value;
    struct node *left;
    struct node *right;
};

btree newBtree(void){
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

    new->value = val;
    new->left = sx;
    new->right = dx;
    return new;
}

item getItem(btree T){
    if (!T){
        return NULLITEM;
    }
    else{
        return T->value;
    }
}

void updateSX(btree T, btree SX){
    T->left = SX;
}

void updateDX(btree T, btree DX){
    T->right = DX;
}