#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "punto.h"

struct pto
{
    float x;
    float y;
};


punto creaPunto (float x, float y){
    //crea e alloca dinamicamento un nuovo punto
    punto p=calloc(1,sizeof(*p));
    //assegna x e y rispettivamente ai campi .x e .y 
    p->x=x; 
    p->y=y;
    //restituisce p (il passaggio avviene per valore)
    return p;
}

float ascissa (punto p){
    //restituisce il valore del campo p.x
    return p->x;
}

float ordinata (punto p){
    //restituisce il valore del campo p.y
    return p->y;
}

float distanza (punto p1, punto p2){
    float dx, dy, d;
    //calcola distanza ascissa e ordinata
    dx=p1->x-p2->x;
    dy=p1->y-p2->y;
    //calcola e restituisce distanza punti
    d=sqrt((dx*dx)+(dy*dy));
    return d;
}

void stampa (punto p){
    printf("X = %f\nY = %f\n", p->x, p->y);
}