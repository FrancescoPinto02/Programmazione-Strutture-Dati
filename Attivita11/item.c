#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "item.h"

struct c_item{
    int num;
};


int get_num(item x){
    return x->num;
}

int is_min(item x, item y){
    if(x->num < y->num){
        return 1;
    }
    else{
        return 0;
    }
}

int eq(item x, item y){
    if(x->num == y->num){
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

    new->num = n;
    return new;
}
item inputItem(void){
    int n=0;
    printf("Inserisci un intero: ");
    scanf("%d", &n);
    return newItem(n);
}

void outputItem(item x){
    printf("%d\n", x->num);
}

