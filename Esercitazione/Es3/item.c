#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct c_item{
    int ID;
    int votanti;
    int vot_effettivi;
    int nulli;
    int si;
    int no;
};

int get_ID(item x){
    return x->ID;
}

int get_votanti(item x){
    return x->votanti;
}

int get_vot_effettivi(item x){
    return x->vot_effettivi;
}

int get_nulli(item x){
    return x->nulli;
}

int get_si(item x){
    return x->si;
}

int get_no(item x){
    return x->no;
}

int eq(item x, item y){
    if(x->ID == y->ID){
        return 1;
    }
    else{
        return 0;
    }
}

item inputItem(void){
    item new;
    new = malloc(sizeof(*new));
    if(!new){
        printf("Allocazione Fallita!\n");
        return NULLITEM;
    }

    printf("ID: ");
    scanf("%d", &new->ID);
    printf("aventi diritto al voto: ");
    scanf("%d", &new->votanti);
    printf("votanti effettivi: ");
    scanf("%d", &new->vot_effettivi);
    printf("Nulli: ");
    scanf("%d", &new->nulli);
    printf("Si: ");
    scanf("%d", &new->si);
    printf("No: ");
    scanf("%d", &new->no);

    return new;
}

void outputItem(item x){
    if(x!=NULLITEM){
        printf("ID: %d\n", x->ID);
        printf("aventi diritto al voto: %d\n", x->votanti);
        printf("Votanti effettivi: %d\n", x->vot_effettivi);
        printf("Nulli: %d\n", x->nulli);
        printf("Si: %d\n", x->si);
        printf("No: %d\n", x->no);
    }
}

