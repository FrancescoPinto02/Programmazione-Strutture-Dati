#include <stdio.h>
#include "item.h"


int eq(item a, item b) {
    if (a==b){
        return 1;
    }
    else{
        return 0;
    }
}

void input_item(item *x) {
    printf("inserisci valore intero: ");
    scanf("%d", x);
} 

void output_item(item x) {
    printf("Valore item: %d\n", x);
}
