#include <stdio.h>
#include <stdlib.h>
#include "item.h"


int eq(item x, item y){
    if(x == y){
        return 1;
    }
    else{
        return 0;
    }
}


item inputItem(void){
    item new;
    printf("inserisci carattere: ");
    scanf("%c", &new);
    return new;
}

void outputItem(item x){
    printf("carattere: %c", x);
}

