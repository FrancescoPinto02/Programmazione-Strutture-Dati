#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct c_item{
    int key;
    int val;
};

int get_key(item x){
    return x->key;
}

int get_val(item x){
    return x->val;
}

item newItem(int key, int val){
    item new = malloc(sizeof(struct c_item));
    if(!new){
        printf("allocazione fallita!\n");
        return NULL;
    }

    new->key = key;
    new->val = val;
    return new;
}

int eq(item x, item y){
    if(x->key == y->key){
        return 1;
    }
    else{
        return 0;
    }
}

int maggiore(item x, item y){
    if(x->key > y->key){
        return 1;
    }
    else{
        return 0;
    }
}

int minore(item x, item y){
    if(x->key < y->key){
        return 1;
    }
    else{
        return 0;
    }
}

item inputItem(void){
    int key, val;
    printf("Inserisci la key: ");
    scanf("%d", &key);
    printf("Inserisci il valore: ");
    scanf("%d", &val);
    return newItem(key, val);
}

void outputItem(item x){
    if(x != NULL){
        printf("Key: %d  Valore: %d\n", x->key, x->val);
    }
}

