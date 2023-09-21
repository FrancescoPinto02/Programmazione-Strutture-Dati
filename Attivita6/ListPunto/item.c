#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "item.h"

struct puntoitem{
    float x;
    float y;
};

int eq(item a, item b){
    if (a->x == b->x  && a->y==b->y){
        return 1;
    }
    return 0;
}

item creaItem(float x, float y){
    item p=malloc(sizeof(*p));
    if (!p){
        printf("Allocazione fallita!\n");
        return NULLITEM;
    }
    p->x=x;
    p->y=y;
    return p;
}

item input_item(){
    float x, y;
    printf("Inserisci ascissa: ");
    scanf("%f", &x);
    printf("Inserisci ordinata: ");
    scanf("%f", &y);
    return creaItem(x, y);
}

float distanza(item p1, item p2){
    float dx, dy;
    dx=p1->x-p2->x;
    dy=p1->y-p2->y;
    return sqrt((dx*dx)+(dy*dy));
}   

void output_item(item it){
    printf("X=%f  Y=%f  ", it->x, it->y);
}

float get_x(item it){
    return it->x;
}

float get_y(item it){
    return it->y;
}
