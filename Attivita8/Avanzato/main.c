#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "queue.h"

void excute(queue q, int maxC);


int main(int argc, char argv[]){
    int num=0;
    time_t t1;
    srand((unsigned) time (&t1));
    
    
    printf("Inserisci numero dei processi: ");
    scanf("%d", &num);


    queue processi = newQueue();
    item proc;
    for(int id=1; id<=num; id++){
        proc=newItem(id, rand()%20);
        enQueue(processi, proc);
    }

    int n;
    printf("Inserisci il numero massimo di cicli per processo: ");
    scanf("%d", &n);

    excute(processi, n);
    return 0;
}

void excute(queue q, int maxC){
    item proc;
    int i=0;
    
    while(!emptyQueue(q)){
        printf("START: ");
        proc=deQueue(q);
        outputItem(proc);
        printf("\n");

        while(i!=4 && getBurst(proc)!=0){
            cicloClock(proc);
            i++;
        }
        i=0;

        if(getBurst(proc)>0){
            enQueue(q, proc);
        }

        printf("END: ");
        outputItem(proc);
        printf("\n\n\n");
    }
}