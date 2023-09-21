#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "item.h"

struct c_item{
    float x;
    float y;
};

int eq(item a, item b){
    if((a->x == b->x) && (a->y == b->y)){
        return 1;
    }
    else{
        return 0;
    }
}

float getX(item a){
    return a->x;
}

float getY(item a){
    return a->y;
}

item inputItem(void){
    item new = malloc(sizeof(*new));
    if(!new){
        printf("Allocazione fallita!\n");
        return NULLITEM;
    }

    printf("Inserire ascissa: ");
    scanf("%f", &new->x);
    printf("Inserisci ordinata: ");
    scanf("%f", &new->y);

    return new;
}

void outputItem(item a){
    printf("X: %f  Y: %f", a->x, a->y);
}

float distance (item a, item b){
    float dx, dy;
    dx=a->x-b->x;
    dy=a->y-b->y;
    return sqrt((dx*dx)+(dy*dy));
}