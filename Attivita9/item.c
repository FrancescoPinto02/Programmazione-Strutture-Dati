#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct c_item{
    int numero;
};

int eq(item x, item y){
    if(x->numero == y->numero){
        return 1;
    }
    else{
        return 0;
    }
}

item newItem(int n){
    item new = malloc(sizeof(*new));
    if(!new){
        return NULLITEM;
    }

    new->numero = n;
    return new;
}

item inputItem(void){
    int num;
    printf("inserisci numero: ");
    scanf("%d", &num);
    return newItem(num);
}

void outputItem(item x){
    printf("numero: %d", x->numero);
}

