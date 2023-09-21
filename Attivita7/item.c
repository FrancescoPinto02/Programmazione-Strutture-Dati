#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct c_item{
    int data;
};

int get_data(item x){
    return x->data;
}

int eq(item x, item y){
    if(x->data == y->data){
        return 1;
    }
    else{
        return 0;
    }
}

item inputItem(void){
    item new=malloc(sizeof(*new));
    if(!new){
        printf("allocazione fallita!\n");
        return NULL;
    }

    printf("Inserisci valore intero: ");
    scanf("%d", &new->data);
    return new;
}

void outputItem(item x){
    printf("%d", x->data);
}

