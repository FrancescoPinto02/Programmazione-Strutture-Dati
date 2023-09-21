#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "item.h"

struct c_item{
    int ID;
    int burst;
};

int eq(item a, item b){
    if(a->ID == b->ID){
        return 1;
    }
    else{
        return 0;
    }
}

float getID(item a){
    return a->ID;
}

float getBurst(item a){
    return a->burst;
}

void cicloClock(item a){
    if(a->burst > 0){
        (a->burst)--;
    }
}

item newItem(int id, int burst){
    item new = malloc(sizeof(*new));
    if(!new){
        printf("Allocazione fallita!\n");
        return NULLITEM;
    }

    new->ID=id;
    new->burst=burst;
    return new;
}

item inputItem(void){
    item new = malloc(sizeof(*new));
    if(!new){
        printf("Allocazione fallita!\n");
        return NULLITEM;
    }

    printf("Inserire ID: ");
    scanf("%d", &new->ID);
    printf("Inserisci CPU-Burst: ");
    scanf("%d", &new->burst);

    return new;
}

void outputItem(item a){
    printf("ID: %d  CPU-Burst: %d", a->ID, a->burst);
}
